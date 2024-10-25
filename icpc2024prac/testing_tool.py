#!/usr/bin/env python3
#
# Testing tool for the Card Game problem
#
# Usage:
#
#   python3 testing_tool.py -f inputfile <program>
#
#
# Use the -f parameter to specify the input file, e.g. input.in.
# Format of the input file:
# - One line with a single integer:
#   - n, the number of cards
# - One line with n integers:
#   - i-th integer is the value written on the back of card i
#
# E.g.:
# 6
# 0 0 0 1 0 1
#
# If you have a C++ solution stored in a file called "sol.cpp",
# you must first compile using "g++ sol.cpp -o sol" and then
# invoke the testing tool with:
#
#   python3 testing_tool.py -f input.in ./sol
#
# If you have a Python solution that you would run using
# "pypy3 solution.py", you could invoke the testing tool with:
#
#   python3 testing_tool.py -f input.in pypy3 solution.py
#
# If you have a Java solution that you would run using
# "java MyClass", you could invoke the testing tool with:
#
#   python3 testing_tool.py -f input.in java MyClass
#
# The tool is provided as-is, and you should feel free to make
# whatever alterations or augmentations you like to it.
#
# The tool attempts to detect and report common errors, but it is not guaranteed
# that a program that passes the testing tool will be accepted.

import argparse
import subprocess
import traceback


def write(p, line):
    assert p.poll() is None, "Program terminated early"
    print(f"Write: {line}", flush=True)
    p.stdin.write(f"{line}\n")
    p.stdin.flush()


def read(p):
    assert p.poll() is None, "Program terminated early"
    line = p.stdout.readline().strip()
    assert (
        line != ""
    ), "Read empty line or closed output pipe. Make sure that your program started successfully."
    print(f"Read: {line}", flush=True)
    return line


parser = argparse.ArgumentParser(
    description="Testing tool for the Card Game problem"
)
parser.add_argument(
    "-f",
    dest="inputfile",
    metavar="inputfile",
    default=None,
    type=argparse.FileType("r"),
    required=True,
    help="The input file to use.",
)
parser.add_argument("program", nargs="+", help="Invocation of your solution")

args = parser.parse_args()

with args.inputfile as f:
    lines = f.readlines()
    assert len(lines) > 0
    n = int(lines[0].strip())
    cards = list(map(int, lines[1].strip().split()))
num_queries = 0
max_num_queries = n-2
is_neg_one = True
for i in range(1, n):
    if 0 == cards[i-1] and 1 == cards[i]:
        is_neg_one = False
with subprocess.Popen(
    " ".join(args.program),
    shell=True,
    stdout=subprocess.PIPE,
    stdin=subprocess.PIPE,
    universal_newlines=True,
) as p:
    try:
        write(p, str(n))
        while True:
            request_args = list(read(p).split())
            if len(request_args) < 2:
                write(p, "error")
                assert False, "Invalid request."
            request_type = request_args[0]
            if '?' == request_type:
                _, x = request_args
                x = int(x)
                num_queries += 1
                if max_num_queries < num_queries:
                    write(p, "error")
                    assert False, "Too many queries."
                if x < 1 or n < x:
                    write(p, "error")
                    assert False, "Invalid request."
                write(p, str(cards[x-1]))
            elif '!' == request_type:
                _, y = request_args
                y = int(y)
                if 1 <= y <= n-1:
                    if 0 == cards[y-1] and 1 == cards[y]:
                        write(p, "correct")
                        break
                if -1 == y:
                    if is_neg_one:
                        write(p, "correct")
                        break
                write(p, "wrong")
                assert False, "Wrong answer."
            else:
                write(p, "error")
                assert False, "Invalid request."

        assert (
            p.stdout.readline() == ""
        ), "Your submission printed extra data after writing the final output request."
        assert p.wait() == 0, "Your submission did not exit cleanly after finishing."

        print(f"\nSuccess.\n# of queries: {num_queries}\n")

    except AssertionError as e:
        print()
        print(f"Error: {e}")
        print()
        try:
            p.wait(timeout=2)
        except subprocess.TimeoutExpired:
            print("Killing your submission after 2 second timeout.")
            p.kill()

    except Exception as e:
        print()
        traceback.print_exc()
        print()
        try:
            p.wait(timeout=2)
        except subprocess.TimeoutExpired:
            print("Killing your submission after 2 second timeout.")
            p.kill()
        raise e

    finally:
        print(f"Exit code: {p.wait()}\n", flush=True)

