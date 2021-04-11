#include "../include/all.h"
#include <stdlib.h>

void	llst_clear(t_llst **lst)
{
	t_llst	*next;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

void	llst_delone(t_llst *lst)
{
	if (lst == NULL)
		return ;
	free(lst);
}

void	llst_iter(t_llst *lst, void (*f)(long))
{
	while (lst)
	{
		f(lst->l);
		lst = lst->next;
	}
}

size_t	llst_length(t_llst *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

t_llst	*llst_last(t_llst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
