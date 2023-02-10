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

#include "push_swap.h"

void	ft_showstack(t_list *tmp, t_list *result)
{
	int	i;

	i = 1;
	while (tmp || result)
	{
		if (tmp)
		{
			printf("%4d):%11d ", i++, *(int *)(tmp->content));
			tmp = tmp->next;
		}
		else
			printf("%4d):            ", i++);
		if (result)
		{
			printf("%11d\n", *(int *)(result->content));
			result = result->next;
		}
		else
			printf("\n");
	}
	printf("        ___________  ___________\n");
	printf("          Before        After   \n");
}

t_list	*ft_dupstack(t_list *lst)
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
