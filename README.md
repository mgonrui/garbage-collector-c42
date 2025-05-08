A rudimentary "garbage collector" made for c 42 school projects.
It does (almost) automatic freeing, youll still have to do manual allocs :(

# How does it work

in function main, create a t_memnode that will store all the allocated pointers. return wit the wrapper gc_return
```c
#include "gc.h"

int main(void)
{
    t_memnode *memlist;
    // allocate some memory
    gc_return(0, &memlist);
}
```
