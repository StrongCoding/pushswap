/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:49:19 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/19 09:49:50 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sorted(t_list **stack)
{
	t_list	*tmp;
	int		sorted;

	sorted = 1;
	tmp = *stack;
	while (tmp->next != NULL && sorted)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			sorted = 0;
		tmp = tmp->next;
	}
	return (sorted);
}

//returns one if nothing is doubled
int	ft_check_double(t_list **stack)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		doubles;

	doubles = 1;
	tmp1 = *stack;
	tmp2 = *stack;
	while (tmp2->next != NULL && doubles)
	{
		while (tmp1->next != NULL && doubles)
		{
			if (*(int *)tmp2->content == *(int *)tmp1->next->content)
				doubles = 0;
			tmp1 = tmp1->next;
		}
		tmp2 = tmp2->next;
		tmp1 = tmp2;
	}
	return (doubles);
}
