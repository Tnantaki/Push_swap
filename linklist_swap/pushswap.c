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

#include "pushswapft.h"

t_list *ft_lstnum(int ac, char **av, t_list *lst, t_info inf)
{
	inf.i = 1;
	while (inf.i < ac)
	{
		inf.j = 0;
		inf.arg = ft_split(av[inf.i], ' ');
		if (!inf.arg[0])
			ft_prterr(lst, inf);
		while (inf.arg[inf.j])
		{
			inf.nb = (int *)malloc(sizeof(int));
			if (!(ft_check_int(inf.arg[inf.j])) || !inf.nb)
				ft_prterr(lst, inf);
			*(inf.nb) = ft_atoi(inf.arg[inf.j]);
			ft_lstadd_back(&lst, ft_lstnew(inf.nb));
			inf.j++;
		}
		ft_double_free(inf.arg);
		inf.i++;
	}
	return (lst);
}

t_info	ft_set_fmt(t_list **sta, t_list **stb, t_info inf)
{
	*sta = NULL;
	*stb = NULL;
	inf.i = 0;
	inf.j = 0;
	inf.size = 0;
	inf.min = 0;
	inf.sec = 0;
	inf.las = 0;
	inf.nb = NULL;
	return (inf);
}

int main(int ac, char **av)
{
	t_list	*sta;
	t_list	*stb;
	//t_list	*stack; //for show
	t_info	inf;

	if (ac == 1)
		exit(0);
	inf = ft_set_fmt(&sta, &stb, inf);
	sta = ft_lstnum(ac, av, sta, inf);
	inf.size = ft_lstsize(sta);
	ft_check_err(sta, inf);
	//stack = ft_dupstack(sta); // for show
	if (inf.size <= 5)
		ft_case_5(&sta, &stb, inf);
	//ft_showstack(stack, sta); // for show
	ft_lstclear(&sta, ft_delcont);
}
