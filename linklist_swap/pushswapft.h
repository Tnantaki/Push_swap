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

//number case
int     ft_check_int(char *str);
int     ft_check_order(t_list *lst);
void    ft_case_3(t_list **lst);

//showstack
void    ft_showstack(t_list *tmp);
#endif