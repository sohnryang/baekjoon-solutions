#!/bin/env python
from sys import argv
from os import path

ext_table = {"py": "python", "cc": "c++", "rs": "rust"}

if __name__ == "__main__":
    ext = argv[1]
    with open(
        path.join(path.dirname(__file__), f"templates/template.{ext}")
    ) as f_template:
        with open(f"solution_{ext_table[ext]}.{ext}", "w") as f:
            f.write(f_template.read().format(prob_no=argv[2]))
