/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a_lot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:50:34 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/17 20:56:42 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_mm(int *min, int *max, t_list **stack)
{
	t_list	*tmp;
	int		count;

	count = 1;
	tmp = *stack;
	*max = *(int *)tmp->content;
	*min = *(int *)tmp->content;
	while (tmp->next != NULL)
	{
		if (*(int *)tmp->next->content > *max)
			*max = *(int *)tmp->next->content;
		if (*(int *)tmp->next->content < *min)
			*min = *(int *)tmp->next->content;
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	ft_sway_rev(t_list **stack, int n)
{
	t_list	*tmp;
	int		i;
	int		mm[2];
	int		count;

	i = 0;
	count = ft_get_mm(&mm[0], &mm[1], stack);
	tmp = ft_lstlast(*stack);
	if ((*(int *)(*stack)->content > *(int *)tmp->content && (n < mm[0]
			|| n > mm[1])) || (*(int *)(*stack)->content < n
				&& *(int *)tmp->content > n))
		return (0);
	tmp = *stack;
	while (tmp != NULL && ++i)
	{
		if ((*(int *)tmp->content > n && *(int *)tmp->next->content < n)
			|| (*(int *)tmp->content == mm[0] && (n < mm[0] || n > mm[1])))
		{
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
		way = ft_sway_rev(stack_b, *(int *)(*stack_a)->content);
		if (way > 0)
			while (way-- > 0)
				ft_rotate_b(stack_b);
		else if (way < 0)
			while (way++ < 0)
				ft_reverse_rotate_b(stack_b);
		ft_push_b(stack_a, stack_b);
	}
}

void	ft_sort_a_lot(t_list **stack_a, t_list **stack_b, int count)
{
	int	stack_count;
	int	stack_c_items;
	int	i;

	i = 0;
	stack_count = 2;
	stack_c_items = count / stack_count;
	ft_push_sort(stack_a, stack_b, stack_c_items);
	ft_print_stacks(stack_a, stack_b);
	ft_get_highest_top_rev(stack_b);
	ft_print_stacks(stack_a, stack_b);
	ft_sort_until_five(stack_a, stack_b, stack_c_items);
	ft_print_stacks(stack_a, stack_b);
	ft_merge_sorted_stacks(stack_a, stack_b, stack_c_items);
	ft_print_stacks(stack_a, stack_b);
	ft_get_highest_top(stack_a);
}

void	ft_get_highest_top_rev(t_list **stack)
{
	int	way;

	way = ft_sway_rev(stack, 2147483647);
	if (way > 0)
		while (way-- > 0)
			ft_rotate_b(stack);
	else if (way < 0)
		while (way++ < 0)
			ft_reverse_rotate_b(stack);
}
