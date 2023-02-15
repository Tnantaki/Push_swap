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

int	ft_find_maxnb_i(t_list *lst)
{
	int	i;
	int	maxnb_i;
	int	tmp;

	i = 1;
	maxnb_i = 0;
	tmp = *(int *)lst->content;
	lst = lst->next;
	while (lst)
	{
		if (tmp < *(int *)lst->content)
		{
			tmp = *(int *)lst->content;
			maxnb_i = i;
		}
		lst = lst->next;
		i++;
	}
	return (maxnb_i);
}

void	ft_push_chunk2a(t_pushswap *pw)
{
	int	i;

	i = 0;
	// ft_showstack(pw->stk_a, pw->stk_b); // for show
	while (i < pw->size)
	{
		pw->size_b = ft_lstsize(pw->stk_b);
		pw->maxnb_i = ft_find_maxnb_i(pw->stk_b);
		if (pw->maxnb_i <= pw->size_b / 2)
		{
			while (pw->maxnb_i--)
				ft_rb(&pw->stk_b);
		}
		else
		{
			while (pw->maxnb_i++ < pw->size_b)
				ft_rrb(&pw->stk_b);
		}
		ft_pa(&pw->stk_a, &pw->stk_b);
		i++;
	}
}

void	ft_find_range_nb(t_list *lst, int size, t_chunk *chk)
{
	int	i;
	int	half;

	i = 0;
	half = size / 2;
	while (i <= half)
	{
		if (*(int *)lst->content <= chk->range[chk->chunk])
			break ;
		lst = lst->next;
		i++;
	}
	chk->tob_i = i;
	while (i < size)
	{
		if (*(int *)lst->content <= chk->range[chk->chunk])
			chk->bot_i = i;
		lst = lst->next;
		i++;
	}
	if (lst)
		printf("FIX YOUR LOOP\n");// For Show
}

void	ft_push_chunk2b(t_pushswap *pw, t_chunk *chk)
{
	while (chk->i < chk->range[chk->chunk])
	{
		pw->size_a = ft_lstsize(pw->stk_a);
		ft_find_range_nb(pw->stk_a ,pw->size_a, chk);
		if ((pw->size_a - chk->bot_i) > chk->tob_i)
		{
			while (chk->tob_i--)
				ft_ra(&pw->stk_a);
		}
		else
		{
			while (chk->bot_i++ < pw->size_a)
				ft_rra(&pw->stk_a);
		}
		ft_pb(&pw->stk_a, &pw->stk_b);
		chk->i++;
	}
}

void	ft_setchunk(t_pushswap *pw, t_chunk *chk)
{
	int	gap;
	int	frac;
	int	range;

	chk->chunk_cap = (ft_sqrt(pw->size) * 0.3 + 1);
	gap = pw->size / chk->chunk_cap;
	frac = pw->size % chk->chunk_cap;
	chk->range = (int *)malloc(sizeof(int) * chk->chunk_cap);
	chk->range_half = (int *)malloc(sizeof(int) * chk->chunk_cap);
	if (!chk->range || !chk->range_half)	
	{
		ft_lstclear(&pw->stk_a, ft_delcont);
		exit (1);// Free plase
	}
	chk->i = 0;
	range = 0;
	while (chk->i < chk->chunk_cap)
	{
		range += gap;
		if (frac-- > 0)
			range++;
		chk->range[chk->i] = range;
		chk->range_half[chk->i] = chk->range[chk->i] / 2;
		chk->i++;
	}
}

void	ft_quick_sort(t_pushswap *pw)
{
	t_chunk chk;

	ft_setchunk(pw, &chk);
	chk.chunk = 0;
	// printf("chunk_cap: %d\n", chk.chunk_cap);
	// printf("size: %d\n", pw->size);
	// for (int i = 0; i < chk.chunk_cap;i++)
	// 	printf("range[%d]:%d\n", i, chk.range[i]);
	// exit (0);
	chk.i = 0;
	while (chk.chunk < chk.chunk_cap)
	{
		ft_push_chunk2b(pw, &chk);
		chk.chunk++;
	}
	ft_push_chunk2a(pw);
	// while (chk.chunk > 0)
	// {
	// 	chk.chunk--;
	// 	ft_push_chuck2a(pw, &chk);
	// }
}