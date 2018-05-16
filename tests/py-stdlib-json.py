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
    return ((end-start)/iterations, end-start)

def dump_json(jFile, iterations):
    with open(jFile) as fin:
        data = json.load(fin)
    start = time.time()
    for i in range(iterations):
        string = json.dumps(data)
    end = time.time()
    return ((end-start)/iterations, end-start)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('small', type=str)
    parser.add_argument('big', type=str)
    args = parser.parse_args()

    big_duration, total_big_duration = load_json(args.big, 144)
    small_duration, total_small_duration = load_json(args.small, 1607938)
    print(f'py-stdlib-json-deserialize,{small_duration},{total_small_duration},{big_duration},{total_big_duration}')

    big_duration, total_big_duration = dump_json(args.big, 144)
    small_duration, total_small_duration = dump_json(args.small, 1607938)
    print(f'py-stdlib-json-serialize,{small_duration},{total_small_duration},{big_duration},{total_big_duration}')
