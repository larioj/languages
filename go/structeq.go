package main

import "fmt"

type foo struct {
	str string
	val int
}

func main() {
	foo1 := foo{"hello", 2}
	foo2 := foo{"hello", 4}
	fmt.Println(foo1 == foo2)
}
