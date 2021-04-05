#ifndef LLST_H
# define LLST_H
# include <stddef.h>

typedef struct s_llst
{
	long			l;
	struct s_llst	*next;
}		t_llst;

t_llst	*llst_new(long l);
void	llst_push_back(t_llst **lst, long l);
void	llst_push_front(t_llst **lst, long l);
void	llst_add_front(t_llst **lst, t_llst *new);
void	llst_add_back(t_llst **lst, t_llst *new);
void	llst_clear(t_llst **lst);
void	llst_delone(t_llst *lst);
void	llst_iter(t_llst *lst, void (*f)(long));
size_t	llst_length(t_llst *lst);
t_llst	*llst_last(t_llst *lst);

#endif
