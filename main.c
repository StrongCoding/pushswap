/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:37:46 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/03 15:07:31 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	char	**splitted;
	int		error;

	int digit = 7;
	int digit1 = 8;
	int digit2 = 6;
	int digit3 = 1;
	int digit4 = 2;

	error = 0;
	stack_a = NULL;
	stack_b = NULL;
	// stack_a = ft_lstnew(&digit);
	// ft_lstadd_back(&stack_a, ft_lstnew(&digit1));
	// ft_lstadd_back(&stack_a, ft_lstnew(&digit2));
	// ft_lstadd_back(&stack_a, ft_lstnew(&digit3));
	// ft_lstadd_back(&stack_a, ft_lstnew(&digit4));
	if (argc > 2)
	{
		i = 1;
		stack_a = ft_lstnew(ft_new_number(ft_atoi_special(argv[1], &error)));
		while (++i < argc)
		{
			ft_printf("args[%i]: %i\n", i, ft_atoi_special(argv[i], &error));
			ft_lstadd_back(&stack_a, ft_lstnew(ft_new_number(ft_atoi_special(argv[i], &error))));
		}
	}
	if (argc == 2)
	{
		i = 0;
		splitted = ft_split(argv[1], ' ');
		stack_a = ft_lstnew(ft_new_number(ft_atoi_special(splitted[i], &error)));
		while (splitted[i])
		{
			ft_lstadd_back(&stack_a, ft_lstnew(ft_new_number(ft_atoi_special(splitted[i], &error))));
			i++;
		}
	}
	ft_print_stacks(&stack_a, &stack_b);
}
