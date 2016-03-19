package main

import "fmt"

func main() {
	ma := make(map[string]string)
	ma["a"] = "b"
	ma["b"] = "c"
	ma["c"] = "d"

	mb := ma
	fmt.Println(mb["a"], mb["b"], mb["c"])

	ma["a"] = "foo"
	fmt.Println(mb["a"], mb["b"], mb["c"])

	fmt.Println(ma["bar"] == "")
}
