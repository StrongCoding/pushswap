/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:38:12 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/03 08:01:24 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

void	ft_printlist(t_list **list);
void	ft_swap(t_list **stack);
void	ft_push(t_list **stack_src, t_list **stack_dst);
void	ft_rotate(t_list **stack);
void	ft_reverse_rotate(t_list **stack);

#endif