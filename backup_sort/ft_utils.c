/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:51:29 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:51:32 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_prterr(t_pushswap *pw)
{
	// if (err == 1)
	// 	printf("The argument must be digits.\n");
	// if (err == 2)
	// 	printf("The argument must not be the same number.\n");
	pw->arg = NULL;
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (i <= 46340)
	{
		if (i * i > nb)
			return (i - 1);
		i++;
	}
	return (0);
}
