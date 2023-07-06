/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a_lot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:50:34 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/06 09:50:27 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_shortest_way(t_list **stack, int number)
{
	t_list	*tmp;
	int		i;
	int		way;
	int		way_set;

	way_set = 0;
	i = 0;
	way = 0;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	printf("erstes element ist: %i < number: %i und < %i letztes element\n", (*(int *)(*stack)->content), number, *(int *)tmp->content);
	if (!(*(int *)(*stack)->content < number && number < *(int *)tmp->content))
	{
		tmp = *stack;
		printf("way soll gesucht werden!\n");
	}
	else
	{
		tmp = NULL;
		printf("tmp null also way 0 also erste Stelle!\n");
	}
	while (tmp != NULL)
	{
		if (!(tmp->next == NULL))
			printf("content: %i <= number: %i next: %i >= number: %i\n", *(int *)tmp->content, number, *(int *)tmp->next->content, number);
		else
			printf("content: %i <= number: %i\n", *(int *)tmp->content, number);
		if (!(tmp->next == NULL) && !(way_set) && (
			(*(int *)tmp->content >= number && *(int *)tmp->next->content <= number) ||
			(*(int *)tmp->content < *(int *)tmp->next->content && *(int *)tmp->next->content < number)
			)
			)
		// wenn number größer als aktuelle und größer als nächste
		{
			printf("way found i: %i\n", i);
			way = i;
			way_set = 1;
		}
		tmp = tmp->next;
		i++;
	}
	printf("way: %i i: %i way after: %i\n", way, i, (i - way) * -1);
	if (way < i - way)
		return (way);
	else
		return ((i - way) * -1);
}

void	ft_push_sort(t_list **stack_a, t_list **stack_b, int stack_c_items)
{
	int	i;
	int	j;
	int	way;

	j = 0;
	i = 2;
	ft_push_b(stack_a, stack_b);
	ft_push_b(stack_a, stack_b);
	//if (*(int *)(*stack_b)->content < *(int *)(*stack_b)->next->content)
	//	ft_rotate_b(stack_b);
	while (i++ < stack_c_items)
	{
		printf("if : %i < %i\n",*(int *)(*stack_a)->content, *(int *)(*stack_b)->content);
		way = ft_get_shortest_way(stack_b, *(int *)(*stack_a)->content);
		printf("way %i\n", way);
		if (way > 0)
		{
			while (way-- > 0)
				ft_reverse_rotate_b(stack_b);
		}
		else if (way < 0)
		{
			while (way++ < 0)
				ft_rotate_b(stack_b);
		}
		ft_push_b(stack_a, stack_b);
		ft_print_stacks(stack_a, stack_b);
	}
	way = ft_get_shortest_way(stack_b, 2147483647);
	printf("way: %i\n", way);
	if (way > 0)
	{
		while (way-- > 0)
			ft_reverse_rotate_b(stack_b);
	}
	else if (way < 0)
	{
		while (way++ < 0)
			ft_rotate_b(stack_b);
	}
	i = 0;
	while (i++ < stack_c_items)
		ft_push_a(stack_b, stack_a);
}

void	ft_sort_a_lot(t_list **stack_a, t_list **stack_b, int count)
{
	int	stack_count;
	int	stack_c_items;
	int	i;

	i = 0;
	stack_count = 1;
	stack_c_items = count / stack_count;
	ft_push_sort(stack_a, stack_b, stack_c_items);
	//ft_push_sort(stack_a, stack_b, count);
}
