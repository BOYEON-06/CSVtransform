import serial
# import matplotlib.pyplot as plt
# import datetime as dt
from datetime import datetime
import csv
import time


serial_port = '/dev/cu.usbserial-A50285BI'
serial_baudrate = 115200
ard = serial.Serial(serial_port, serial_baudrate)

# 데이터를 저장할 파일 경로 및 이름
f = open("/Users/leeboyeon/Desktop/Aboutschool/sciencework/result-data/spraydata-control.csv", mode="wt", encoding="cp949", newline="")
writer = csv.writer(f)
writer.writerow(["Time", "PM2.5", "PM10"])
loopCount = 0

# 1초 씩 3번 데이터 
while (loopCount < 300):
    value_pm25 = ard.readline().decode()
    value_pm10 = ard.readline().decode()
    nowtime = datetime.now().strftime('%H:%M:%S')
    print("pm2.5: " + value_pm25)
    print("pm1 0: " + value_pm10)
    writer.writerow([nowtime, value_pm25, value_pm10])
    time.sleep(1)
    loopCount = loopCount + 1
