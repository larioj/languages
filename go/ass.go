package main

func assert(cond bool) {
	if !cond {
		panic()
	}
}

func main() {
	assert(false)
}
