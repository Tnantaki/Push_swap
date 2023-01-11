#include "pushswapft.h"

static int ft_check_int(char *str)
{
    long long nb;
    int i;

    i = 0;
    while (str[i])
    {
        nb = 0;
        while (str[i] == ' ')
            i++;
        if (str[i] == '+' || str[i] == '-')
            i++;
        while (ft_isdigit(str[i]) && (nb <= 2147483647 || nb >= -2147483648))
            nb = nb * 10 + (str[i++] - '0');
    }
    return (1);
}

int main(void)
{
    t_list  *stack_a;
    char **arg;

    stack_a = NULL;
    int i = 1;
    while (i < ac)
    {
        arg = ft_split(av, ' ');
        while (*arg)
        {
            ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(av[i])));
            (*arg)++;
        }
        i++;
    }
    int a =ft_check_int("  ++20");
    printf("a:%d\n", a);

}