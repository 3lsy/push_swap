
#include "push_swap.h"

void	ft_display_doubly(t_doubly *start)
{
	t_doubly	*tmp;
	if (!start)
	{
		ft_putstr_fd("Empty list", 2);
		return ;
	}
	tmp = start;
	printf("Doubly: [ %d ", *(int *)(start->obj));
	start = start->next;
	while (start != tmp)
	{
		printf("%d ", *(int *)(start->obj));
		start = start->next;
	}
	printf("]\n");
}

void	ft_display_array(int *tab, int size)
{
	int i;

	i = 0;
	printf("Sorted: [ ");
	while (i < size)
		printf("%d ", tab[i++]);
	printf("]\n");
}
