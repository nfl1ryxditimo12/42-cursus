import sys

def state():
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
        for i in capital_cities.keys():
            if capital_cities.get(i) == arg[1]:
                for j in states.keys():
                    if states.get(j) == i:
                        print(j)

if __name__ == '__main__':
    state()