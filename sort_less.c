/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:23:16 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/10 14:51:25 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_shortest_way(t_list **stack, int number)
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

void	ft_sort_three(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (*(int *)tmp->next->content < *(int *)tmp->content && *(int *)tmp->next->content < *(int *)tmp->next->next->content)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->next->content)
			ft_swap_a(stack);
		else
			ft_rotate_a(stack);
	}
	else if (*(int *)tmp->next->content > *(int *)tmp->content && *(int *)tmp->next->content > *(int *)tmp->next->next->content)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->next->content)
		{
			ft_reverse_rotate_a(stack);
			ft_swap_a(stack);
		}
		else
			ft_reverse_rotate_a(stack);
	}
	else if (*(int *)tmp->next->content > *(int *)tmp->next->next->content)
	{
		ft_rotate_a(stack);
		ft_swap_a(stack);
	}
}

void	ft_sort_until_five(t_list **stack_a, t_list **stack_b, int count)
{
	int	push_count;
	int	i;
	int	way;

	push_count = count - 3;
	i = 0;
	while (i++ < push_count)
		ft_push_a(stack_a, stack_b);
	ft_sort_three(stack_a);
	i = 0;
	ft_print_stacks(stack_a, stack_b);
	while (i++ <= push_count)
	{
		way = ft_get_shortest_way(stack_a, *(int *)(*stack_b)->content);
		printf("way: %i content b: %i\n", way, *(int *)(*stack_b)->content);
	}
	// if (push_count == 1)
	// {
	// 	if (*(int *)(*stack_b)->content < *(int *)(*stack_a)->content)
	// 		ft_push(stack_b, stack_a);
	// 	else if (*(int *)(*stack_b)->content > *(int *)(*stack_a)->next->next->content)
	// 	{
	// 		ft_push(stack_b, stack_a);
	// 		ft_rotate(stack_a);
	// 	}
	// }
}
