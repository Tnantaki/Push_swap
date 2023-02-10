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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "actions/actft.h"
# include <unistd.h>
# include <stdlib.h>

# include <fcntl.h>
# include <stdio.h>

# define DIGIT_ERR 1
# define UNIQUE_ERR 2

typedef struct s_pushswap
{
	t_list	*stk_a;
	int		size_a;
	t_list	*stk_b;
	// int		size_b;
	char	**arg;
	int		*nb;
	int		*arr;
	int		size;
	int		top;
	int		vic;
	int		bot;
	int		min_i;
}	t_pushswap;

typedef struct s_chunk
{
	t_list	*tmp;
	int		i;
	int		chunk;
	int		range;
	int		half;
	int		tob_i;
	int		bot_i;
}	t_chunk;


//Check argument
void	ft_check_integer(int ac, char **av, t_pushswap *pw);
void	ft_stack_num(int ac, char **av, t_pushswap *pw);
void	ft_check_unique(t_pushswap *pw);
void	ft_check_ascending_order(t_pushswap *pw);
//utils
void ft_double_free(char **ptr);
void ft_prterr(t_pushswap *pw, int err);
//number case
void	ft_sorting(t_pushswap *pw);

//showstack
t_list	*ft_dupstack(t_list *lst);
void	ft_showstack(t_list *tmp, t_list *result);

#endif
