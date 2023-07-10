/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a_lot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:50:34 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/10 14:52:03 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_shortest_way_rev(t_list **stack, int number)
{
	t_list	*tmp;
	int		i;
	int		highest;
	int		lowest;
	int		count;

	i = 0;
	count = 1;
	tmp = *stack;
	highest = *(int *)tmp->content;
	lowest = *(int *)tmp->content;
	while (tmp->next != NULL)
	{
		if (*(int *)tmp->next->content > highest)
			highest = *(int *)tmp->next->content;
		if (*(int *)tmp->next->content < lowest)
			lowest = *(int *)tmp->next->content;
		count++;
		tmp = tmp->next;
	}
	if (DEBUG)
		printf("highest: %i lowest: %i\n", highest, lowest);
	if (*(int *)(*stack)->content > *(int *)tmp->content && (number < lowest || number > highest))
		return (0);
	if (*(int *)(*stack)->content < number && *(int *)tmp->content > number)
		return (0);
	tmp = *stack;
	while (tmp != NULL)
	{
		i++;
		if (!(tmp->next == NULL))
		{
			if (DEBUG)
				printf("content: %i <= number: %i next: %i >= number: %i\n", *(int *)tmp->content, number, *(int *)tmp->next->content, number);
			if (DEBUG)
				printf("aktuelle %i < nächste %i UND nächste %i < number %i\n", *(int *)tmp->content, *(int *)tmp->next->content, *(int *)tmp->next->content, number);
		}	
		else
			if (DEBUG)
				printf("content: %i <= number: %i\n", *(int *)tmp->content, number);
		if ((*(int *)tmp->content > number && *(int *)tmp->next->content < number) || (*(int *)tmp->content == lowest && (number < lowest || number > highest)))
		{
			if (DEBUG)
				printf("way found i: %i count: %i\n", i, count);
			if (i > count - i)
				return ((count - i) * -1);
			return (i);
		}
		tmp = tmp->next;
	}
	return (0);
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
	while (i++ < stack_c_items)
	{
		way = ft_get_shortest_way_rev(stack_b, *(int *)(*stack_a)->content);
		if (way > 0)
			while (way-- > 0)
				ft_rotate_b(stack_b);
		else if (way < 0)
			while (way++ < 0)
				ft_reverse_rotate_b(stack_b);
		ft_push_b(stack_a, stack_b);
	}
	way = ft_get_shortest_way_rev(stack_b, 2147483647);
	if (way > 0)
		while (way-- > 0)
			ft_rotate_b(stack_b);
	else if (way < 0)
		while (way++ < 0)
			ft_reverse_rotate_b(stack_b);
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
}
