/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_lot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:39:33 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/18 17:20:20 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_highest_top(t_list **stack)
{
	int	way;

	way = ft_get_shortest_way(stack, 2147483647);
	if (way > 0)
		while (way-- > 0)
			ft_rotate_a(stack);
	else if (way < 0)
		while (way++ < 0)
			ft_reverse_rotate_a(stack);
}

void	ft_merge_sorted_stacks(t_list **stack_a, t_list **stack_b, int count)
{
	int	i;
	int	way;

	i = 0;
	while (i++ < count)
	{
		way = ft_get_shortest_way(stack_a, *(int *)(*stack_b)->content);
		if (way > 0)
			while (way-- > 0)
				ft_rotate_a(stack_a);
		else if (way < 0)
			while (way++ < 0)
				ft_reverse_rotate_a(stack_a);
		ft_push_a(stack_b, stack_a);
	}
}
