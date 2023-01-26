/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_top2bot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:52:43 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:54:57 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actft.h"

void	ft_ra(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstadd_back(lst, tmp);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *lst_a;
	tmp_b = *lst_b;
	*lst_a = (*lst_a)->next;
	*lst_b = (*lst_b)->next;
	tmp_a->next = NULL;
	tmp_b->next = NULL;
	ft_lstadd_back(lst_a, tmp_a);
	ft_lstadd_back(lst_b, tmp_b);
	ft_putstr_fd("rr\n", 1);
}
