#!/usr/bin/python3

import sys
from bs4.element import ResultSet
import requests
from bs4 import BeautifulSoup

def check_dup(history: list):
    for i in range(0, len(history)):
        for j in range(i + 1, len(history)):
            if history[i] == history[j]:
                return False
    return True

def check_elements(elements):
    count = 0
    
    if len(elements) == 0:
        return False
    for elem in elements:
        try:
            if elem['title']:
                count += 1
        except Exception as e:
            continue
    if count == 0:
        return False
    return True

def go():
    if len(sys.argv) == 2:
        count = 0
        link = sys.argv[1].replace(' ', '_')
        history = []

        while link != 'Philosophy':
            try:
                request = requests.get('https://en.wikipedia.org/wiki/{}'.format(link))
                request.raise_for_status()
            except requests.HTTPError as e:
                break
            soup = BeautifulSoup(request.text, 'html.parser')
            history.append(soup.find("h1", {"class": "firstHeading"}).text)
            elements = soup.select('div > p > a')
            if not check_elements(elements):
                break
            link = elements[0]['title']
            count += 1
        
        if count == 0:
            print('Input else keyword !')
        elif link == 'Philosophy':
            for his in history:
                print(his)
            print(link)
            print('{} roads from {} to philosophy !'.format(count + 1, history[0]))
        elif not check_dup(history):
            print('It leads to an infinite loop !')
        else:
            print('It leads to a dead end !')

    else:
        print('Usage : python roads_to_philosophy.py "Keyword"')

if __name__ == '__main__':
    go()