package maptest

import "fmt"

type foo struct {
	a int
	b int
}

func main() {
	m := make(map[int]foo)
	bar := m[0]
	bar.a = 44
	bar.b = 44
	fmt.Println(m[0])
	m[0] = bar
	fmt.Println(m[0])
	baz := m[0]
	baz.b = 66
	fmt.Println(m[0])
}
