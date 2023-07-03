/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:03:47 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/03 07:01:17 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*tmp;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	//tmp->next = (*stack)->next->next;
	//printf("before stack adress: %p stack->next: %p stack->next-next: %p\n", *stack, (*stack)->next,(*stack)->next->next);
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	//printf("after stack adress: %p stack->next: %p stack->next->next: %p\n", *stack, (*stack)->next, (*stack)->next->next);
}
	/*stack 1 -> stack 2 -> stack 3 -> stack 4
	stack 2 -> stack 3 -> stack 4
	stack 3 -> stack 4
	stack 4 -> NULL*/
// void	ft_push(t_l_stack stack)
// {
	
// }

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	*stack = (*stack)->next;
	//printf("before stack adress: %p stack->next: %p stack->next-next: %p\n", *stack, (*stack)->next,(*stack)->next->next);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp2->next = NULL;
	//printf("after stack adress: %p stack->next: %p stack->next->next: %p\n", *stack, (*stack)->next, (*stack)->next->next);
}

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	tmp2 = *stack;
	//printf("before stack adress: %p stack->next: %p stack->next-next: %p\n", *stack, (*stack)->next,(*stack)->next->next);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	//tmp->next ist das letzte Element also muss das auf erste
	*stack = tmp->next;
	(*stack)->next = tmp2;
	tmp->next = NULL;
	//*stack = tmp->next;
	//printf("after stack adress: %p stack->next: %p stack->next->next: %p\n", *stack, (*stack)->next, (*stack)->next->next);
}
