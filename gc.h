#ifndef GARBCOL_H
# define GARBCOL_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

/* # define malloc(x) 0 */

typedef struct s_memnode
{
	bool				isdouble;
	void				**dblptr;
	void				*memptr;
	struct s_memnode	*next;
}						t_memnode;

int						gc_add_allocd_ptr(t_memnode **root, void *memptr);
void					*gc_malloc(int nbytes, t_memnode **memlist);
void					free_llist(t_memnode **root);
void					gc_free(t_memnode **root);
void					gc_exit(int status, t_memnode **memlist);
int						gc_return(int retvalue, t_memnode **memlist);
int						gc_add_allocd_dbl_ptr(t_memnode **root, void **dblptr);
#endif // GARBCOL_H
