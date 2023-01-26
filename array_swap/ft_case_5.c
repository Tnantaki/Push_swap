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

#include "pswft.h"

int	ft_find_min(t_list *lst_a, t_info inf)
{
	t_list *tmp;

	inf.i = 1;
	tmp = lst_a;
	lst_a = lst_a->next;
	while (lst_a)
	{
		if (*(int *)tmp->content > *(int *)lst_a->content)
		{
			inf.min = inf.i + 1;
			tmp = lst_a;
		}
		lst_a = lst_a->next;
		inf.i++;
	}
	//printf("min:%d\n", inf.min);
	return (inf.min);
}


void	ft_case_3(t_list **lst, t_info inf)
{
	if (inf.fir > inf.sec && inf.fir < inf.las && inf.sec < inf.las)
		ft_sa(lst);
	else if (inf.fir > inf.sec && inf.fir > inf.las && inf.sec > inf.las)
	{
		ft_sa(lst);
		ft_rra(lst);
	}
	else if (inf.fir > inf.sec && inf.fir > inf.las && inf.sec < inf.las)
		ft_ra(lst);
	else if (inf.fir < inf.sec && inf.fir < inf.las && inf.sec > inf.las)
	{
		ft_sa(lst);
		ft_ra(lst);
	}
	else
		ft_rra(lst);
}

void	ft_pro(t_list **sta, t_list **stb, t_info inf)
{
	if (inf.min <= inf.j / 2)
	{
		while (--inf.min)
			ft_ra(sta);
	}
	else
	{
		while (inf.min++ <= inf.j)
			ft_rra(sta);
	}
	ft_pb(sta, stb);
}

t_info	ft_find_pos(t_list **lst, t_info inf)
{
	inf.j = ft_lstsize(*lst);
	inf.fir = *(int *)((*lst)->content);
	inf.sec = *(int *)(((*lst)->next)->content);
	inf.las = *(int *)(ft_lstlast(*lst)->content);
	return (inf);
}

void	ft_case_5(t_list **sta, t_list **stb, t_info inf)
{
	inf = ft_find_pos(sta, inf);
	if (inf.size == 2)
		ft_sa(sta);
	else if (inf.size == 3)
		ft_case_3(sta, inf);
	else
	{
		inf.i = inf.size - 3;
		while (inf.i--)
		{
			inf.min = ft_find_min(*sta, inf);
			ft_pro(sta, stb, inf);
			inf = ft_find_pos(sta, inf);
		}
		ft_case_3(sta, inf);
		inf.i = inf.size - 3;
		while (inf.i--)
			ft_pa(sta, stb);
	}
}
