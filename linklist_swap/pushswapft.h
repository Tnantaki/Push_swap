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

#ifndef PUSHSWAPFT_H
# define PUSHSWAPFT_H

//libft
# include "libft/libft.h"
//action
# include "actions/actft.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct s_info
{
	char	**arg;
	int		i;
	int		j;
	int		*nb;
	int		size;
	int		min;
	int		fir;
	int		sec;
	int		las;
//	int	vic;
//	int	max;
}	t_info;

//number case
void	ft_case_5(t_list **sta, t_list **stb, t_info inf);
//error check
int		ft_check_int(char *str);
void	ft_check_err(t_list *stack_a, t_info inf);
//utils
void ft_double_free(char **ptr);
//void ft_prterr(t_list *lst, char **arg, int *tmp_nb);
void ft_prterr(t_list *lst, t_info inf);

//showstack
t_list	*ft_dupstack(t_list *lst);
void	ft_showstack(t_list *tmp, t_list *result);
#endif
