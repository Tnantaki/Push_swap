#include "pushswapft.h"

void    ft_showstack(t_list *tmp)
{
    int i;

    i = 1;
    while (tmp)
    {
        printf("[%d]:%d\n", i++, *(int *)(tmp->content));
        tmp = tmp->next;
    }
}