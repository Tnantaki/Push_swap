#include "pushswapft.h"

void ft_showstack(t_list *tmp, t_list *result)
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