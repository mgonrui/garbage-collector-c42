A rudimentary "garbage collector" made for c 42 school projects.
It does (almost) automatic freeing, youll still have to do manual allocs :(

# How does it work

in function main, create a t_memnode that will store all the allocated pointers. allocate memory with gc_malloc passing the size and the t_memnode address, return wit the gc_return or exit with gc_exit in the same way.
```c
#include "gc.h"

int main(void)
{
    t_memnode *memlist;
    char *str = gc_malloc(sizeof(char) * 5, &memlist); // 
    if (str == NULL)
        gc_exit(1, &memlist);
    str = "hello";

    gc_return(0, &memlist);
}
```


for functions that allocate memory themselves, you must manually add the pointer(s) to the t_memnode:

```c
#includde <string.h>
#include "gc.h"

int main(void)
{
    t_memnode *memlist;
    char *str = strdup("hello world");
    if (str == NULL)
        gc_exit(1, &memlist);
    gc_add_allocd_ptr(str, &memlist);

    char **double_ptr = some_fn_that_returns_double_ptr();
    if (double_ptr == NULL)
        gc_exit(1, &memlist);
    gc_add_allocd_dbl_ptr(double_ptr, &memlist);

    gc_return(0, memlist);
}
```

