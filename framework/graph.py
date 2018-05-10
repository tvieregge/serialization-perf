import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import csv

def graph_timing(data_fn):
    """Graph the timing results from a CSV file"""
    df = pd.read_csv(data_fn, index_col=0, names=['Tool', 'small', 'big'])
    ax = plt.subplot(2, 1, 1)
    df.plot(y='small', kind='bar', ax=ax)
    ax.set_ylabel('Time (Seconds)')
    ax.set_title('Time to serialize a small (~1KB) message')

    ax = plt.subplot(2, 1, 2)
    df.plot(y='big', kind='bar', ax=ax)
    ax.set_ylabel('Time (Seconds)')
    ax.set_title('Time to serialize a large (~10MB) message')

    plt.subplots_adjust(wspace=0.1, hspace=0.4)
    plt.show()

if __name__ == "__main__":
    graph_timing('test.csv')
