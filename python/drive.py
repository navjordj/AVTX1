from rplidar import RPLidar

import numpy as np 
import sys

lidar = RPLidar('/dev/ttyUSB0')

info = lidar.get_info()
print(info)

health = lidar.get_health()
print(health)

lidar.clear_input()

import serial, time

try:
    arduino = serial.Serial('/dev/ttyACM1', 9600)
except:
    arduino = serial.Serial('/dev/ttyACM0', 9600)

print(arduino)
time.sleep(1)


for i, scan in enumerate(lidar.iter_scans(max_buf_meas=500)):
    if i % 7 == 0:
        angles = np.array([])
        dists = np.array([])
        for measurement in scan:
            angle = measurement[1]
            if (angle > 270 or angle < 90):
                angles = np.append(angles, angle)
                dists = np.append(dists, measurement[2])
        steer = 0

        for j, _ in enumerate(angles):
            angle = angles[j]
            dist = dists[j]
            if angles[j] > 270:
                steer -= (360-angle)*dist/10000
            else:
                steer += angle*dist/10000

        if steer < 0:
            arduino.write(str.encode("0"))
            print("venstre")
            #Sving til venstre
        else:
            arduino.write(str.encode("1"))
            print("hoyre")
            #sving til hoyre
        print(steer)
        time.sleep(0)
