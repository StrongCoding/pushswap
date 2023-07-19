/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:37:46 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/19 10:03:43 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pick_sort(t_list **stack_a, t_list **stack_b, int count)
{
	if (count < 2)
	{
		write(2, "Error count\n", 12);
		exit(1);
	}
	else if (count == 2)
		ft_sort_two(stack_a);
	else if (count == 3)
		ft_sort_three(stack_a);
	else if (count > 3 && count < 11)
		ft_sort_until_five(stack_a, stack_b, count);
	else if (count == 50)
		ft_sort_a_lot(stack_a, stack_b, count);
	else if (count == 100)
		ft_sort_a_lot(stack_a, stack_b, count);
	else if (count == 500)
		ft_sort_five_hundred(stack_a, stack_b, count);
	else
		ft_sort_a_lot(stack_a, stack_b, count);
}

int	main(int argc, char **argv)
{
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
		ft_pick_sort(&stack_a, &stack_b, count);
	ft_lstclear(&stack_a, free);
}

// cc main.c libftprintf.a operation_utils.c others.c
// ft_atoi_special.c sort_less.c ft_sort_a_lot.c operations_rotate.c
// operations_rr.c operations_ps.c  ft_sort_two.c ft_sort_five_hundred.c
// sort_a_lot_utils.c dontuploadthis.c errors.c -o push_swap
// "; ./a.out $ARG | ./checker_Mac $ARG
// ARG="515 -9805 52 1476 -4131"; ./a.out $ARG | wc -l
// valgrind --leak-check=full -s ./a.out 3 1 2
// 61 blocks