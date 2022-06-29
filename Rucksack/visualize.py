import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


if __name__ == "__main__":
    data = pd.read_csv('greedy.csv')
    
    """
    plt.plot(data['size'], data['time'], '-g', label="Messwerte")
    plt.plot([i for i in range(0, 65000, 100)], [(i*i) / 850000 for i in range(0, 65000, 100)], '-r', label="Vergleichsfunktion")
    plt.grid(True)
    plt.xlabel("Anzahl Elemente")
    plt.ylabel("Zeit gebraucht")
    plt.legend()
    plt.show()
    """
    data = pd.read_csv('backtracking.csv')

    plt.plot(data['size'], data['time'], '-g', label="Messwerte")
    plt.plot([i for i in range(0, 30, 1)], [(i**2) / 1000 for i in range(0, 30, 1)], '-r', label="Vergleichsfunktion")
    plt.grid(True)
    plt.xlabel("Anzahl Elemente")
    plt.ylabel("Zeit gebraucht")
    plt.legend()
    plt.show()
