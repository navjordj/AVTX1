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
            for _ in range(3): #Skipper over de 3 første linjene som ikke inneholder verdier
                next(f)
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
    if len(sys.argv) < 2:
        print("Ingen fil oppgitt")
        sys.exit()
    FILE = sys.argv[1]
    values = parse_data(FILE)
    plot_values(values)
