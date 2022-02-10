#!/bin/env python
from sys import argv
import os
import re
import shutil

ext_table = {
    "py": ("python", []),
    "cc": ("c++", []),
    "rs": ("rust", []),
    "go": ("go", ["go.mod"]),
}
regex = re.compile(r"\d+")

if __name__ == "__main__":
    ext = argv[1]
    language_name, other_files = ext_table[ext]
    basedir = os.path.dirname(__file__)
    with open(os.path.join(basedir, f"templates/template.{ext}")) as f_template:
        with open(f"solution_{language_name}.{ext}", "w") as f:
            if len(argv) < 3:
                prob_no = re.findall(regex, os.getcwd())[-1]  # type: ignore
            else:
                prob_no = int(argv[2])
            f.write(f_template.read().format(prob_no=prob_no))
    if other_files:
        for file in other_files:
            shutil.copy(
                os.path.join(basedir, f"templates/{language_name}_files", file),
                os.curdir,
            )
