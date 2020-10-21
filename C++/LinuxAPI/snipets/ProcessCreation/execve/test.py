#!/usr/bin/env python3
import time
import sys


if len(sys.argv) > 1:
    SLEEP_TIME = int(sys.argv[1])
else:
    SLEEP_TIME = int(5)

time.sleep(SLEEP_TIME)
print(f"The process was sleep {SLEEP_TIME} seconds.")
