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
    t_list    *stack_a;


    i = 1;
    while (i < ac)
    {
        if (i == 1)
            stack_a = ft_lstnew(ft_atoi(av[i]));
        else
            ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(av[i])));
        i++;
    }

    int j = 1;
    while (stack_a)
    {
        printf("[%d]:%d\n", j++, stack_a->content);
        stack_a = stack_a->next;
    }
}