package main

import (
	"fmt"
	"math"
	"time"
)

const (
	filePath = "example.txt"
)

func increasingSequence(arr []int, n int) {
	for i := 0; i < n; i++ {
		arr[i] = i
	}
}

func binarySearch(arr []int, n int, target int) int {
	low := 0
	high := n - 1
	for low <= high {
		mid := (low + high) / 2
		if arr[mid] == target {
			return mid
		} else if arr[mid] < target {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	return -1
}

func main() {
	var degree int = 7
	n := int(math.Pow(10, float64(degree)))
	arr := make([]int, n)

	increasingSequence(arr, n)

	target := 0

	start := time.Now()
	result := binarySearch(arr, n, target)
	end := time.Since(start)

	fmt.Printf("First element | Result: %d, Time: %d ns\n", result, end.Nanoseconds())

	target = 5000000

	start = time.Now()
	result = binarySearch(arr, n, target)
	end = time.Since(start)

	fmt.Printf("Middle element | Result: %d, Time: %d ns\n", result, end.Nanoseconds())

	target = 9999999

	start = time.Now()
	result = binarySearch(arr, n, target)
	end = time.Since(start)

	fmt.Printf("Last element | Result: %d, Time: %d ns\n", result, end.Nanoseconds())

	target = -1
	start = time.Now()
	result = binarySearch(arr, n, target)
	end = time.Since(start)

	fmt.Printf("Not found | Result: %d, Time: %d ns\n", result, end.Nanoseconds())
}
