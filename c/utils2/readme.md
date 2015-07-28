# C utils

## Design
_add()
_remove()
_set()
_get()
_size()
_new()
_type()

/* returns a list of items. */
_each()

### Example: linked list

	_type(linked_list, int) mylist;
	if (_new(&mylist)) {
		/* memory failure */
	}

	_push(mylist, 3);
	int ret;

	if (_pop(mylist, &ret)) {
		/* some error */
	}
