package main

import "fmt"

func main() {
	m := make(map[int][]int)
	m[1] = append(m[1], 1)
	m[1] = append(m[1], 2)
	fmt.Println(m)
}
