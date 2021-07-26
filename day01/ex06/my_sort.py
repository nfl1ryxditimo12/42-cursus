def my_sort():
    d = {
    'Hendrix' : '1942',
    'Allman' : '1946',
    'King' : '1925',
    'Clapton' : '1945',
    'Johnson' : '1911',
    'Berry' : '1926',
    'Vaughan' : '1954',
    'Cooder' : '1947',
    'Page' : '1944',
    'Richards' : '1943',
    'Hammett' : '1962',
    'Cobain' : '1967',
    'Garcia' : '1942',
    'Beck' : '1944',
    'Santana' : '1947',
    'Ramone' : '1948',
    'White' : '1975',
    'Frusciante': '1970',
    'Thompson' : '1949',
    'Seongsu' : '1939',
    'Burton' : '1939',
    }

    dic = sorted(d.items(), key=lambda x: x[1])
    for i in range(0, len(dic)):
        for j in range(i + 1, len(dic)):
            if dic[i][1] == dic[j][1]:
                if dic[i][0] > dic[j][0]:
                    tmp = dic[i]
                    dic[i] = dic[j]
                    dic[j] = tmp
    dic = dict(dic)

if __name__ == '__main__':
    my_sort()