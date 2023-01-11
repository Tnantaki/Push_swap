#include "pushswapft.h"


void    ft_double_free(char **ptr)
{
    int     i;

    i = 0;
    while (ptr[i])
    {
        free (ptr[i]);
        i++;
    }
    free (ptr);
}

void    ft_prterr(t_list *lst, char **arg, int *tmp_nb)
{
    if (tmp_nb)
        free(tmp_nb);
    if (arg)
        ft_double_free(arg);
    ft_lstclear(&lst, ft_delcont);
    ft_putendl_fd("Error", 2);
    exit (0);
}

t_list *ft_lstnum(int ac, char **av)
{
    int i;
    int j;
    int *tmp_nb;
    char    **arg;
    t_list  *lst;

    i = 1;
    lst = NULL;
    while (i < ac)
    {
        j = 0;
        arg = ft_split(av[i], ' ');
        while (arg[j])
        {
            tmp_nb = (int *)malloc(sizeof(int));
            if (!(ft_check_int(arg[j])) || !tmp_nb)
                ft_prterr(lst, arg, tmp_nb);
            *tmp_nb = ft_atoi(arg[j]);
            ft_lstadd_back(&lst, ft_lstnew(tmp_nb));
            j++;
        }
        ft_double_free(arg);
        i++;
    }
    return (lst);
}

int main(int ac, char **av)
{
    int size;
    t_list    *stack_a;

    if (ac == 1)
        exit (0);
    stack_a = ft_lstnum(ac, av);
    ft_showstack(stack_a);
    if (!(ft_check_order(stack_a)))
        ft_prterr(stack_a, NULL, NULL);
    size = ft_lstsize(stack_a);
    if (size == 3)
        ft_case_3(&stack_a);
    // printf("--------------------------\n");
    // ft_showstack(stack_a);
    ft_lstclear(&stack_a, ft_delcont);
}
