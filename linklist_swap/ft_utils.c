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

#include "pushswapft.h"

void ft_double_free(char **ptr)
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

void ft_prterr(t_list *lst, t_info inf)
{
	//printf("The argument is not integers\n");
	if (inf.nb)
		free(inf.nb);
	if (inf.arg)
		ft_double_free(inf.arg);
	if (lst)
		ft_lstclear(&lst, ft_delcont);
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
