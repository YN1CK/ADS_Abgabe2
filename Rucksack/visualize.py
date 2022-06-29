import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


if __name__ == "__main__":
    data = pd.read_csv('greedy.csv')
    
    plt.plot(data['size'], data['time'], '-g', label="Messwerte")
    
    plt.grid(True)
    plt.xlabel("Anzahl Elemente")
    plt.ylabel("Zeit gebraucht")
    plt.legend()
    plt.show()
    data = pd.read_csv('backtracking.csv')

    plt.plot(data['size'], data['time'], '-g', label="Messwerte")
    
    plt.grid(True)
    plt.xlabel("Anzahl Elemente")
    plt.ylabel("Zeit gebraucht")
    plt.legend()
    plt.show()
