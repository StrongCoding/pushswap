/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:37:46 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/17 17:53:47 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pick_sort(t_list **stack_a, t_list **stack_b, int count)
{
	if (count < 3)
	{
		write(2, "Error!\n", 7);
		exit(1);
	}
	else if (count == 3)
		ft_sort_three(*stack_a);
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
	int		error;
	int		count;

	error = 0;
	count = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ft_fill_s(&stack_a, argc, argv, &count))
		write(2, "Error\n", 6);
	else
		ft_pick_sort(&stack_a, &stack_b, count);
	ft_lstclear(&stack_a, free);
}

// cc main.c libftprintf.a operation_utils.c others.c ft_atoi_special.c
// sort_less.c ft_sort_a_lot.c operations_rotate.c operations_rr.c
// operations_ps.c ft_sort_five_hundred.c sort_a_lot_utils.c
// "; ./a.out $ARG | ./checker_Mac $ARG
// ARG="515 -9805 52 1476 -4131"; ./a.out $ARG | wc -l
// valgrind --leak-check=full -s ./a.out ARG
// 62 blocks