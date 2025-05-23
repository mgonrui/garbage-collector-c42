#include "gc.h"

void	*gc_malloc(int nbytes, t_memnode **memlist)
{
	void	*allocd_ptr;

	allocd_ptr = malloc(nbytes);
	if (allocd_ptr == NULL)
		return (NULL);
	if (gc_add_ptr(allocd_ptr, memlist) == 1)
	{
		free(allocd_ptr);
		return (NULL);
	}
	return (allocd_ptr);
}

void	gc_exit(int status, t_memnode **memlist)
{
	gc_run(memlist);
	exit(status);
}

int	gc_return(int retvalue, t_memnode **memlist)
{
	gc_run(memlist);
	return (retvalue);
}
