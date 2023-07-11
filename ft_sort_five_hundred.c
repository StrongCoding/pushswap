/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five_hundred.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:58:02 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/11 12:25:11 by dnebatz          ###   ########.fr       */
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
	stack_count = 2;
	while (j++ < stack_count - 1)
	{
		ft_push_sort_not_reverse(stack_a, stack_b, potion_size);
		ft_get_highest_top_rev(stack_b);
		i = 0;
		while (i++ < potion_size)
		{
			ft_push_a(stack_b, stack_a);
			ft_rotate_a(stack_a);
		}
	}
	ft_push_sort_not_reverse(stack_a, stack_b, potion_size);
	ft_get_highest_top_rev(stack_b);
	//ft_merge_sorted_potions(stack_a, stack_b, potion_size);
	ft_print_stacks(stack_a, stack_b);
}

void	ft_merge_sorted_potions(t_list **stack_a, t_list **stack_b, int potion_count)
{
	int	i;
	int	way;
	int	j;

	i = 0;
	j = 0;
	while (i++ < potion_count)
	{
		way = ft_get_shortest_potion_way(stack_a, *(int *)(*stack_b)->content, potion_count);
		while (way-- > 0)
		{
			ft_rotate_a(stack_a);
			j++;
		}
		ft_push_a(stack_b, stack_a);
	}
	while (j++ < potion_count)
		ft_rotate_a(stack_a);
}

int	ft_get_shortest_potion_way(t_list **stack, int number, int potion_count)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (i++ > potion_count)
	{
		if ((*(int *)tmp->content < number))
		{
			if (DEBUG)
				printf("way found i: %i\n", i);
			return (i);
		}
		tmp = tmp->next;
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
	//ft_get_highest_top_rev(stack_b);
	// i = 0;
	// while (i++ < stack_c_items)
	// 	ft_push_a(stack_b, stack_a);
}