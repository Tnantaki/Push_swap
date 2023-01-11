#include "pushswapft.h"
/*
static void    ft_check_order(t_list *lst)
{
    while (lst->next != NULL && lst->content < (lst->next)->content)
    {
        lst = lst->next;
        if (lst->next == NULL)
        {
            //printf("The number has already ascendant order.\n");
            ft_lstfree(lst);
            exit (0);
        }
    }
}

static int ft_check_int(char *str)
{
    int nb;
    int i;
    int negative;

    nb = 0;
    i = 0;
    negative = 1;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i] == '+' || str[i] == '-')
            i++;
        while (ft_isdigit(str[i]))
        {
            if (nb >= 2147483647 / 10 && str[i] - '0' > 7)
            {
                if (negative == -1 && str[i] == 8)
                    break ;
                else
                    return (0);
            }
            nb = nb * 10 + (str[i++] - '0');
        }
    }
}

int main(void)
{
    int a = ft_check_int("20");
    printf("%d", a);
}
/*
static int ft_count_arg(char *str)
{
    int i;
    int nb;
    int negative;

    i = 0;
    negative = 1;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i] == '+' || str[i] == '-')
        {
            negative = -1;
            i++;
        }
        while (ft_isdigit(str[i]))
        {
            if (nb >= 2147483647 / 10 && str[i] - '0' > 7)
            {
                if (negative == -1 && str[i] == 8)
                    return (-21474836478);
                else
                    ft_error (1);
            }
            nb = nb * 10 + (str[i++] - '0');
        }
	    return (nb * negative);
    }
}

static void ft_count_arg(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < ac)
    {
        while (av[i][j])
        {
            while (av[i][j] == ' ')
                i++;
            if (av[i][j] == '+' || av[i][j] == '-')
            {
                negative = -1;
                i++;
            }
            while (ft_isdigit(str[i]))
            {
                if (nb >= 2147483647 / 10 && str[i] - '0' > 7)
                {
                    if (negative == -1 && str[i] == 8)
                        return (-21474836478);
                    else
                        ft_error (1);
                }
                nb = nb * 10 + (str[i++] - '0');
            }
            return (nb * negative);
        }
        i++;
    }
}
*/

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

void    ft_prterr(t_list lst, char **arg)
{
    ft_double_free(arg);
    ft_lstclear(&lst, ft_delcont);
    ft_putendl_fd("Error", 2);
}

t_list *ft_listnum(t_list *lst, int ac, char **av)
{
    int i;
    int j;
    int *tmp_nb;
    char    **arg;

    i = 1;
    while (i < ac)
    {
        j = 0;
        arg = ft_split(av[i], ' ');
        while (arg[j])
        {
            tmp_nb = (int *)malloc(sizeof(int));
            if (!tmp_nb)
                return (NULL);
            if (!(ft_checkint(arg[j]))
                ft_prterr(arg, lst);
            *tmp_nb = ft_atoi(arg[j]);
            ft_lstadd_back(&stack_a, ft_lstnew(tmp_nb));
            j++;
        }
        ft_double_free(arg);
        i++;
    }
    return (lst)
}

int main(int ac, char **av)
{
    t_list    *stack_a;

    stack_a = NULL;
    if (ac == 1)
        exit (0);
    ft_showstack(stack_a);
    //ft_check_order(stack_a);
    //ft_case_3(&stack_a);
    ft_lstclear(&stack_a, ft_delcont);

    // printf("--------------------------\n");
    // j = 1;
    // while (stack_a)
    // {
    //     printf("[%d]:%d\n", j++, stack_a->content);
    //     stack_a = stack_a->next;
    // }
}
