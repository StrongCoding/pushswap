/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:35:25 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/18 21:37:02 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_recursive_str_to_int(const char *str, int *number)
{
	if (!str[0])
		return (0);
	if (!(str[0] >= '0' && str[0] <= '9'))
		return (0);
	if (str[0] >= '0' && str[0] <= '9')
		*number = *number * 10 + str[0] - '0';
	ft_recursive_str_to_int(&str[1], number);
	return (0);
}

int	ft_check_after(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str [i] <= '9')
		i++;
	if (str[i])
		return (1);
	else
		return (0);
}

int	ft_set_error(int *error)
{
	*error = 1;
	return (0);
}

int	ft_atoi_s(char *str, int *error)
{
	int		i;
	int		count_minus;
	int		number;

	i = 0;
	count_minus = 0;
	number = 0;
	if (!str[0])
		return (ft_set_error(error));
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str [i] == '+')
		if (str[i++] == '-')
			count_minus++;
	if (!(str[i] >= '0' && str [i] <= '9'))
		return (ft_set_error(error));
	ft_recursive_str_to_int(&str[i], &number);
	if (ft_check_after(&str[i]))
		return (ft_set_error(error));
	if (((!(count_minus % 2)) || number == -2147483648))
		return (number);
	else if ((i) && (count_minus % 2))
		return (number * -1);
	else
		return (ft_set_error(error));
}
