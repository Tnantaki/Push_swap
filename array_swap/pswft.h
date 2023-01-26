/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswapft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:51:41 by tnantaki          #+#    #+#             */
/*   Updated: 2023/01/12 22:51:43 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWFT_H
# define PSWFT_H

//libft
# include "libft/libft.h"
//action
# include "actions/actft.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct s_stack
{
	int	*num;
	int	size;
//	int	vic;
//	int	max;
}	t_stack;

//number case
//void	ft_case_5(t_list **sta, t_list **stb, t_info inf);

//error check
int		ft_check_int(char *str);
//void	ft_check_err(t_list *stack_a, t_info inf);

//utils
void ft_free2ptr(char **ptr);
void ft_prterr(char **arg);

//showstack
t_list	*ft_dupstack(t_list *lst);
void	ft_showstack(t_list *tmp);
void	ft_show2stack(t_list *tmp, t_list *result);

#endif
