/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:37:46 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/11 10:30:13 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		error;
	int		count;

	error = 0;
	count = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ft_fill_s(&stack_a, argc, argv, &count))
		write(2, "Error\n", 6);
	else
	{
		//ft_print_stacks(&stack_a, &stack_b);
		if (count < 3)
			write(2, "Error\n", 6);
		else if (count == 3)
		{
			if (DEBUG)
				printf("sort three\n");
			ft_sort_three(&stack_a);
		}
		else if (count > 3 && count < 11)
		{
			if (DEBUG)
				printf("sort more than three\n");
			ft_sort_until_five(&stack_a, &stack_b, count);
		}
		else if (count == 50)
		{
			if (DEBUG)
				printf("sort 50\n");
			ft_sort_a_lot(&stack_a, &stack_b, count);
		}
		else if (count == 100)
		{
			if (DEBUG)
				printf("sort 100\n");
			ft_sort_a_lot(&stack_a, &stack_b, count);
		}
		else if (count == 500)
		{
			if (DEBUG)
				printf("sort 500\n");
			ft_sort_five_hundred(&stack_a, &stack_b, count);
		}
		else
		{
			if (DEBUG)
				printf("sort a lot\n");
			ft_sort_a_lot(&stack_a, &stack_b, count);
		}
	}
	//if (DEBUG)
	//	ft_print_stacks(&stack_a, &stack_b);
	//printf("count: %i sqrtnextcount: %i\n", count, ft_sqrt_next(count));
}

//cc main.c libftprintf.a operation_utils.c others.c ft_atoi_special.c sort_less.c ft_sort_a_lot.c operations_rotate.c operations_rr.c operations_ps.c
// "; ./a.out $ARG | ./checker_Mac $ARG

// ARG="515 -9805 52 1476 -4131"; ./a.out $ARG | wc -l