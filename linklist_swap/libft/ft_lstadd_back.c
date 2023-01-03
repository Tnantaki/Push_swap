/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:07:06 by tnantaki          #+#    #+#             */
/*   Updated: 2022/09/22 10:38:12 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
}

//(lst) is adress of *lst;
//(*lst) is adress of content in the first node;
//((*lst)->content) use this for represent value instead of (**lst);
// temp = *lst // make temp point to the same as node as lst point;
/*
int	main(void)
{
	t_list *head;
	char *str1 = "Pepo01";
	char *str2 = "Pepo02";
	char *str3 = "Pepo03";
	int a = 20;
	int *b = &a;
	printf("%d", *b);

	// printf("str1:%s\n", str1);
	// printf("head @:%p\n", &head);
	// printf("*head @:%p\n", &(*head));
	// printf("head->con @:%p\n", &(head->content));
	// printf("head->nex @:%p\n", &(head->next));
	head = ft_lstnew(20);
	// printf("%s", (char *)head->content);
	// ft_lstadd_back(&head, ft_lstnew(str2));
	// ft_lstadd_back(&head, ft_lstnew(str3));
	// while (head)
	// {
	// 	printf("%s, ", (char *)head->content);
	// 	head = head->next;
	// }
}
*/