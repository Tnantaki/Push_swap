/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:54:12 by tnantaki          #+#    #+#             */
/*   Updated: 2023/02/13 19:54:14 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "actions/actft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pushswap
{
	t_list	*stk_a;
	int		size_a;
	t_list	*stk_b;
	int		size_b;
	char	**arg;
	int		*nb;
	int		*arr;
	int		size;
	int		minnb_i;
	int		maxnb_i;
}	t_pushswap;

//Check argument
void	ft_check_integer(int ac, char **av, t_pushswap *pw);
void	ft_stack_num(int ac, char **av, t_pushswap *pw);
void	ft_check_unique(t_pushswap *pw);
void	ft_check_ascending_order(t_pushswap *pw);
//List number
void	ft_arrange_num(t_pushswap *pw);
void	ft_lst_num(t_pushswap *pw);
//Case 5
void	ft_case_3(t_pushswap *pw);
void	ft_case_5(t_pushswap *pw);
void	ft_radix_sort(t_pushswap *pw);
//utils
void	ft_double_free(char **ptr);
void	ft_prterr(void);
void	ft_dbfree_prterr(char **ptr);

#endif
