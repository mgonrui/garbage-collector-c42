#include "garbcol.h"

int add_allocd_ptr(t_memnode **root, void *memptr)
{
	t_memnode	*new_node;
	t_memnode	*current_memnode;

	if (*root == NULL)
	{
		*root = malloc(sizeof(t_memnode));
		if (*root == NULL)
			return 1;
		(*root)->memptr = memptr;
		(*root)->next = NULL;
		return 0;
	}
	new_node = malloc(sizeof(t_memnode));
	if (new_node == NULL)
		return 1;
	new_node->memptr = memptr;
	new_node->next = NULL;
	current_memnode = *root;
	while (current_memnode->next != NULL)
		current_memnode = current_memnode->next;
	current_memnode->next = new_node;
	return 0;
}

void	*gc_malloc(int nbytes, t_memnode **memlist)
{
	void	*allocd_ptr;

	allocd_ptr = malloc(nbytes);
	if (allocd_ptr == NULL)
		return NULL;
	if (add_allocd_ptr(memlist, allocd_ptr) == 1)
	{
		free(allocd_ptr);
		return NULL;
	}
	return (allocd_ptr);
}

void	gc_free(t_memnode **root)
{
	t_memnode	*current;
	t_memnode	*prev;

	if (*root == NULL)
		return ;
	current = *root;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
		free(prev->memptr);
		free(prev);
	}
	*root = NULL;
	return ;
}

void	gc_exit(int status, t_memnode **memlist)
{
	gc_free(memlist);
	exit(status);
}

int	gc_return(int retvalue, t_memnode **memlist)
{
	gc_free(memlist);
	return (retvalue);
}
