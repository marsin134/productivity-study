import time

def main():
    n = 100_000_000
    a = [0] * n

    start = time.perf_counter()

    for i in range(n):
        a[i] = (i * 31 + 7) % 1000

    elapsed = time.perf_counter() - start

    checksum = sum(a)

    print(f"Time: {elapsed:.6f} seconds")
    print(f"Checksum: {checksum}")

if __name__ == "__main__":
    main()
