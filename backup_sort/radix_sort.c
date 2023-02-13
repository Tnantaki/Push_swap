/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:39:13 by tnantaki          #+#    #+#             */
/*   Updated: 2023/02/13 12:39:26 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_lst_check_ascending_order(t_list *lst_a, int	size)
// {
// 	int		i;
// 	t_list *tmp; 

// 	i = 1;
// 	while (i < size)
// 	{
// 		tmp = lst_a->next;
// 		if (*(int *)tmp->content > *(int *)lst_a->content)
// 			return ;
// 		lst_a = lst_a->next;
// 		i++;
// 	}
// 	exit(0);
// }

void	radix_sort(t_pushswap *pw)
{
	int	i;
	int	bit;
	int	size_b;

	bit = 0;
	while ((pw->size >> bit) > 0)
	{
		i = 0;
		while (i++ < pw->size)
		{
			if (!(((*(int *)pw->stk_a->content >> bit) & 1) == 1))
				ft_pb(&pw->stk_a, &pw->stk_b);
			else
				ft_ra(&pw->stk_a);
		}
		size_b = ft_lstsize(pw->stk_b);
		while (size_b--)
			ft_pa(&pw->stk_a, &pw->stk_b);
		bit++;
	}
}
