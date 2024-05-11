#!/usr/bin/python3

import sys

def is_states(state):
    states = {
    "Oregon" : "OR",
    "Alabama" : "AL",
    "New Jersey": "NJ",
    "Colorado" : "CO"
    }
    for i in states.keys():
        if i.lower() == state.lower():
            return True
    return False

def is_capital(capital):
    capital_cities = {
    "OR": "Salem",
    "AL": "Montgomery",
    "NJ": "Trenton",
    "CO": "Denver"
    }
    for i in capital_cities.values():
        if i.lower() == capital.lower():
            return True
    return False

def all_in():
    arg = sys.argv
    if len(arg) == 2:
        states = {
        "Oregon" : "OR",
        "Alabama" : "AL",
        "New Jersey": "NJ",
        "Colorado" : "CO"
        }
        capital_cities = {
        "OR": "Salem",
        "AL": "Montgomery",
        "NJ": "Trenton",
        "CO": "Denver"
        }
        flist = arg[1].split(',')
        data = []
        for i in range(0, len(flist)):
            if flist[i][0] != ' ' or len(flist[i]) != 1:
                data.append(flist[i].lstrip())
        for i in data:
            if is_states(i):
                for j in states.keys():
                    if j.lower() == i.lower():
                        for k in capital_cities.keys():
                            if states.get(j) == k:
                                print(capital_cities.get(k), "is the capital of", j)
            elif is_capital(i):
                for j in capital_cities.keys():
                    if capital_cities.get(j).lower() == i.lower():
                        for k in states.keys():
                            if j == states.get(k):
                                print(capital_cities.get(j), "is the capital of", k)
            else:
                print(i, "is neither a capital city nor a state")
    
if __name__ == '__main__':
    all_in()