package main

import "fmt"

func main() {
	var mm map[int]map[int]int
	m := mm[0]
	m[1] = 2
	fmt.Println(m[1])
	//panic nil map
}
