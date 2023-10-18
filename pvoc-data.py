import serial
# import matplotlib.pyplot as plt
# import datetime as dt
from datetime import datetime
import csv
import time


serial_port = 'COM6'
serial_baudrate = 9600
ard = serial.Serial(serial_port, serial_baudrate)

# 데이터를 저장할 파일 경로 및 이름
f = open("C:/Users/효림/voc/TVOC.control.csv", mode="wt", encoding="cp949", newline="")
writer = csv.writer(f)
writer.writerow(["Time", "TVOC"])
loopCount = 0

# 1초 씩 300번 데이터 찍기
while (loopCount < 300):
    value_TVOC = ard.readline().decode()
    nowtime = datetime.now().strftime('%H:%M:%S')
    print("TVOC: " + value_TVOC)
    writer.writerow([nowtime, value_TVOC])
    time.sleep(1)
    loopCount = loopCount + 1
