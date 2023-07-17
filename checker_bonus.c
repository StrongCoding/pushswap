/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:44:42 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/17 19:06:48 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*hello;

	hello = get_next_line(0);
	while (hello && *hello != '\n')
	{
		printf("action was: %s", hello);
		hello = get_next_line(0);
	}
}
