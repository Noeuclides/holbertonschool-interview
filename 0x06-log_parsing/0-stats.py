#!/usr/bin/python3
import sys

sizes = []
try:
    for line in sys.stdin:
        array = line.split(' - ')
        ip = array[0]
        get = array[1].split(' ')
        code = get[-2]
        size = get[-1]
        if len(sizes) == 10:
            print("File size: {}".format(sum(sizes)))
            sorted(sizes)
            for size in sizes:
                print("status code: {}".format(size))
                sizes = []
        else:
            sizes.append(int(size))
except Exception:
    pass
finally:
    print("File size: {:d}".format(sum(sizes)))
    for size in sizes:
        print("status code: {}".format(size))
