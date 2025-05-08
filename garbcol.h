#ifndef GARBCOL_H
# define GARBCOL_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_memnode
{
	void				*memptr;
	struct s_memnode	*next;
}						t_memnode;

void					add_allocd_ptr(t_memnode **root, void *memptr);
void					*gc_malloc(int nbytes, t_memnode **memlist);
void					free_llist(t_memnode **root);
void					gc_exit(int errcode, t_memnode *memlist);
void					gc_free(t_memnode **root);
#endif // GARBCOL_H
