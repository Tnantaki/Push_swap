/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:53:27 by tnantaki          #+#    #+#             */
/*   Updated: 2023/02/13 19:53:31 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sorting(t_pushswap *pw)
{
	if (pw->size == 2)
		ft_sa(&pw->stk_a);
	else if (pw->size == 3)
		ft_case_3(pw);
	else if (pw->size <= 12)
		ft_case_5(pw);
	else
		ft_radix_sort(pw);
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
	ft_sorting(&pw);
	ft_lstclear(&pw.stk_a, ft_delcont);
}
