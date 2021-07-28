#!/usr/bin/python3

import sys

def capital_city():
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
        for i in states.keys():
            if arg[1] == i:
                for j in capital_cities.keys():
                    if states.get(i) == j:
                        print(capital_cities.get(j))

if __name__ == '__main__':
    capital_city()