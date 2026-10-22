import time
import numpy as np

def main():
    n = 100_000_000

    indices = np.arange(n, dtype=np.int64)
    a = np.empty(n, dtype=np.int64)
    temp = np.empty(n, dtype=np.int64)

    start = time.perf_counter()

    np.multiply(indices, 31, out=temp)
    np.add(temp, 7, out=temp)
    np.remainder(temp, 1000, out=a)

    elapsed = time.perf_counter() - start

    checksum = np.sum(a, dtype=np.int64)

    print(f"Time: {elapsed:.6f} seconds")
    print(f"Checksum: {checksum}")

if __name__ == "__main__":
    main()
