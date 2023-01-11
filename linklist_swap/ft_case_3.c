#include "pushswapft.h"

void    ft_case_3(t_list **lst)
{
    int first; 
    int second; 
    int last; 

    first = (*lst)->content;
    second = ((*lst)->next)->content;
    last = (ft_lstlast(*lst))->content;
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