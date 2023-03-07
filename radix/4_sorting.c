/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sorting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:53:50 by tnantaki          #+#    #+#             */
/*   Updated: 2023/02/13 19:53:52 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_minnb_i(t_list *lst)
{
	int	i;
	int	minnb_i;
	int	tmp;

	i = 1;
	minnb_i = 0;
	tmp = *(int *)lst->content;
	lst = lst->next;
	while (lst)
	{
		if (tmp > *(int *)lst->content)
		{
			tmp = *(int *)lst->content;
			minnb_i = i;
		}
		lst = lst->next;
		i++;
	}
	return (minnb_i);
}

void	ft_case_3(t_pushswap *pw)
{
	int	top;
	int	mid;
	int	bot;

	top = *(int *)(pw->stk_a->content);
	mid = *(int *)(pw->stk_a->next->content);
	bot = *(int *)(ft_lstlast(pw->stk_a)->content);
	if (top > mid && top > bot && mid > bot)
	{
		ft_sa(&pw->stk_a);
		ft_rra(&pw->stk_a);
	}
	else if (top > mid && top > bot && mid < bot)
		ft_ra(&pw->stk_a);
	else if (top > mid && top < bot)
		ft_sa(&pw->stk_a);
	else if (top > bot)
		ft_rra(&pw->stk_a);
	else if (mid > bot)
	{
		ft_sa(&pw->stk_a);
		ft_ra(&pw->stk_a);
	}
}

void	ft_case_5(t_pushswap *pw)
{
	int	i;

	i = 3;
	while (i < pw->size)
	{
		pw->size_a = ft_lstsize(pw->stk_a);
		pw->minnb_i = ft_find_minnb_i(pw->stk_a);
		if (pw->minnb_i <= pw->size_a / 2)
		{
			while (pw->minnb_i--)
				ft_ra(&pw->stk_a);
		}
		else
		{
			while (pw->minnb_i++ < pw->size_a)
				ft_rra(&pw->stk_a);
		}
		ft_pb(&pw->stk_a, &pw->stk_b);
		i++;
	}
	ft_case_3(pw);
	while (i-- > 3)
		ft_pa(&pw->stk_a, &pw->stk_b);
}

void	ft_radix_sort(t_pushswap *pw)
{
	int	i;
	int	bit;

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
		pw->size_b = ft_lstsize(pw->stk_b);
		while (pw->size_b--)
			ft_pa(&pw->stk_a, &pw->stk_b);
		bit++;
	}
}
