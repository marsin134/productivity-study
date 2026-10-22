package main

import (
	"fmt"
	"runtime"
	"sync"
	"time"
)

func main() {
	const n = 100_000_000
	a := make([]int64, n)

	workers := runtime.GOMAXPROCS(0)
	if workers > n {
		workers = n
	}

	var wg sync.WaitGroup
	wg.Add(workers)

	start := time.Now()

	for w := 0; w < workers; w++ {
		lo := n * w / workers
		hi := n * (w + 1) / workers

		go func(lo, hi int) {
			defer wg.Done()

			for i := lo; i < hi; i++ {
				a[i] = (int64(i)*31 + 7) % 1000
			}
		}(lo, hi)
	}

	wg.Wait()
	elapsed := time.Since(start)

	var checksum int64
	for _, v := range a {
		checksum += v
	}

	fmt.Printf("Workers: %d\n", workers)
	fmt.Printf("Time: %v seconds\n", elapsed.Seconds())
	fmt.Printf("Checksum: %d\n", checksum)
}
