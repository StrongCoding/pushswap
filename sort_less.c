/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:23:16 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/17 17:48:46 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if the position is already right
int	ft_check_right_pos(t_list **stack, int n)
{
	t_list	*tmp;
	int		mm[2];
	int		count;

	count = ft_get_mm(&mm[0], &mm[1], stack);
	tmp = ft_lstlast(*stack);
	if ((*(int *)(*stack)->content < *(int *)tmp->content && (n < mm[0] || 
			n > mm[1])) || (*(int *)(*stack)->content > n && 
			*(int *)tmp->content < n))
		return (1);
	else
		return (0);
}

// 
int	ft_get_shortest_way(t_list **stack, int n)
{
	t_list	*tmp;
	int		i;
	int		mm[2];
	int		count;

	i = 0;
	count = ft_get_mm(&mm[0], &mm[1], stack);
	if (ft_check_right_pos(stack, n))
		return (0);
	tmp = *stack;
	while (tmp != NULL && ++i)
	{
		if (!(tmp->next == NULL))
		{
			if ((*(int *)tmp->content < n && *(int *)tmp->next->content > n) || 
				(*(int *)tmp->content == mm[1] && (n < mm[0] || n > mm[1])))
			{
				if (i > count - i)
					return ((count - i) * -1);
				return (i);
			}
			tmp = tmp->next;
		}
	}
	return (0);
}

// hard coded sorting three in shortest way
void	ft_sort_three(t_list *stack)
{
	if (*(int *)stack->next->content < *(int *)stack->content && 
		*(int *)stack->next->content < *(int *)stack->next->next->content)
	{
		if (*(int *)stack->content < *(int *)stack->next->next->content)
			ft_swap_a(&stack);
		else
			ft_rotate_a(&stack);
	}
	else if (*(int *)stack->next->content > *(int *)stack->content && 
		*(int *)stack->next->content > *(int *)stack->next->next->content)
	{
		if (*(int *)stack->content < *(int *)stack->next->next->content)
		{
			ft_reverse_rotate_a(&stack);
			ft_swap_a(&stack);
		}
		else
			ft_reverse_rotate_a(&stack);
	}
	else if (*(int *)stack->next->content > *(int *)stack->next->next->content)
	{
		ft_rotate_a(&stack);
		ft_swap_a(&stack);
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
		ft_push_b(stack_a, stack_b);
	ft_sort_three(*stack_a);
	i = 0;
	while (i++ < push_count)
	{
		way = ft_get_shortest_way(stack_a, *(int *)(*stack_b)->content);
		ft_process_way_a(stack_a, way);
		ft_push_a(stack_b, stack_a);
	}
	way = ft_get_shortest_way(stack_a, 2147483647);
	ft_process_way_a(stack_a, way);
}

void	ft_process_way_a(t_list **stack, int way)
{
	if (way > 0)
		while (way-- > 0)
			ft_rotate_a(stack);
	else if (way < 0)
		while (way++ < 0)
			ft_reverse_rotate_a(stack);
}
