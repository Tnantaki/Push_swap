/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:51:57 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:51:58 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswapft.h"

static int	ft_check_max(char *str)
{
	long long	nb;
	int			i;
	int			negative;

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

int	ft_check_unique(t_list *lst)
{
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

int	ft_check_order(t_list *lst)
{
	t_list	*tmp;

	tmp = lst->next;
	while (tmp)
	{
//		printf("lst:%d  = tmp:%d\n", *(int *)lst->content , *(int *)tmp->content);
		if (*(int *)lst->content > *(int *)tmp->content)
			return (1);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (0);
}

void ft_check_err(t_list *lst, t_info inf)
{
	if (inf.size == 1)
	{
		//printf("You have only one number\n");
		ft_lstclear(&lst, ft_delcont);
		exit(0);
	}
	if (!(ft_check_unique(lst)))
	{
		//printf("The number not unique\n");
		ft_lstclear(&lst, ft_delcont);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	if (!(ft_check_order(lst)))
	{
	//	printf("The number has descending order\n");
		ft_lstclear(&lst, ft_delcont);
		exit(0);
	}
}
