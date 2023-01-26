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

#include "pswft.h"

void ft_free2ptr(char **ptr)
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

void ft_prterr(char **arg)
{
	printf("The argument is not integers\n");
	if (arg)
		ft_free2ptr(arg);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
