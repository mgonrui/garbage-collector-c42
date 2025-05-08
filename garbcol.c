#include "garbcol.h"

void	add_allocd_ptr(t_memnode **root, void *memptr)
{
	t_memnode	*new_node;
	t_memnode	*current_memnode;

	if (*root == NULL)
	{
		*root = malloc(sizeof(t_memnode));
		if (*root == NULL)
			exit(1);
		(*root)->memptr = memptr;
		(*root)->next = NULL;
		return ;
	}
	new_node = malloc(sizeof(t_memnode));
	if (new_node == NULL)
		exit(1);
	new_node->memptr = memptr;
	new_node->next = NULL;
	current_memnode = *root;
	while (current_memnode->next != NULL)
		current_memnode = current_memnode->next;
	current_memnode->next = new_node;
}

void	*gc_malloc(int nbytes, t_memnode **memlist)
{
	void	*allocd_ptr;

	allocd_ptr = malloc(nbytes);
	add_allocd_ptr(memlist, allocd_ptr);
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

void	gc_exit(int errcode, t_memnode *memlist)
{
	gc_free(&memlist);
	exit(errcode);
}

int	gc_return(int retvalue, t_memnode *memlist)
{
	gc_free(&memlist);
	return (retvalue);
}
