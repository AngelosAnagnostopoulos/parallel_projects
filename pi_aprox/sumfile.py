import os

line_sum = 0
filepath = os.getcwd() + "/pi_aprox/pi_sums.txt"

with open(filepath, "r") as file:
    lines = file.readlines()
    for line in lines:
        line = line.strip()
        line_sum += float(line)
    median = line_sum / len(lines)
    print(f"\nThe median value for pi is: {median}")