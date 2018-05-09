import numpy as np
import matplotlib.pyplot as plt
import csv

def graph(data_file_name):
    with open(data_file_name, newline='') as data_file:
        csv_reader = csv.reader(data_file)
        data = [float(x) for x in next(csv_reader)] #only looking at the first row for now

        """label = [data_file_name.rsplit('.', 1)[0]]*2
        plt.bar(0, data[0])
        plt.bar(1, data[1])
        plt.xticks([0,1], label)
        plt.title('Test')
        plt.ylim(ymin=0)
        plt.show()"""

        objects = ('test small', 'test large')
        y_pos = np.arange(len(objects))
        performance = data

        plt.bar(y_pos, performance, align='center', alpha=0.5)
        plt.xticks(y_pos, objects)
        plt.ylabel('Usage')
        plt.title('Programming language usage')

        plt.show()

if __name__ == "__main__":
    graph('test.csv')
