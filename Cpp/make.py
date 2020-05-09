#!/usr/bin/python3
import sys
import subprocess as subp

CC = "g++"
PROG = ""
FLAGS = [
            "-Wall",
            "-Weffc++",
            "-Wextra",
            "-Wsign-conversion",
            "--std=c++17"
        ]
CPPFLAGS = " ".join(FLAGS)
OJBS = []
CPPFILES = []

if __name__ == "__main__":
    fname = sys.argv[1]
    if fname:
        cmd_line = f"{CC} {fname} -o {fname.replace('.cpp','')} {CPPFLAGS}"
        print(cmd_line)
        subp.run(cmd_line, shell=True)
