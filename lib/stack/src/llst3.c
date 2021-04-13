#include "../include/all.h"

// small to big
bool	llst_issorted(const t_llst *lst)
{
	t_llst	*l;

	if (!lst)
		return (true);
	l = (t_llst *)lst;
	while (true)
	{
		if (!l->next)
			return (true);
		if (l->l > l->next->l)
			return (false);
		l = l->next;
	}
}
