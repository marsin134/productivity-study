package main

import (
	"fmt"
	"time"
)

var fibCache = [1000000]int64{0}

func fibonacci(n int64) int64 {
	if n < 2 {
		return n
	}
	if fibCache[n] != 0 {
		return fibCache[n]
	}
	fibCache[n] = fibonacci(n-1) + fibonacci(n-2)
	return fibCache[n]
}

func main() {
	n := int64(100000)
	start := time.Now()
	fibonacci(n)
	elapsed := time.Since(start)
	fmt.Printf("Fibonacci of %d, Time: %v seconds\n", n, elapsed.Seconds())
}
