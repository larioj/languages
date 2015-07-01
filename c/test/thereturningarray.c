struct array {
	int a[100];
};

struct array foo() {
	struct array a;
	return a;
}

int main() {
	struct array b;
	b = foo();
}
