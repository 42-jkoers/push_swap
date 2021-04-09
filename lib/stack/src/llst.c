#include "../include/all.h"
#include <stdlib.h>

t_llst	*llst_new(long l)
{
	t_llst	*lst;

	lst = ft_malloc(sizeof(t_llst));
	lst->l = l;
	lst->next = NULL;
	return (lst);
}

void	llst_push_back(t_llst **lst, long l)
{
	if (lst == NULL || *lst == NULL)
		*lst = llst_new(l);
	else
		(llst_last(*lst))->next = llst_new(l);
}

void	llst_push_front(t_llst **lst, long l)
{
	t_llst	*old_front;

	old_front = *lst;
	*lst = llst_new(l);
	(*lst)->next = old_front;
}

void	llst_add_front(t_llst **lst, t_llst *new)
{
	t_llst	*old_front;

	old_front = *lst;
	*lst = new;
	(*lst)->next = old_front;
}

void	llst_add_back(t_llst **lst, t_llst *new)
{
	if (lst == NULL || *lst == NULL)
		*lst = new;
	else
		(llst_last(*lst))->next = new;
}

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
