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

#include "pswft.h"

int	ft_isinteger(int ac, char **av)
{
	char	**arg;
	int		size;
	int		i;
	int		j;
	
	i = 1;
	size = 0;
	while (i < ac)
	{
		j = 0;
		arg = ft_split(av[i], ' ');
		if (!arg[0])
			ft_prterr(arg);
		while (arg[j])
		{
			if (!ft_check_int(arg[j++]))
				ft_prterr(arg);
			size++;
		}
		ft_free2ptr(arg);
		i++;
	}
	if (size <= 1)
		exit (0);
	return (size);
}

void	create_stack(int ac, char **av, t_stack	**sta)
{
	char	**arg;
	int		i;
	int		j;
	int		k;
	
	k = 0;
	i = 1;
	(*sta)->num = malloc(sizeof(int) * (*sta)->size);
	if (!(*sta)->num)
		ft_prterr(NULL);
	while (i < ac)
	{
		j = 0;
		arg = ft_split(av[i], ' ');
		if (!arg)
			ft_prterr(arg);
		while (arg[j])
			(*sta)->num[k++] = atoi(arg[j++]);
		ft_free2ptr(arg);
		i++;
	}
}

int main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;

	sta = malloc(sizeof(t_stack));
	sta->size = ft_isinteger(ac, av);
	create_stack(ac, av, &sta);
	printf("%d \n", sta->size);
	for (int i = 0; i < sta->size; i++)
		printf("%d \n", sta->num[i]);

	// ft_check_err(sta, inf);

	// if (inf.size <= 5)
	// 	ft_case_5(&sta, &stb, inf);
	// ft_lstclear(&sta, ft_delcont);
}
