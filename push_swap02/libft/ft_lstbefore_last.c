/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbefore_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:57:50 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:57:51 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstbefore_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while ((lst->next)->next != NULL)
		lst = lst->next;
	return (lst);
}
