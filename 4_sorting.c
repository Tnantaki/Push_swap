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

static int	ft_find_maxnb_i(t_list *lst)
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
		if (tmp > *(int *)lst->content)
		{
			tmp = *(int *)lst->content;
			maxnb_i = i;
		}
		lst = lst->next;
		i++;
	}
	return (maxnb_i);
}

void	ft_case_3(t_pushswap *pw)
{
	pw->size_a = ft_lstsize(pw->stk_a);
	pw->top = *(int *)(pw->stk_a->content);
	pw->vic = *(int *)(pw->stk_a->next->content);
	pw->bot = *(int *)(ft_lstlast(pw->stk_a)->content);
	if (pw->top > pw->vic && pw->top > pw->bot && pw->vic > pw->bot)
	{
		ft_sa(&pw->stk_a);
		ft_rra(&pw->stk_a);
	}
	else if (pw->top > pw->vic && pw->top > pw->bot && pw->vic < pw->bot)
		ft_ra(&pw->stk_a);
	else if (pw->top > pw->vic && pw->top < pw->bot)
		ft_sa(&pw->stk_a);
	else if (pw->top > pw->bot)
		ft_rra(&pw->stk_a);
	else if (pw->vic > pw->bot)
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
		pw->maxnb_i = ft_find_maxnb_i(pw->stk_a);
		if (pw->maxnb_i <= pw->size_a / 2)
		{
			while (pw->maxnb_i--)
				ft_ra(&pw->stk_a);
		}
		else
		{
			while (pw->maxnb_i++ < pw->size_a)
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
		// ft_showstack(pw->stk_a, pw->stk_b); // for show
		bit++;
	}
}
