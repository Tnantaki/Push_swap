#include "actft.h"

void    ft_ra(t_list **lst)
{
    t_list  *tmp;

    tmp = *lst;
    *lst = (*lst)->next;
    tmp->next = NULL;
    ft_lstadd_back(lst, tmp);
    ft_putendl_fd("ra", 1);
}

void    ft_rb(t_list **lst)
{
    t_list  *tmp;

    tmp = *lst;
    *lst = (*lst)->next;
    tmp->next = NULL;
    ft_lstadd_back(lst, tmp);
    ft_putendl_fd("rb", 1);
}

void    ft_rr(t_list **lst_a, t_list **lst_b)
{
    t_list  *tmp_a;
    t_list  *tmp_b;

    tmp_a = *lst_a;
    tmp_b = *lst_b;
    *lst_a = (*lst_a)->next;
    *lst_b = (*lst_b)->next;
    tmp_a->next = NULL;
    tmp_b->next = NULL;
    ft_lstadd_back(lst_a, tmp_a);
    ft_lstadd_back(lst_b, tmp_b);
    ft_putendl_fd("rr", 1);
}