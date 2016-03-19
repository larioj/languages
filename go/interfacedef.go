package main

import "fmt"

type bar struct {
	a int
	b interface{}
	c int
}

type bar2 struct {
	a int
	b int
}

func main() {
	var foo interface{}
	fmt.Println(foo)
	foo = bar{}
	fmt.Println(foo)
	baz := bar{}
	if baz.b == nil {
		fmt.Println("It's nil!")
	}
	baz.b = bar2{}
	fmt.Println(baz)
}
