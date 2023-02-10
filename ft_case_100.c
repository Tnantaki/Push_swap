/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 21:29:20 by tnantaki          #+#    #+#             */
/*   Updated: 2023/02/10 21:29:22 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_min_range(t_list *lst, t_chunk	*chk)
{
	chk->tob_i = 0;
	chk->tmp = lst;
	chk->size = ft_lstsize(lst) / 2;
	while (chk->i < chk->size)
	{
		if (*(int *)lst->content <= chk->range)
			break ;
		lst = lst->next;
		chk->tob_i++;
	}
	chk->bot_i = chk->size - 1;
	while (chk->bot_i >= 0)
	{
		if (*(int *)chk->tmp->content <= chk->range)
			break ;
		chk->tmp = chk->tmp->next;
		chk->bot_i--;
	}
}

void	ft_pop_chunk2b(t_pu , t_chunk *chk)
{
	chk->range = chk->chunk * 20;

	while (chk->i < )
	{
		ft_find_min_range(lst, chk);
		if ((chk->size - chk->bot_i) < chk->tob_i)
		{
			while (chk->tob_i--)
				ft_ra(&pw->stk_a);
		}
		else
		{
			while (chk->tob++ < chk->size)
				ft_rra(&pw->stk_a);
		}
		ft_pb(&pw->stk_a, &pw->stk_b);
	}
}

void	ft_case_100(t_pushswap *pw)
{
	t_chunk chk;

	chk.i = 0;
	chk.chunk = 1;

}