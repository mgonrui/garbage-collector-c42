#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct s_node
{
	void *memptr;
	struct s_node *next;
} t_node;

void	add_allocd_ptr(t_node **root, void *memptr)
{
	t_node	*new_node;
	t_node	*current_node;

	if (*root == NULL)
	{
		(*root) = malloc(sizeof(t_node));
		if (*root == NULL)
			exit(1);
		(*root)->memptr= memptr;
		(*root)->next = NULL;
		return ;
	}
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->memptr = memptr;
	new_node->next = NULL;
	current_node = *root;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new_node;
}

void *gc_malloc(int nbytes, t_node **memlist)
{
	void *allocd_ptr;
	allocd_ptr = malloc(nbytes);
	add_allocd_ptr(memlist, allocd_ptr);
	return allocd_ptr;
}

void	free_llist(t_node **root)
{
	t_node	*current;
	t_node	*prev;

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

void gc_exit(int errcode, t_node *memlist)
{
	free_llist(&memlist);
	exit(errcode);
}

int gc_return(int retvalue, t_node *memlist)
{
	free_llist(&memlist);
	return (retvalue);
}
