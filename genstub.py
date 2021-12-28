#!/bin/env python
from sys import argv
import os
import re

ext_table = {"py": "python", "cc": "c++", "rs": "rust"}
regex = re.compile(r"\d+")

if __name__ == "__main__":
    ext = argv[1]
    with open(
        os.path.join(os.path.dirname(__file__), f"templates/template.{ext}")
    ) as f_template:
        with open(f"solution_{ext_table[ext]}.{ext}", "w") as f:
            if len(argv) < 3:
                prob_no = re.search(regex, os.getcwd())[0]  # type: ignore
            else:
                prob_no = int(argv[2])
            f.write(f_template.read().format(prob_no=prob_no))
