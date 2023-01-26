/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bot2top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:52:35 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:54:38 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actft.h"

void	ft_rra(t_list **lst)
{
	t_list	*last;
	t_list	*lstbefore_last;

	last = ft_lstlast(*lst);
	lstbefore_last = ft_lstbefore_last(*lst);
	lstbefore_last->next = NULL;
	ft_lstadd_front(lst, last);
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_list **lst)
{
	t_list	*last;
	t_list	*lstbefore_last;

	last = ft_lstlast(*lst);
	lstbefore_last = ft_lstbefore_last(*lst);
	lstbefore_last->next = NULL;
	ft_lstadd_front(lst, last);
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_list **lst_a, t_list **lst_b)
{
	t_list	*last_a;
	t_list	*last_b;
	t_list	*lstbefore_last_a;
	t_list	*lstbefore_last_b;

	last_a = ft_lstlast(*lst_a);
	last_b = ft_lstlast(*lst_b);
	lstbefore_last_a = ft_lstbefore_last(*lst_a);
	lstbefore_last_b = ft_lstbefore_last(*lst_b);
	lstbefore_last_a->next = NULL;
	lstbefore_last_b->next = NULL;
	ft_lstadd_front(lst_a, last_a);
	ft_lstadd_front(lst_b, last_b);
	ft_putstr_fd("rrr\n", 1);
}
