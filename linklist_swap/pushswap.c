#include "pushswap.h"

static void ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int ac, char **av)
{
    int i;
    t_list    stack_a;


    i = 0;
    while (i < ac - 1)
    {
        if (i == 0)
            stack_a = ft_lstnew(ft_atoi(av[i]))
        else
            ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(av[i])));
        i++;
    }
    
    // int j = 0;
    // while (j < i)
    // {
    //     printf("[%d]:%d\n", j, stack_a[j]);
    //     j++;
    // }
    // int k = 0;
    // while (k < i)
    // {
    //     if (stack_a[k] < stack_a[k + 1])
    //         stack_a[k];
    // }
    // while (i + 1 < ac)
    // {
    //     nb = ft_atoi(av[i++]);
    //     ft_lstadd_back(&head, ft_lstnew(ft_atoi(av[i++])));
    // }
    // while (*head)
    // {
    //     printf("[%d]:%s\n", head->content);
    //     head = head->next;
    // }
}