#include "stdio.h"
#include <vector>
#include <algorithm>
#include <list>
#include "err.h"

using namespace std;

class Person {
private:
    int name;
    int fiancee_idx;
    int *preferences;
    int *ratings;
public:
    Person(int name, int *preferences, int n);
    Person(int name, int n);
    ~Person();
    int goodness() { return fiancee_idx; }
    int getName() { return name; }
    int nextFiancee() { return preferences[fiancee_idx + 1]; }
    int currentFiancee() { return -1 == fiancee_idx ? -1 : preferences[fiancee_idx]; }
    void changeFiancee(Person *new_fiancee) { fiancee_idx = ratings[new_fiancee->getName()]; }
    bool isAvailable() { return -1 == fiancee_idx; }
    bool prefers(Person *a, Person *b) { return ratings[a->getName()] < ratings[b->getName()]; }
    void printPreferences(int n);
};

void Person::printPreferences(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", preferences[i]);
    }
    printf("\n");
}

Person::Person(int name, int n) {
    this->name = name;
    fiancee_idx = -1;

    vector<int> pvec;
    for (int i = 0; i < n; i++) pvec.push_back(i);
    random_shuffle(pvec.begin(), pvec.end());

    preferences = new int [n];
    ratings = new int [n];
    for (int i = 0; i < n; i++) {
        preferences[i] = pvec[i];
        ratings[preferences[i]] = i;
    }
}

Person::Person(int name, int *preferences, int n) {
    this->name = name;
    fiancee_idx = -1;
    this->preferences = new int [n];
    ratings = new int [n];
    for (int i = 0; i < n; i++) {
        this->preferences[i] = preferences[i];
        ratings[preferences[i]] = i;
    }
}

Person::~Person() {
    delete preferences;
    delete ratings;
}

class Record {
private:
    int size;
    Person **ps;
public:
    Record(Person **people, int n);
    list<Person *> toList();
    Person *lookup(int name) { return ps[name]; }
    int goodness();
};

int Record::goodness() {
    int res = 0;
    for (int i = 0; i < size; i++) {
        res += ps[i]->goodness();
    }
    return res / size;
}

list<Person *> Record::toList() {
    list<Person *> lst;
    for (int i = 0; i < size; i++) {
        lst.push_front(ps[i]);
    }
    return lst;
}

Record::Record(Person **people, int n) {
    size = n;
    ps = people;
}

/* ********************************************** */
/* This is the Gale-Shapley algoritm */
void match(Record men, Record women) {
    Person *m1, *w, *m2;
    list<Person *> single = men.toList();
    while (!single.empty()) {
        m1 = single.front();
        w = women.lookup(m1->nextFiancee());
        if (w->isAvailable()) {
            m1->changeFiancee(w);
            w->changeFiancee(m1);
            single.pop_front();
        } else {
            m2 = men.lookup(w->currentFiancee());
            if (w->prefers(m1, m2)) {
                m1->changeFiancee(w);
                w->changeFiancee(m1);
                single.pop_front();
                single.push_front(m2);
            } else {
                m1->changeFiancee(w);
            }
        }
    }
}
/* ***************************************** */

void rand_goodness(int n) {
    Person **m = new Person *[n];
    Person **w = new Person *[n];
    for (int i = 0; i < n; i++) {
        m[i] = new Person(i, n);
        w[i] = new Person(i, n);
    }

    Record men(m, n);
    Record women(w, n);

    match(men, women);

    printf("%d: %d %d\n", n, men.goodness(), women.goodness());

    for (int i = 0; i < n; i++) {
        delete m[i];
        delete w[i];
    }
    delete m;
    delete w;
}

int main(int argc, char **argv) {
    if (2 != argc) errx(1, "usage: %s n", argv[0]);
    int n;
    if (!sscanf(argv[1], "%d", &n)) errx(1, "usage: %s n", argv[0]);
    rand_goodness(n);
    return 0;
}
