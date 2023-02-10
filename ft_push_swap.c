/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:51:16 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:51:23 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			free(pw->nb);
			exit(1);
		}
		*tmp = pw->nb[i];
		ft_lstadd_back(&pw->stk_a, ft_lstnew(tmp));
		i++;
	}
	free(pw->nb);
}

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
	i = 0;
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

int	main(int ac, char **av)
{
	t_pushswap	pw;

	if (ac == 1)
		return (0);
	ft_check_integer(ac, av, &pw);
	ft_stack_num(ac, av, &pw);
	ft_check_unique(&pw);
	ft_check_ascending_order(&pw);
	ft_arrange_num(&pw);
	ft_lst_num(&pw);
	t_list *stack = ft_dupstack(pw.stk_a); // for show
	ft_sorting(&pw);
	ft_showstack(stack, pw.stk_a); // for show
	ft_lstclear(&pw.stk_a, ft_delcont);
}
