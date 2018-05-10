#! /usr/bin/env python3

import argparse
import json
import time

def load_json(jFile, iterations):
    with open(jFile) as fin:
        string = fin.read()
    start = time.time()
    for i in range(iterations):
        data = json.loads(string)
    end = time.time()
    return (end-start)/iterations

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('small', type=str)
    parser.add_argument('big', type=str)
    args = parser.parse_args()

    big_duration = load_json(args.big, 100)
    small_duration = load_json(args.small, 100)
    print(f'py-native-json,{small_duration},{big_duration}')
