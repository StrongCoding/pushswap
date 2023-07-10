/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a_lot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:50:34 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/10 11:42:07 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_shortest_way(t_list **stack, int number)
{
	t_list	*tmp;
	int		i;
	int		way;
	int		way_set;
	int		highest;
	int		lowest;

	way_set = 0;
	i = 1;
	way = 1;
	tmp = *stack;
	highest = *(int *)tmp->content;
	lowest = *(int *)tmp->content;
	while (tmp->next != NULL)
	{
		if (*(int *)tmp->next->content > highest)
			highest = *(int *)tmp->next->content;
		if (*(int *)tmp->next->content < lowest)
			lowest = *(int *)tmp->next->content;
		tmp = tmp->next;
	}
	//printf("highest: %i\n", highest);
	//printf("erstes element ist: %i < number: %i und < %i letztes element\n", (*(int *)(*stack)->content), number, *(int *)tmp->content);
	// wenn größte oben und noch größere gepusht werden soll
	if ((number > highest && *(int *)(*stack)->content == highest) || (number < lowest && *(int *)(*stack)->content == lowest)
	|| (*(int *)(*stack)->content < number && number < *(int *)tmp->content))
	{
		if (DEBUG)
			printf("highest oder lowest ist oben also way 0!\n");
		return (0);
	}
	tmp = *stack;
	// if (!(*(int *)(*stack)->content < number && number < *(int *)tmp->content))
	// {
	// 	tmp = *stack;
	// 	if (DEBUG)
	// 		printf("way soll gesucht werden!\n");
	// }
	// else
	// {
	// 	if (DEBUG)
	// 		printf("tmp null also way 0 also erste Stelle!\n");
	// 	return (0);
	// }
	while (tmp != NULL)
	{
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
		if (!(tmp->next == NULL) && !(way_set) && (
			(*(int *)tmp->content >= number && *(int *)tmp->next->content <= number) || 
			(number > highest && *(int *)tmp->next->content == highest) || 
			(number < lowest && *(int *)tmp->next->content == lowest)
			))
		// wenn number größer als aktuelle und größer als nächste
		// aktuelle ist kleiner als nächste und nächste ist kleiner als number
		{
			if (DEBUG)
				printf("way found i: %i\n", i);
			return (i);
		}
		tmp = tmp->next;
		i++;
	}
	//printf("way: %i i: %i way after: %i\n", way, i, (i - way) * -1);
	return (-1);
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
	while (i++ < stack_c_items)
	{
		way = ft_get_shortest_way(stack_b, *(int *)(*stack_a)->content);
		if (DEBUG)
			printf("way %i\n", way);
		if (way > 0)
		{
			while (way-- > 0)
				ft_rotate_b(stack_b);
		}
		else if (way < 0)
		{
			while (way++ < 0)
				ft_rotate_b(stack_b);
		}
		ft_push_b(stack_a, stack_b);
		if (DEBUG == 1)
			ft_print_stacks(stack_a, stack_b);
	}
	way = ft_get_shortest_way(stack_b, 2147483647);
	if (DEBUG)
		printf("way: %i\n", way);
	if (way > 0)
	{
		while (way-- > 0)
			ft_rotate_b(stack_b);
	}
	else if (way < 0)
	{
		while (way++ < 0)
			ft_reverse_rotate_b(stack_b);
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
}
