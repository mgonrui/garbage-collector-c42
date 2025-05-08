#ifndef GC_H
# define GC_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_memnode
{
	bool				isdouble;
	void				**dblptr;
	void				*memptr;
	struct s_memnode	*next;
}						t_memnode;

int						gc_add_ptr(void *memptr,  t_memnode **root);
int						gc_add_dbl_ptr(void **dblptr, t_memnode **root);
void					gc_run(t_memnode **root);
void					*gc_malloc(int nbytes, t_memnode **memlist);
void					gc_exit(int status, t_memnode **memlist);
int						gc_return(int retvalue, t_memnode **memlist);
#endif // GC_H
