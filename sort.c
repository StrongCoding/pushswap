/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:23:16 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/04 21:22:22 by dnebatz          ###   ########.fr       */
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
		{
			ft_swap(stack);
			printf("sa\n");
		}
		else
		{
			ft_rotate(stack);
			printf("ra\n");
		}
	}
	else if (*(int *)tmp->next->content > *(int *)tmp->content && *(int *)tmp->next->content > *(int *)tmp->next->next->content)
	{
		if (*(int *)tmp->content < *(int *)tmp->next->next->content)
		{
			ft_reverse_rotate(stack);
			printf("rra\n"); //remove printf
			ft_swap(stack);
			printf("sa\n");
		}
		else
		{
			ft_reverse_rotate(stack);
			printf("ra\n");
		}
	}
	else if (*(int *)tmp->next->content > *(int *)tmp->next->next->content)
	{
		ft_rotate(stack);
		printf("ra\n"); //remove printf
		ft_swap(stack);
		printf("sa\n");
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
	if (push_count == 1)
	{
	if (**((int **)(*stack_a)->content) == 7)
			printf("ist gleich\n");
	}
}

void	ft_sort_a_lot(t_list **stack_a, t_list **stack_b, int count)
{
	int	stack_count;

	stack_count = count / 3;
}