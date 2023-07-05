/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:12:50 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/05 10:12:52 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ft_rotate_a(t_list **stack)
{
	ft_rotate(stack);
	write(1, "ra\n", 3);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	ft_rotate_b(t_list **stack)
{
	ft_rotate(stack);
	write(1, "rb\n", 3);
}

// rr : ra and rb at the same time.
void	ft_rotate_r(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	ft_reverse_rotate_a(t_list **stack)
{
	ft_reverse_rotate(stack);
	write(1, "rra\n", 4);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	ft_reverse_rotate_b(t_list **stack)
{
	ft_reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

// rrr : rra and rrb at the same time.
void	ft_reverse_rotate_r(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
