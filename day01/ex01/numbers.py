r = open('numbers.txt', 'r')
data = r.read()

for i in data:
    if i == ',':
        print("")
    else:
        print(i, end='')
r.close()