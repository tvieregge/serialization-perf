import numpy as np
import matplotlib.pyplot as plt
import csv

def graph(data_fn):
    with open(data_fn, newline='') as data_file:
        csv_reader = csv.reader(data_file)

        data = [list(map(float, x)) for x in csv_reader]
        means = list(map(lambda x: sum(x)/len(x), data))

        # data for plots
        means_small = means[0]
        means_large = means[1]

        objects = [data_fn.rsplit('.', 1)[0]] # get rid of extension
        y_pos = [x for x in range(len(objects))] # len(small) == len(large)

        # plot small data set
        plt.subplot(2, 1, 1)
        plt.bar(y_pos, means_small, align='center', alpha=0.5)
        plt.xticks(y_pos, objects)
        plt.ylabel('Time (Seconds)')
        plt.title('Small (~1KB)')
        plt.plot()

        # plot large data set
        plt.subplot(2, 1, 2)
        plt.bar(y_pos, means_large, align='center', alpha=0.5)
        plt.xticks(y_pos, objects)
        plt.ylabel('Time (Seconds)')
        plt.title('Large (~10MB)')
        plt.plot()
        plt.show()

if __name__ == "__main__":
    graph('test.csv')
