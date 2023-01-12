/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:55:54 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:56:03 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check(const char *str, int *i, int *negative)
{
	while ((str[*i] && str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	if (str[*i] && (str[*i] == '+'))
		*i += 1;
	else if (str[*i] && (str[*i] == '-'))
	{
		*negative = -1;
		*i += 1;
	}
}

int	ft_atoi(const char *str)
{
	long long	nb;
	int			negative;
	int			i;

	i = 0;
	nb = 0;
	negative = 1;
	ft_check(str, &i, &negative);
	while (str[i] && ft_isdigit(str[i]))
	{
		if (nb >= 9223372036854775807 / 10 && str[i] - '0' > 7)
		{
			if (negative == 1)
				return (-1);
			else
				return (0);
		}
		nb = nb * 10 + (str[i++] - '0');
	}
	return (nb * negative);
}
