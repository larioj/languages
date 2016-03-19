package main

import "fmt"

func main() {
	for i := 0; i < 100; i++ {
		fmt.Println(itoprime(i))
	}
}

func itoprime(n int) int {
	res := 2
	for i := 1; i <= n; {
		res++

		isprime := true
		for j := 2; j < res; j++ {
			if res%j == 0 {
				isprime = false
				break
			}
		}

		if isprime {
			i++
		}
	}
	return res
}
