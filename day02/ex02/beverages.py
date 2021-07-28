#!/usr/bin/python3

class HotBeverage:
    def __init__(self) -> None:
        self.name = "hot beverage"
        self.price = 0.30
    
    def description(self) -> str:
        return "Just some hot water in a cup"

    def __str__(self) -> str:
        TEMP = ('name : {name}\n'
                'price : {price:0.2f}\n'
                'description : {description}')
        return TEMP.format(name=self.name, price=self.price, description=self.description())
        
class Coffee(HotBeverage):
    def __init__(self) -> None:
        self.name = "coffee"
        self.price = 0.40
    
    def description(self) -> str:
        return "A coffee, to stay awake."

class Tea(HotBeverage):
    def __init__(self) -> None:
        self.name = "tea"
        self.price = 0.30

class Chocolate(HotBeverage):
    def __init__(self) -> None:
        self.name = 'chocolate'
        self.price = 0.50
    
    def description(self) -> str:
        return "Chocolate, sweet chocolate..."

class Cappuccino(HotBeverage):
    def __init__(self) -> None:
        self.name = "cappuccino"
        self.price = 0.45
    
    def description(self) -> str:
        return "Un po’ di Italia nella sua tazza!"

def beverage():
    print(HotBeverage())
    print(Coffee())
    print(Tea())
    print(Chocolate())
    print(Cappuccino())

if __name__ == '__main__':
    beverage()