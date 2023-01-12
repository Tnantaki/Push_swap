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
typedef struct s_num
{
	int nb;
	int pot;
}	t_num;

typedef struct s_info
{
	t_num *num;
	int size;
	int min;
	int vice;
	int max;
}	t_info;

//number case
void	ft_case_3(t_list **lst);
int		ft_check_int(char *str);
int		ft_check_order(t_list *lst);

//showstack
t_list	*ft_dupstack(t_list *lst);
void	ft_showstack(t_list *tmp, t_list *result);
#endif