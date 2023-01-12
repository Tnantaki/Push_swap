#include "actft.h"

void ft_pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	tmp = *lst_b;
	*lst_b = (*lst_b)->next;
	tmp->next = *lst_a;
	*lst_a = tmp;
	ft_putendl_fd("pa", 1);
}

void ft_pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;

	tmp = *lst_a;
	*lst_a = (*lst_a)->next;
	tmp->next = *lst_b;
	*lst_b = tmp;
	ft_putendl_fd("pb", 1);
}
