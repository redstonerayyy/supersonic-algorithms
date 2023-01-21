import os
import pathlib

blacklisted = [
    # ".pdf",
    ".aux",
    ".fdb_latexmk",
    ".fls",
    ".log",
    ".gz",
    ".out",
    ".toc",
    ".bcf",
    ".xml",
    ".bbl",
    ".blg",
    ".xdv",
    ".ps",
    ".dvi"
]

def clean():
    for (root,dirs,files) in os.walk('.', topdown=True):
        for file in files:
            print(file)
            if pathlib.Path(file).suffix in blacklisted:
                os.remove(os.path.join(root, file))

clean()
