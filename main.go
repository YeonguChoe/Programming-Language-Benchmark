/**
 * Production compile command
 * go build -o Go_program main.go
 * ./Go_program
 */

package main

import (
	"fmt"
	"os"
	"strconv"
	"time"
)

func factorial(num uint64) uint64 {
	if num == 0 || num == 1 {
		return 1
	}
	var result uint64 = 1
	for i := uint64(2); i <= num; i++ {
		result *= uint64(i)
	}
	return result
}

func main() {
	var iteration uint64 = 0
	iterationStr := os.Args[1]
	iteration, err := strconv.ParseUint(iterationStr, 10, 64)
	if err != nil {
		fmt.Println("Invalid argument: not a number")
		return
	}
	var factorialInput uint64 = 20
	var finalValue uint64 = (iteration-2) * (iteration-2) * (iteration-2) * (iteration-2)
	var count uint64 = 0

	// Start timer
	start := time.Now()

	for i := uint64(2); i < iteration; i++ {
		for j := uint64(2); j < iteration; j++ {
			for k := uint64(2); k < iteration; k++ {
				for m := uint64(2); m < iteration; m++ {
					_ = factorial(uint64(factorialInput))
					count++
					if count == finalValue {
						fmt.Println("==================================================")
						fmt.Printf("Result count: %d\n", finalValue)
					}
				}
			}
		}
	}

	// End timer
	elapsed := time.Since(start)

	fmt.Printf("Expected count: %d\n", finalValue)
	fmt.Println("==================================================")
	
	fmt.Printf("Go Runtime: %f seconds\n", elapsed.Seconds())
	fmt.Println("==================================================")
}