/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a_lot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:50:34 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/05 09:57:42 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a_lot(t_list **stack_a, t_list **stack_b, int count)
{
	int	stack_count;
	int	stack_c_items;
	int	i;

	i = 0;
	stack_count = 3;
	stack_c_items = count / stack_count;
	ft_push_sort(stack_a, stack_b, stack_c_items);
}

void	ft_push_sort(t_list **stack_a, t_list **stack_b, int stack_c_items)
{
	int	i;

	i = 0;
	ft_push
	while (i++ < stack_c_items)
		{
			
		}
}
