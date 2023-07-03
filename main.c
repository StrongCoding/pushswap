/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:37:46 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/03 10:16:59 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	int digit = 7;
	int digit1 = 8;
	int digit2 = 6;
	int digit3 = 1;
	int digit4 = 2;
	int j = 0;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_lstnew(&digit);
	ft_lstadd_back(&stack_a, ft_lstnew(&digit1));
	ft_lstadd_back(&stack_a, ft_lstnew(&digit2));
	ft_lstadd_back(&stack_a, ft_lstnew(&digit3));
	ft_lstadd_back(&stack_a, ft_lstnew(&digit4));
	if (argc > 2)
	{
		i = 0;
		while (++i < argc)
		{
			ft_printf("args[%i]: %s\n", i, argv[i]);
		}
	}
	if (argc == 2)
		ft_printf("hier muss ich splitten\n");
	ft_print_stacks(&stack_a, &stack_b);
	ft_push(&stack_a, &stack_b);
	printf("push b\n");
	ft_print_stacks(&stack_a, &stack_b);
	ft_push(&stack_a, &stack_b);
	printf("push b\n");
	ft_print_stacks(&stack_a, &stack_b);
	ft_reverse_rotate(&stack_b);
	ft_reverse_rotate(&stack_a);
	printf("reverse rotate\n");
	ft_print_stacks(&stack_a, &stack_b);
	ft_push(&stack_a, &stack_b);
	printf("push b\n");
	ft_print_stacks(&stack_a, &stack_b);
	ft_reverse_rotate(&stack_b);
	ft_reverse_rotate(&stack_a);
	printf("reverse rotate\n");
	ft_print_stacks(&stack_a, &stack_b);
	ft_push(&stack_b, &stack_a);
	printf("push a\n");
	ft_print_stacks(&stack_a, &stack_b);
}
//ft_fill_list()