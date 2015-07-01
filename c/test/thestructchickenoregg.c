// Creating a struct with a pointer to it own type.
struct node {
	int data;
	struct node *next;
};

int main() {
	struct node a, b;
	a.data = 1;
	a.next = &b;
}
