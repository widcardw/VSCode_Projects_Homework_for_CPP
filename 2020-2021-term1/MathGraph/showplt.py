import numpy as np
import matplotlib.pyplot as plt
import csv

x_min, x_max = 20, 90
y_min, y_max = -40, 40

def read_arr():
    arr = np.zeros((0, 1))
    with open("result.csv", "r") as fin:
        csv_reader = csv.reader(fin)
        for row in csv_reader:
            brr = np.array([int(row[2])])
            arr = np.vstack((arr, brr))
    return arr.reshape(x_max - x_min, y_max - y_min).T

def show_plt(arr: np.ndarray):
    plt.figure('Imshow', facecolor='lightgray')
    plt.imshow(arr, cmap="jet", origin="lower")
    plt.colorbar()
    plt.show()

if __name__ == "__main__":
    show_plt(read_arr())
