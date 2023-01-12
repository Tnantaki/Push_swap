#include "pushswapft.h"

void	ft_find_least_pb(t_list **lst_a, t_list **lst_b)
{
	t_list *tmp;
	t_list *least;

	least = *lst_a;
	while ((*lst)->next)
	{
		tmp = (*lst)->next;
		while (tmp)
		{
			if (*(int *)(*lst)->content > *(int *)tmp->content)
				least = tmp;
			tmp = tmp->next;
		}
		*lst = (*lst)->next;
	}
	return (1);
}

void	ft_case_3(t_list **lst)
{
	int first;
	int second;
	int last;

	first = *(int *)((*lst)->content);
	second = *(int *)(((*lst)->next)->content);
	last = *(int *)(ft_lstlast(*lst)->content);
	if (first > second && first < last && second < last)
		ft_sa(lst);
	else if (first > second && first > last && second > last)
	{
		ft_sa(lst);
		ft_rra(lst);
	}
	else if (first > second && first > last && second < last)
		ft_ra(lst);
	else if (first < second && first < last && second > last)
	{
		ft_sa(lst);
		ft_ra(lst);
	}
	else
		ft_rra(lst);
}

void	ft_case_5(t_list **lst_a, t_list **lst_b, size)
{
	int	first;

	first = *(int *)((*lst_a)->content);
	if (size == 3)
		ft_case_3(lst_a);
	else if (size == 4)
	{
		ft_pb(lst_a, lst_b);
		ft_case_3(lst_a);
	}
}