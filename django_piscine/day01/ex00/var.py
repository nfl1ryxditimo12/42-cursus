#!/usr/bin/python3

def print_type(var):
    print("{0} has a type {1}".format(var, type(var)))

def my_var():
    print_type(42)
    print_type("42")
    print_type("quarante-deux")
    print_type(42.0)
    print_type(True)
    print_type([42])
    print_type({42: 42})
    print_type((42,))
    print_type(set())

if __name__ == '__main__':
    my_var()