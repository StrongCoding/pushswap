/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:23:16 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/05 10:39:16 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	push_count = count - 3;
	i = 0;
	while (i++ < push_count)
		ft_push(stack_a, stack_b);
	ft_sort_three(stack_a);
	i = 0;
	if (push_count == 1)
	{
		if (*(int *)(*stack_b)->content < *(int *)(*stack_a)->content)
			ft_push(stack_b, stack_a);
		else if (*(int *)(*stack_b)->content > *(int *)(*stack_a)->next->next->content)
		{
			ft_push(stack_b, stack_a);
			ft_rotate(stack_a);
		}
	}
}
