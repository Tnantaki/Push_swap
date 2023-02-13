/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_lst_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:53:44 by tnantaki          #+#    #+#             */
/*   Updated: 2023/02/13 19:53:45 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_index_arrage(t_pushswap *pw)
{
	int	i;
	int	tmp;
	int	point;

	point = 0;
	while (point < pw->size)
	{
		if (pw->arr[point] == 0)
			break ;
		point++;
	}
	tmp = pw->nb[point];
	i = point + 1;
	while (i < pw->size)
	{
		if (tmp > pw->nb[i] && pw->arr[i] == 0)
		{
			tmp = pw->nb[i];
			point = i;
		}
		i++;
	}
	return (point);
}

void	ft_arrange_num(t_pushswap *pw)
{
	int	i;
	int	order;

	pw->arr = (int *)malloc(sizeof(int) * pw->size);
	if (!pw->arr)
	{
		free(pw->nb);
		exit(1);
	}
	i = 0;
	while (i < pw->size)
		pw->arr[i++] = 0;
	order = 1;
	while (order <= pw->size)
		pw->arr[ft_index_arrage(pw)] = order++;
	free(pw->nb);
	pw->nb = pw->arr;
}

void	ft_lst_num(t_pushswap *pw)
{
	int	i;
	int	*tmp;

	i = 0;
	pw->stk_a = NULL;
	pw->stk_b = NULL;
	while (i < pw->size)
	{
		tmp = (int *)malloc(sizeof(int));
		if (!tmp)
		{
			ft_lstclear(&pw->stk_a, ft_delcont);
			free(pw->nb);
			exit(1);
		}
		*tmp = pw->nb[i];
		ft_lstadd_back(&pw->stk_a, ft_lstnew(tmp));
		i++;
	}
	free(pw->nb);
}
