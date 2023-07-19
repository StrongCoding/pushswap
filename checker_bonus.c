/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:44:42 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/19 09:50:45 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_statement(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (!ft_strncmp("sa\n", s, len))
		ft_printf("ist sa\n");
	else if (!ft_strncmp("sb\n", s, len))
		ft_printf("ist sb\n");
	else if (!ft_strncmp("pa\n", s, len))
		ft_printf("ist pa\n");
	else if (!ft_strncmp("pb\n", s, len))
		ft_printf("ist pa\n");
	else if (!ft_strncmp("ra\n", s, len))
		ft_printf("ist ra\n");
	else if (!ft_strncmp("rb\n", s, len))
		ft_printf("ist rb\n");
	else if (!ft_strncmp("rra\n", s, len))
		ft_printf("ist rra\n");
	else if (!ft_strncmp("rrb\n", s, len))
		ft_printf("ist rrb\n");
	else
		write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*input;
	t_list	*stack_a;
	t_list	*stack_b;
	int		count;

	count = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else if (ft_fill_s(&stack_a, argc, argv, &count))
		write(2, "Error\n", 6);
	else if (count < 2)
		write(2, "Error\n", 6);
	else if (ft_check_sorted(&stack_a))
		return (0);
	else if (!ft_check_double(&stack_a))
		write(2, "Error\n", 6);
	else
	{
		input = get_next_line(0);
		while (input && *input != '\n')
		{
			ft_check_statement(input);
			input = get_next_line(0);
		}
		free(input);
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}

// cc checker_bonus.c libftprintf.a errors.c others.c ft_atoi_special.c 