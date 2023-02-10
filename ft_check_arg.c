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

#include "push_swap.h"

static int	ft_isint(char *str)
{
	long long	nb;
	int			i;
	int			negative;

	i = 0;
	nb = 0;
	negative = 1;
	if (!str)
		return (0);
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-'))
		i++;
	if (str[i] != '\0')
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			negative = -1;
	}
	while (ft_isdigit(str[i]) && nb <= 2147483648)
		nb = nb * 10 + (str[i++] - '0');
	nb = nb * negative;
	if (!(str[i]) && nb <= 2147483647 && nb >= -2147483648)
		return (1);
	return (0);
}

void	ft_check_integer(int ac, char **av, t_pushswap *pw)
{
	int		i;
	int		j;

	i = 1;
	pw->size = 0;
	while (i < ac)
	{
		j = 0;
		pw->arg = ft_split(av[i], ' ');
		if (!pw->arg)
			exit(1);
		while (pw->arg[j])
		{
			if (!ft_isint(pw->arg[j++]))
			{
				ft_double_free(pw->arg);
				ft_prterr(pw, DIGIT_ERR);
			}
			pw->size++;
		}
		ft_double_free(pw->arg);
		i++;
	}
	if (pw->size <= 1)
		exit(0);
}

void	ft_stack_num(int ac, char **av, t_pushswap *pw)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	pw->nb = (int *)malloc(sizeof(int) * pw->size);
	if (!pw->nb)
		exit(1);
	while (i < ac)
	{
		j = 0;
		pw->arg = ft_split(av[i], ' ');
		if (!pw->arg)
		{
			free(pw->nb);
			exit(1);
		}
		while (pw->arg[j])
			pw->nb[k++] = ft_atoi(pw->arg[j++]);
		ft_double_free(pw->arg);
		i++;
	}
}

void	ft_check_unique(t_pushswap *pw)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i + 1 < pw->size)
	{
		tmp = pw->nb[i];
		j = i + 1;
		while (j < pw->size)
		{
			if (tmp == pw->nb[j])
				ft_prterr(pw, UNIQUE_ERR);
			j++;
		}
		i++;
	}
}

void	ft_check_ascending_order(t_pushswap *pw)
{
	int	i;
	int	tmp;

	i = 1;
	while (i < pw->size)
	{
		tmp = pw->nb[i - 1];
		if (tmp > pw->nb[i])
			return ;
		i++;
	}
	printf("Ascending Order Argument.\n");//Don't forget to delete
	exit(0);
}
