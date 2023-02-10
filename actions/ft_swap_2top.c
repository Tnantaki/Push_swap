/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_2top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:52:27 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:52:28 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actft.h"

void	ft_sa(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *lst_a;
	tmp_b = *lst_b;
	*lst_a = (*lst_a)->next;
	*lst_b = (*lst_b)->next;
	tmp_a->next = (*lst_a)->next;
	tmp_b->next = (*lst_b)->next;
	(*lst_a)->next = tmp_a;
	(*lst_b)->next = tmp_b;
	write(1, "ss\n", 3);
}
