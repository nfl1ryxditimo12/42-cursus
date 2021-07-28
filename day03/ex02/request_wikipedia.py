#!/usr/bin/python3

import sys
import requests
import json
import dewiki

def wiki(page: str):
    url = "https://en.wikipedia.org/w/api.php"
    param = {
        'action': 'parse',
        'page': page,
        'prop': 'wikitext',
        'format': 'json',
        'redirects': 'true'
    }

    try:
        res = requests.get(url=url, params=param)
        res.raise_for_status()
    except requests.HTTPError as e:
        raise e
    try:
        data = json.loads(res.text)
    except json.decoder.JSONDecodeError as e:
        raise e
    if data.get("error") is not None:
        raise Exception(data["error"]["info"])
    return (dewiki.from_string(data["parse"]["wikitext"]["*"]))

def go():
    if len(sys.argv) == 2:
        try:
            data = wiki(sys.argv[1])
        except Exception as e:
            return print(e)
        try:
            with open('{}.wiki'.format(sys.argv[1]), 'w') as file:
                file.write(data)
        except Exception as e:
            return print(e)
    else:
        print('Usage : python request_wiki "Keyword"')
    

if __name__ == '__main__':
    go()