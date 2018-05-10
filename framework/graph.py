import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import csv

def graph_timing(data_fn):
    """Graph the timing results from a CSV file"""
    df = pd.read_csv(data_fn, index_col=0, names=['Tool', 'small', 'time-small', 'big', 'time-big'])
    ax = plt.subplot(2, 1, 1)
    df['small_us'] = df['small']*1e6
    df.plot(y='small_us', kind='bar', ax=ax)
    ax.set_ylabel('Time (μs)')
    ax.set_title('Time to serialize a small (~1KB) message')

    ax = plt.subplot(2, 1, 2)
    df['big_ms'] = df['big']*1000
    df.plot(y='big_ms', kind='bar', ax=ax)
    ax.set_ylabel('Time (ms)')
    ax.set_title('Time to serialize a large (~10MB) message')

    plt.subplots_adjust(wspace=0.1, hspace=0.4)
    plt.show()

if __name__ == "__main__":
    graph_timing('test.csv')
