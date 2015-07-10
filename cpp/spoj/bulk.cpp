#include <vector>
#include <stdio.h>

struct point {
		int x, y, z;
		bool outer;
		point(int x = 0, int y = 0, int z = 0, bool outer = false) {
			printf("In point constructor.\n");
			this->x = x;
			this->y = y;
			this->z = z;
			this->outer = outer;
		}

		~point() {
			printf("%d %d %d %s\n", this->x, this->y, this->z, this->outer ? "true" : "false");
			printf("In point destructor.\n");
		}
};

struct line {
	std::vector<struct point *> points;
	bool outer;

	line(bool outer = false) {
		printf("In line constructor.\n");
		this->outer = outer;
	}

	~line() {
		printf("in line destructor.\n");
	}

	void addpoint(struct point *newpoint) {
		points.push_back(newpoint);
	}

	bool iscomplete() {
		if (points.size() < 2) {
			return false;
		}

	}
};

struct simple_face {
	std::vector<struct line *> line;
	bool outer;
};

struct face {
	std::vector<struct simple_face *> plane;
	bool outer;
};

struct simple_bulk {
	std::vector<struct face *> face;
	bool outer;
};

struct bulk {
	std::vector<struct simple_bulk *> simple_bulk;
};

int main() {
	point p(1, 2, 3);
	return 0;
}
