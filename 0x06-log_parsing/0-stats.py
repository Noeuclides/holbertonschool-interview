#!/usr/bin/python3
"""log parsin
"""

import sys

count = 0
total_size = 0
status_code = ['200', '301', '400', '401', '403', '404', '405', '500']
code_count = {}

try:
    for line in sys.stdin:
        array = line.split(' ')
        if len(array) > 2:
            code = array[-2]
            size = array[-1]
            count += 1
            total_size += int(size)
            if code in status_code:
                if code in code_count:
                    code_count[code] += 1
                else:
                    code_count[code] = 1
        if count == 10:
            print("File size: {:d}".format(total_size))
            for k, v in sorted(code_count.items()):
                print("{}: {}".format(k, v))
            count = 0
finally:
    print("File size: {:d}".format(total_size))
    for k, v in sorted(code_count.items()):
        print("{}: {}".format(k, v))
