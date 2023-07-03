/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:38:12 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/03 15:47:25 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

void	ft_print_stack(t_list **list);
void	ft_print_stacks(t_list **stack_a, t_list **stack_b);
void	ft_swap(t_list **stack);
void	ft_push(t_list **stack_src, t_list **stack_dst);
void	ft_rotate(t_list **stack);
void	ft_reverse_rotate(t_list **stack);
int		ft_atoi_special(char *str, int *error);
int		*ft_new_number(int number);
int	ft_fill_s(t_list **stack_a, t_list **stack_b, int argc, char **argv);

#endif