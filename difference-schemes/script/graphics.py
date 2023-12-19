import csv
import matplotlib.pyplot as plt
import sys

def plot_csv(file_path, save_path=None):
    x = []
    u = []
    u1 = []

    with open(file_path, 'r') as csvfile:
        csvreader = csv.reader(csvfile)
        next(csvreader)
        for row in csvreader:
            x.append(float(row[0]))
            u.append(float(row[1]))
            u1.append(float(row[2]))

    plt.figure()
    plt.scatter(x, u, label='Приближенное решение', marker='o', color='red')
    plt.plot(x, u1, label='Точное решение', color='blue')
    plt.title(f'График {file_path[:-4].replace("_", " ")}')
    plt.xlabel('Ось X')
    plt.ylabel('Ось U')
    plt.legend()
    plt.grid(True)

    if save_path:
        plt.savefig(save_path)
        print(f'График сохранен в файл: {save_path}')
    else:
        plt.show()

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python script.py file1.csv file2.csv file3.csv file4.csv")
        sys.exit(1)

    file_paths = sys.argv[1:]

    for file_path in file_paths:
        save_path = file_path.replace('.csv', '.png')
        plot_csv(file_path, 'docs/' + save_path)
