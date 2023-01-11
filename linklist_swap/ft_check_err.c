#include "pushswapft.h"

static int	ft_check_max(char *str)
{
	int			i;
	int			negative;
	long long	nb;

	i = 0;
	nb = 0;
	negative = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	if (!(ft_isdigit(str[i])))
		return (0);
	while (ft_isdigit(str[i]) && nb <= 2147483648)
		nb = nb * 10 + (str[i++] - '0');
	nb = nb * negative;
	if (!(str[i]) && nb <= 2147483647 && nb >= -2147483648)
		return (1);
	return (0);
}

int	ft_check_int(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-'))
		i++;
	if (str[i] != '\0')
		return (0);
	if (!(ft_check_max(str)))
		return (0);
	return (1);
}

int	ft_check_order(t_list *lst)
{
	// int	i;
	// int	*num;
	// int	size;

	// i = 0;
	// size = ft_lstsize(lst);
	// num = (int *)malloc(sizeof(int) * size);
	// while (lst)
	// {
	// 	num[i++] = *(int *)(lst->content);
	// 	lst = lst->next;
	// 	printf("num[%d]:%d\n", i, num[i - 1]);
	// }
	t_list	*tmp;

	while (lst->next)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*(int *)lst->content == *(int *)tmp->content)
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}
