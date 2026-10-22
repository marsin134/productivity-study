import time
import math

def increasing_sequence(arr, n):
    for i in range(n):
        arr[i] = i


def binary_search(arr, target):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1


def main():
    degree = 7
    n = int(math.pow(10, degree))
    arr = [0] * n

    increasing_sequence(arr, n)

    target = 0
    start = time.perf_counter_ns()
    result = binary_search(arr, target)
    end = time.perf_counter_ns()
    print(f"First element | Result: {result}, Time: {end - start} ns")

    target = 5000000
    start = time.perf_counter_ns()
    result = binary_search(arr, target)
    end = time.perf_counter_ns()
    print(f"Middle element | Result: {result}, Time: {end - start} ns")

    target = 9999999
    start = time.perf_counter_ns()
    result = binary_search(arr, target)
    end = time.perf_counter_ns()
    print(f"Last element | Result: {result}, Time: {end - start} ns")

    target = -1
    start = time.perf_counter_ns()
    result = binary_search(arr, target)
    end = time.perf_counter_ns()
    print(f"Not found | Result: {result}, Time: {end - start} ns")


if __name__ == "__main__":
    main()