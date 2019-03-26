import sys
import math

import numpy as np 
import matplotlib.pyplot as plt

def parse_data(file):
    print("parsing data")
    theta = []
    r = []
    try:
        with open(file) as f:
            for row in f:
                rad = row.split(' ')
                theta.append(math.radians(float(rad[0])))
                r.append(float(rad[1]))
            return [theta, r]
    except Exception as e:
        print(e)

def plot_values(values):
    ax = plt.subplot(111, projection = 'polar')
    ax.scatter(values[0], values[1])
    ax.set_theta_zero_location("N")
    plt.show()

if __name__ == "__main__":
    if len(sys.argv) == 1:
        FILE = '../lidar/sdk/output/Linux/Release/points.txt'
    else:
        FILE = sys.argv[1]
    values = parse_data(FILE)
    plot_values(values)
