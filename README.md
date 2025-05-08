# What it is
A rudimentary "garbage collector" made for c 42 school projects.
It does automatic freeing, but you'll still have to do manual allocs.

# How does it work

In the start of the program, we will create a struct pointer that will serve as a linked list and will contain pointers to all the dynamically allocated variables. At the end of the program we will deallocate the list with gc_return() and gc_exit(). The wrapper gc_malloc() will function as a malloc that will automatically assign a new pointer in the list to the allocated memory. If we use a function that dinamically allocates memory by itself in a variable, we can add to the list a pointer to the variable with gc_add_ptr() and gc_add_dbl_ptr() so they can too be deallocated automatically. 

# How to use it
in function main, create a t_memnode that will store all the allocated pointers. allocate memory with gc_malloc passing the size and the t_memnode address, return with the gc_return or exit with gc_exit in the same way.
```c
#include "gc.h"

int main(void)
{
    t_memnode *memlist;
    memlist = NULL;
    
    char *str = gc_malloc(sizeof(char) * 5, &memlist); // 
    if (str == NULL)
        gc_exit(1, &memlist);
    str = "hello";

    gc_return(0, &memlist);
}
```


For functions that allocate memory themselves, you must manually add the pointer(s) to the t_memnode, we can add single or double pointers:

```c
#include <string.h>
#include "gc.h"

int main(void)
{
    t_memnode *memlist;
    memlist = NULL;

    char *str = strdup("hello world");
    if (str == NULL)
        gc_exit(1, &memlist);
    gc_add_ptr((void*)str, &memlist);

    char **double_ptr = some_fn_that_returns_double_ptr();
    if (double_ptr == NULL)
        gc_exit(1, &memlist);
    gc_add_dbl_ptr((void **)double_ptr, &memlist);

    gc_return(0, &memlist);
}
```

