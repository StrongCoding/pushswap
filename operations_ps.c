/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:47:59 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/05 10:13:49 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	ft_swap_a(t_list **stack)
{
	ft_swap(stack);
	write(1, "sa\n", 3);
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	ft_swap_b(t_list **stack)
{
	ft_swap(stack);
	write(1, "sb\n", 3);
}

// ss : sa and sb at the same time.
void	ft_swap_s(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	ft_push_a(t_list **stack)
{
	ft_push(stack);
	write(1, "pa\n", 3);
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	ft_push_b(t_list **stack)
{
	ft_push(stack);
	write(1, "pb\n", 3);
}
