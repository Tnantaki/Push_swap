/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:51:48 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:51:51 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswft.h"

void ft_show2stack(t_list *tmp, t_list *result)
{
	int	i;

	i = 1;
	while (tmp)
	{
		printf("[%d]:%11d  %11d\n", i++, *(int *)(tmp->content), *(int *)(result->content));
		tmp = tmp->next;
		result = result->next;
	}
	printf("    ___________  ___________\n");
	printf("      Before        After   \n");
}

void ft_showstack(t_list *tmp)
{
	int	i;

	i = 1;
	printf("---------------------\n");
	while (tmp)
	{
		printf("[%d]:%d \n", i++, *(int *)(tmp->content));
		tmp = tmp->next;
	}
}

t_list *ft_dupstack(t_list *lst)
{
	t_list	*tmp;
	int		*num;

	tmp = NULL;
	while (lst)
	{
		num = (int *)malloc(sizeof(int));
		*num = *(int *)(lst->content);
		ft_lstadd_back(&tmp, ft_lstnew(num));
		lst = lst->next;
	}
	return (tmp);
}
