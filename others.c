/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:29 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/18 21:37:51 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fill_args(t_list **stack_a, int argc, char **argv, int *error)
{
	int	i;

	i = 1;
	*stack_a = ft_lstnew(ft_new_num(ft_atoi_s(argv[1], error)));
	while (++i < argc)
		ft_lstadd_back(stack_a,
			ft_lstnew(ft_new_num(ft_atoi_s(argv[i], error))));
	i--;
	return (i);
}

int	*ft_new_num(int number)
{
	int	*ptr_number;

	ptr_number = malloc(sizeof(int));
	*ptr_number = number;
	return (ptr_number);
}

int	ft_fill_s(t_list **stack_a, int argc, char **argv, int *c)
{
	char	**splitted;
	int		error;
	int		i;

	error = 0;
	i = 0;
	if (argc > 2)
		i = ft_fill_args(stack_a, argc, argv, &error);
	if (argc == 2)
	{
		i = 0;
		splitted = ft_split(argv[1], ' ');
		if (splitted && splitted[0])
			*stack_a = ft_lstnew(ft_new_num(ft_atoi_s(splitted[0], &error)));
		free(splitted[0]);
		while (splitted[++i])
		{
			ft_lstadd_back(stack_a,
				ft_lstnew(ft_new_num(ft_atoi_s(splitted[i], &error))));
			free(splitted[i]);
		}
		free(splitted);
	}
	*c = i;
	return (error);
}
