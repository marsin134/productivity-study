package main

import (
	"fmt"
	"time"
)

func main() {
	const n = 100_000_000
	a := make([]int64, n)

	start := time.Now()

	for i := 0; i < n; i++ {
		a[i] = (int64(i)*31 + 7) % 1000
	}

	elapsed := time.Since(start)

	var checksum int64
	for _, v := range a {
		checksum += v
	}

	fmt.Printf("Time: %v seconds\n", elapsed.Seconds())
	fmt.Printf("Checksum: %d\n", checksum)
}
