/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:52:02 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:52:03 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_list *lst)
{
	int		i;
	int		min_i;
	t_list	*tmp;

	i = 1;
	min_i = 0;
	tmp = lst;
	lst = lst->next;
	while (lst)
	{
		if (*(int *)tmp->content > *(int *)lst->content)
		{
			tmp = lst;
			min_i = i;
		}
		lst = lst->next;
		i++;
	}
	return (min_i);
}

// void	ft_findpos_stk_a(t_pushswap *pw)
// {
// 	pw->size_a = ft_lstsize(pw->stk_a);
// 	pw->top = *(int *)(pw->stk_a->content);
// 	pw->vic = *(int *)(pw->stk_a->next->content);
// 	pw->bot = *(int *)(ft_lstlast(pw->stk_a)->content);
// }

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
		pw->min_i = ft_find_min(pw->stk_a);
		if (pw->min_i <= pw->size_a / 2)
		{
			while (pw->min_i--)
				ft_ra(&pw->stk_a);
		}
		else
		{
			while (pw->min_i++ < pw->size_a)
				ft_rra(&pw->stk_a);
		}
		ft_pb(&pw->stk_a, &pw->stk_b);
		i++;
	}
	ft_case_3(pw);
	while (i-- > 3)
		ft_pa(&pw->stk_a, &pw->stk_b);
}

void	ft_sorting(t_pushswap *pw)
{
	if (pw->size == 2)
		ft_sa(&pw->stk_a);
	else if (pw->size == 3)
		ft_case_3(pw);
	else if (pw->size == 4)
		ft_case_100(pw)
	else
		ft_case_5(pw);
}
