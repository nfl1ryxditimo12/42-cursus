#!/usr/bin/python3

import random

from beverages import HotBeverage, Coffee, Tea, Chocolate, Cappuccino

class CoffeMachine:
    
    class EmptyCup(HotBeverage):
        def __init__(self) -> None:
            self.name = "empty cup"
            self.price = 0.90
        
        def description(self) -> str:
            return "An empty cup?! Gimme my money back!"

    class BrokenMachineException(Exception):
        def __init__(self) -> None:
            super().__init__( "This coffee machine has to be repaired.")

    def __init__(self) -> None:
        self.count = 10

    def repair(self) -> None:
        self.count = 10

    def serve(self, drink: HotBeverage) -> HotBeverage():
        if self.count <= 0:
            raise CoffeMachine.BrokenMachineException
        self.count -= 1
        if random.randint(0, 5) == 0:
            return CoffeMachine.EmptyCup()
        return drink()

def machine():
    coffe = CoffeMachine()
    for _ in range(23):
        try:
            print(coffe.serve(random.choice(
                [Coffee, Tea, Cappuccino, Chocolate])))
        except CoffeMachine.BrokenMachineException as broken:
            print(broken)
            coffe.repair()

if __name__ == '__main__':
    machine()