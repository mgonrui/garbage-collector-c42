#include "gc.h"

int	gc_add_allocd_dbl_ptr(t_memnode **root, void **dblptr)
{
	t_memnode	*new_node;
	t_memnode	*current_memnode;

	if (*root == NULL)
	{
		*root = malloc(sizeof(t_memnode));
		if (*root == NULL)
			return (1);
		(*root)->isdouble = true;
		(*root)->dblptr = dblptr;
		(*root)->next = NULL;
		return (0);
	}
	new_node = malloc(sizeof(t_memnode));
	if (new_node == NULL)
		return (1);
	new_node->isdouble = true;
	new_node->dblptr = dblptr;
	new_node->next = NULL;
	current_memnode = *root;
	while (current_memnode->next != NULL)
		current_memnode = current_memnode->next;
	current_memnode->next = new_node;
	return (0);
}

int	gc_add_allocd_ptr(t_memnode **root, void *memptr)
{
	t_memnode	*new_node;
	t_memnode	*current_memnode;

	if (*root == NULL)
	{
		*root = malloc(sizeof(t_memnode));
		if (*root == NULL)
			return (1);
		(*root)->isdouble = false;
		(*root)->memptr = memptr;
		(*root)->next = NULL;
		return (0);
	}
	new_node = malloc(sizeof(t_memnode));
	if (new_node == NULL)
		return (1);
	new_node->isdouble = false;
	new_node->memptr = memptr;
	new_node->next = NULL;
	current_memnode = *root;
	while (current_memnode->next != NULL)
		current_memnode = current_memnode->next;
	current_memnode->next = new_node;
	return (0);
}

void	gc_run(t_memnode **root)
{
	t_memnode	*current;
	t_memnode	*prev;
	int			i;

	if (*root == NULL)
		return ;
	current = *root;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
		if (prev->isdouble)
		{
			i = 0;
			while (prev->dblptr[i] != NULL)
				free(prev->dblptr[i++]);
			free(prev->dblptr);
		}
		else
			free(prev->memptr);
		free(prev);
	}
	*root = NULL;
	return ;
}
