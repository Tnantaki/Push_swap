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

int	ft_find_maxnb_i(t_list *lst, t_chunk	*chk)
{
	int	i;

	i = 0;
	while (i <= chk->half)
	{
		if (*(int *)lst->content == chk->size)
			return (i);
		lst = lst->next;
		i++;
	}
	while (i < chk->size)
	{
		if (*(int *)lst->content == chk->size)
			return (i);
		lst = lst->next;
		i++;
	}
	// printf("Error find_max\n");
	return (chk->size);
}

void	ft_find_range_nb(t_list *lst, t_chunk	*chk)
{
	int	i;

	i = 0;
	while (i <= chk->half)
	{
		if (*(int *)lst->content <= chk->max)
			break ;
		lst = lst->next;
		i++;
	}
	chk->tob_i = i;
	while (i < chk->size && lst)
	{
		if (*(int *)lst->content <= chk->max)
			chk->bot_i = i;
		lst = lst->next;
		i++;
	}
	if (lst)
		printf("FIX YOUR LOOP\n");// For Show
}

void	ft_pop_chunk_2_b(t_pushswap *pw , t_chunk *chk)
{
	// while (chk->i < chk->max)
	// {
		chk->size = ft_lstsize(pw->stk_a);
		chk->half = chk->size / 2;
		ft_find_range_nb(pw->stk_a, chk);
		if ((chk->size - chk->bot_i) > chk->tob_i)
		{
			while (chk->tob_i--)
				ft_ra(&pw->stk_a);
		}
		else
		{
			while (chk->bot_i++ < chk->size)
				ft_rra(&pw->stk_a);
		}
		ft_pb(&pw->stk_a, &pw->stk_b);
		chk->i++;
	// }
}

void	ft_pop_chunk2a(t_pushswap *pw , t_chunk *chk)
{
	chk->size = ft_lstsize(pw->stk_b);
	chk->half = chk->size / 2;
	chk->max_i = ft_find_max_nb_i(pw->stk_b, chk);
	// printf("chk_max:%d\n", chk->max_i);// For Show
	// exit(0);
	if (chk->max_i <= chk->half)
	{
		while (chk->max_i--)
			ft_rb(&pw->stk_b);
	}
	else
	{
		while (chk->max_i++ < chk->size)
			ft_rrb(&pw->stk_b);
	}
	ft_pa(&pw->stk_a, &pw->stk_b);
}
void	ft_cal_chunk(t_pushswap *pw, t_chunk *chk)
{
	// chk.i = 0;
	chk.chunk_cap = (ft_sqrt(pw->size) * 0.2 + 1) * 2;
	chk.range = pw->size / chk.chunk_cap;
	chk.frac = pw->size % chk.chunk_cap;
	chk.g = (int *)malloc(sizeof(int) * chk->chunk_cap);
	if (!chk.g)
		exit (1);// Free plase
	chk.i = 0;
	while (chk.i < chk.chunk_cap)
	{
		if (chk.frac-- > 0)
			chk->range += 1;
		chk.g[chk.i] = chk.range;
	}

}

void	ft_all_case(t_pushswap *pw)
{
	t_chunk chk;

	ft_cal_chunk(pw, &chk);
	chk.chunk = 1;
	while (chk->chunk <= chk->chunk_cap)
	{
		ft_
	}
	ft_pop_chunk_2_b(pw, &chk);
}
	while (--chk.i >= 0)
		ft_pop_chunk2a(pw, &chk);