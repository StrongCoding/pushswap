/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:35:25 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/19 11:21:55 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_error(int *error)
{
	*error = 1;
	return (0);
}

int	ft_atoi_s(char *str, int *error)
{
	int		i;
	int		count_minus;
	long	number;

	i = 0;
	count_minus = 1;
	number = 0;
	if (!str[0])
		return (ft_set_error(error));
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			count_minus = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		number = (number * 10) + str[i++] - '0';
	number *= count_minus;
	if (i && number <= 2147483647 && number >= -2147483648)
		return (number);
	else
		return (ft_set_error(error));
}
