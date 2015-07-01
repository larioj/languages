#define T int
#define C dll
#define _INNER( type, classname, methodname ) \
     type ## classname ## _ ## methodname
#define _OUTER( type, classname, methodname ) \
     _INNER(type, classname, methodname)
#define _(name) \
	_OUTER(T, C, name)

#ifndef intdll_LIST_H_
#define intdll_LIST_H_

void _(pop)();

/* macro testing. */
int main() {
	return 0;
}

#endif
