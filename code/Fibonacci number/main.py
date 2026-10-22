import time
import sys

sys.setrecursionlimit(1000000000)

cache = [0] * 1000000

def fib(n):
    if n < 2:
        return n
    if cache[n] != 0:
        return cache[n]
    cache[n] = fib(n - 1) + fib(n - 2)
    return cache[n]


def main():
    n = 100000
    start = time.perf_counter()
    result = fib(n)
    end = time.perf_counter()
    elapsed = end - start
    print(f"Fibonacci of {n}, Time: {elapsed} seconds")


if __name__ == "__main__":
    main()