#!/usr/bin/env python3
from sys import argv
import os
import re

ext_table = {
    "py": ("python", []),
    "cc": ("c++", []),
    "rs": ("rust", []),
    "go": ("go", ["go.mod"]),
}
regex = re.compile(r"\d+")

if __name__ == "__main__":
    ext = argv[1]
    language_name, other_filenames = ext_table[ext]
    basedir = os.path.dirname(__file__)
    if len(argv) < 3:
        prob_no = re.findall(regex, os.getcwd())[-1]  # type: ignore
    else:
        prob_no = int(argv[2])
    with open(os.path.join(basedir, f"templates/template.{ext}")) as f_template:
        with open(f"solution_{language_name}.{ext}", "w") as f:
            f.write(f_template.read().format(prob_no=prob_no))
    if other_filenames:
        for filename in other_filenames:
            with open(
                os.path.join(basedir, f"templates/{language_name}_files", filename)
            ) as f_template:
                with open(filename, "w") as f:
                    f.write(f_template.read().format(prob_no=prob_no))
