import serial
import subprocess
import time
import winreg

def get_registry_value(key, subkey, value):
    key = getattr(winreg, key)
    handle = winreg.OpenKey(key, subkey )
    (value, type) = winreg.QueryValueEx(handle, value)
    return value

def SetTimeDateWindows(tm):
    ye = tm.split(' ')[0].split('/')[0].strip()
    mo = tm.split(' ')[0].split('/')[1].strip()
    da = tm.split(' ')[0].split('/')[2].strip()
    ho = tm.split(' ')[1].split(':')[0].strip()
    mi = tm.split(' ')[1].split(':')[1].strip()
    se = tm.split(' ')[1].split(':')[2].strip()
    return '%s/%s/%s %s:%s:%s' % (da,mo,ye,ho,mi,se,)

def TimeDateSerialValidation(tm):
    Value = False
    if tm.count('/') == 2 and tm.count(' ') == 1 and tm.count(':') == 2:
        ye = tm.split(' ')[0].split('/')[0].strip()
        if len(ye) == 4:
            if int(ye) > 2000:
                Value = True
    return Value

def run(cmd):
    completed = subprocess.run(["powershell", "-Command", cmd], capture_output=True)
    return completed

if __name__ == '__main__':
    COM = get_registry_value(
            "HKEY_LOCAL_MACHINE",
            "SOFTWARE\\SetTimeWindows",
            "COM_Port")
    print(COM)
    print(f'Connecting with "{COM}"...')
    dev = serial.Serial(COM,9600)
    time.sleep(3)
    values_serial = []

    for x in range(50):
        value_serial = dev.readline().decode('utf-8', 'ignore').strip()
        values_serial.append(value_serial.strip())
    dev.close()  

    for y in values_serial:
        if TimeDateSerialValidation(y):
            command = f'Set-Date -date "{SetTimeDateWindows(y)}"'
            command_info = run(command)
            if command_info.returncode != 0:
                print("An error occured: %s", command_info.stderr)
            else:
                print(f"Command date and time update executed successfully!: {y}")
            break
        print(f'The command has not been executed: {y}')

    