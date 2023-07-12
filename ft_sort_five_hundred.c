/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_hundred.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:58:02 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/12 16:50:41 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five_hundred(t_list **stack_a, t_list **stack_b, int count)
{
	int	potion_size;
	int	i;
	int	j;
	int	stack_count;

	i = 0;
	j = 0;
	potion_size = 50;
	stack_count = 10;
	while (j++ < stack_count - 1)
	{
		ft_push_sort(stack_a, stack_b, potion_size);
		ft_get_highest_top_rev(stack_b);
		i = 0;
		while (i++ < potion_size)
		{
			ft_push_a(stack_b, stack_a);
			ft_rotate_a(stack_a);
		}
	}
	i = 0;
	ft_push_sort(stack_a, stack_b, potion_size);
	ft_get_highest_top_rev(stack_b);
	while (i++ < stack_count - 1)
		ft_merge_sorted_potions(stack_a, stack_b, potion_size);
	i = 0;
	while (i++ < count)
		ft_push_a(stack_b, stack_a);
	//ft_print_stacks(stack_a, stack_b);
}

void	ft_merge_sorted_potions(t_list **stack_a, t_list **stack_b, int potion_count)
{
	int	i;
	int	way;

	i = 0;
	while (i++ < potion_count)
	{
		way = ft_get_shortest_potion_way(stack_b, *(int *)(*stack_a)->content, potion_count);
		//printf("way: %i\n", way);
		while (way > 0)
		{
			ft_rotate_b(stack_b);
			way--;
		}
		ft_push_b(stack_a, stack_b);
		if (way == -1)
		{
			ft_reverse_rotate_b(stack_b);
		}
	}
	ft_get_highest_top_rev(stack_b);
}

int	ft_get_shortest_potion_way(t_list **stack, int number, int potion_count)
{
	t_list	*tmp;
	int		i;
	int		lowest;

	tmp = *stack;
	lowest = *(int *)tmp->content;
	while (tmp->next != NULL)
	{
		if (*(int *)tmp->next->content < lowest)
			lowest = *(int *)tmp->next->content;
		tmp = tmp->next;
	}
	i = 0;
	tmp = *stack;
	// wenn kleinste zahl, dann muss die gepuscht werden und way doch negativ also reverserotaten 1x
	//printf("lowest: %i > number %i && content %i == lowest %i\n", lowest, number, *(int *)tmp->content, lowest);
	// if (lowest > number)
	// 	return (-1);
	while (tmp->next != NULL)
	//while (i < potion_count)
	{
		//printf("content %i < number%i\n", *(int *)tmp->content, number);
		//if ((*(int *)tmp->content < number) || *(int *)tmp->content == lowest)
		if (*(int *)tmp->content == lowest && number < lowest)
				return (i + 1);
		if ((*(int *)tmp->content < number))
		{
			if (DEBUG)
				printf("way found i: %i\n", i);
			return (i);
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	ft_push_sort_not_reverse(t_list **stack_a, t_list **stack_b, int stack_c_items)
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
		if (way > 0)
			while (way-- > 0)
				ft_reverse_rotate_b(stack_b);
		else if (way < 0)
			while (way++ < 0)
				ft_rotate_b(stack_b);
		ft_push_b(stack_a, stack_b);
	}
}
