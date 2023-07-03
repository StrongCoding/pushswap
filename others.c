/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:29 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/03 14:59:43 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_list **stack)
{
	t_list	*tmp;
	if (stack == NULL || *stack == NULL)
		return ;
	printf("stack: %i adress: %p next-> %p\n", *(int *)(*stack)->content, *stack, (*stack)->next);
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		printf("stack: %i adress: %p next-> %p\n", *(int *)tmp->content, tmp, tmp->next);
	}
}

void	ft_print_stacks(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmpb;

	tmp = *stack_a;
	tmpb = *stack_b;
	if (tmp == NULL && tmpb == NULL)
		return ;
	printf("stack a: ");
	if (tmp != NULL)
		printf("%i", *(int *)tmp->content);
	else
		printf("E");
	printf(" stack b: ");
	if (tmpb != NULL)
		printf("%i\n", *(int *)tmpb->content);
	else
		printf("E\n");
	//printf("stack: %i adress: %p next-> %p\n", *(int *)(*stack)->content, *stack, (*stack)->next);
	while ((tmp != NULL || tmpb != NULL))
	{
		printf("stack a: ");
		if (tmp != NULL && tmp->next != NULL)
			printf("%i", *(int *)tmp->next->content);
		else
			printf("E");
		if (tmp != NULL)
			tmp = tmp->next;
		printf(" stack b: ");
		if (tmpb != NULL && tmpb->next != NULL)
			printf("%i\n", *(int *)tmpb->next->content);
		else
			printf("E\n");
		if (tmpb != NULL)	
			tmpb = tmpb->next;
		//printf("stack_a->next: %p\n", tmp->next);
		//printf("stack_b->next: %p\n", tmpb->next);
		//printf("stack: %i adress: %p next-> %p\n", *(int *)tmp->content, tmp, tmp->next);
	}
}

int	*ft_new_number(int number)
{
	int	*ptr_number;

	ptr_number = malloc(sizeof(int));
	*ptr_number = number;
	return (ptr_number);
}