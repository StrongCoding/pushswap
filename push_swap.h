/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:38:12 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/10 19:15:26 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# define DEBUG 0

void	ft_print_stack(t_list **list);
void	ft_print_stacks(t_list **stack_a, t_list **stack_b);
void	ft_swap(t_list **stack);
void	ft_push(t_list **stack_src, t_list **stack_dst);
void	ft_rotate(t_list **stack);
void	ft_reverse_rotate(t_list **stack);
int		ft_atoi_special(char *str, int *error);
int		*ft_new_number(int number);
int		ft_fill_s(t_list **stack_a, int argc, char **argv, int *count);
void	ft_sort_three(t_list **stack);
void	ft_sort_until_five(t_list **stack_a, t_list **stack_b, int count);
void	ft_sort_a_lot(t_list **stack_a, t_list **stack_b, int count);
int		ft_sqrt_next(int nb);
void	ft_swap_a(t_list **stack);
void	ft_swap_b(t_list **stack);
void	ft_swap_s(t_list **stack_a, t_list **stack_b);
void	ft_push_a(t_list **stack_src, t_list **stack_dest);
void	ft_push_b(t_list **stack_src, t_list **stack_dest);
void	ft_rotate_a(t_list **stack);
void	ft_rotate_b(t_list **stack);
void	ft_rotate_r(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_a(t_list **stack);
void	ft_reverse_rotate_b(t_list **stack);
void	ft_reverse_rotate_r(t_list **stack_a, t_list **stack_b);
int		ft_get_shortest_way(t_list **stack, int number);
void	ft_get_highest_top_rev(t_list **stack);
void	ft_merge_sorted_stacks(t_list **stack_a, t_list **stack_b, int count);
void	ft_get_highest_top(t_list **stack);

#endif