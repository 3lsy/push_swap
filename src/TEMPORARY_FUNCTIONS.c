
#include "push_swap.h"

void	ft_display_doubly(t_doubly *start)
{
	t_doubly	*tmp;
	if (!start)
	{
		ft_putstr_fd("  Empty list\n", 2);
		return ;
	}
	tmp = start;
	printf("  Doubly: [ %d ", *(int *)(start->obj));
	start = start->next;
	while (start != tmp)
	{
		printf("%d ", *(int *)(start->obj));
		start = start->next;
	}
	printf("] size a(%d) b(%d)\n", ft_ps()->a.size, ft_ps()->b.size);
}

void	ft_display_array(t_int *tab, int size)
{
	int i;

	i = 0;
	printf("          Sorted: [ ");
	while (i < size)
		printf("%d ", tab[i++].x);
	printf("]\n");
	i = 0;
	printf("          E     : [ ");
	while (i < size)
		printf("%d ", tab[i++].exists);
	printf("]\n");
}

void	ft_display_op(t_doubly *start)
{
	t_doubly	*tmp;
	if (!start)
	{
		ft_putstr_fd("Empty list\n", 2);
		return ;
	}
	tmp = start;
	printf("Doubly: [ %s ", (char *)start->obj);
	start = start->next;
	while (start != tmp)
	{
		printf("%s ", (char *)start->obj);
		start = start->next;
	}
	printf("]\n");
}
