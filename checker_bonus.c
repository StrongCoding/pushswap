/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:44:42 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/19 18:40:35 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_sorted_print(int *error, t_list **stack_a, t_list **stack_b)
{
	if (*error / 10)
		write(2, "Error\n", 6);
	else if (ft_lstsize(*stack_b))
		write(1, "KO\n", 4);
	else if (ft_check_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ft_double_commands(char *s, t_list **stack_a, t_list **stack_b, int len)
{
	if (!ft_strncmp("ss\n", s, len))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else if (!ft_strncmp("rr\n", s, len))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else if (!ft_strncmp("rrr\n", s, len))
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
}

int	ft_check_statement(char *s, int *error, t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_strlen(s);
	if (!ft_strncmp("sa\n", s, len))
		ft_swap(stack_a);
	else if (!ft_strncmp("sb\n", s, len))
		ft_swap(stack_b);
	else if (!ft_strncmp("pa\n", s, len))
		ft_push(stack_b, stack_a);
	else if (!ft_strncmp("pb\n", s, len))
		ft_push(stack_a, stack_b);
	else if (!ft_strncmp("ra\n", s, len))
		ft_rotate(stack_a);
	else if (!ft_strncmp("rb\n", s, len))
		ft_rotate(stack_b);
	else if (!ft_strncmp("rra\n", s, len))
		ft_reverse_rotate(stack_a);
	else if (!ft_strncmp("rrb\n", s, len))
		ft_reverse_rotate(stack_b);
	else if (!ft_strncmp("rr\n", s, len) || !ft_strncmp("rrr\n", s, len) || 
		!ft_strncmp("ss\n", s, len))
		ft_double_commands(s, stack_a, stack_b, len);
	else
		*error += 10;
	return (0);
}

void	ft_get_inputs(int *error, t_list **stack_a, t_list **stack_b)
{
	char	*input;

	input = NULL;
	input = get_next_line(0);
	while (input && *input != '\n')
	{
		ft_check_statement(input, error, stack_a, stack_b);
		free(input);
		input = get_next_line(0);
	}
	free(input);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		count;
	int		error;

	error = 0;
	count = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else if (ft_fill_s(&stack_a, argc, argv, &count))
		error += 10;
	else if (count < 2 || !ft_check_double(&stack_a))
		error += 10;
	else if (ft_check_sorted(&stack_a))
	{
		ft_free_stacks(&stack_a, &stack_b);
		return (0);
	}
	else
		ft_get_inputs(&error, &stack_a, &stack_b);
	ft_check_sorted_print(&error, &stack_a, &stack_b);
	ft_free_stacks(&stack_a, &stack_b);
}
