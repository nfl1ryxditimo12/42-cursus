#!/usr/bin/python3

def numbers():
    r = open('numbers.txt', 'r')
    data = r.read()

    for i in data:
        if i == ',':
            print("")
        else:
            print(i, end='')
    r.close()

if __name__ == '__main__':
    numbers()