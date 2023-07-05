/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:29 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/05 09:30:09 by dnebatz          ###   ########.fr       */
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

int	ft_fill_s(t_list **stack_a, int argc, char **argv, int *count)
{
	char	**splitted;
	int		error;
	int		i;

	error = 0;
	i = 0;
	if (argc > 2)
	{
		i = 1;
		*stack_a = ft_lstnew(ft_new_number(ft_atoi_special(argv[1], &error)));
		while (++i < argc)
			ft_lstadd_back(stack_a,
				ft_lstnew(ft_new_number(ft_atoi_special(argv[i], &error))));
		i--;
	}
	if (argc == 2)
	{
		i = 0;
		splitted = ft_split(argv[1], ' ');
		*stack_a = ft_lstnew(
				ft_new_number(ft_atoi_special(splitted[0], &error)));
		while (splitted[++i])
			ft_lstadd_back(stack_a,
				ft_lstnew(ft_new_number(ft_atoi_special(splitted[i], &error))));
	}
	*count = i;
	return (error);
}

int	ft_sqrt_next(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (i <= 46340)
	{
		if (i * i == nb)
			return (i);
		else if (i * i > nb && (i -1) * (i -1) < nb)
			return (i);
		i++;
	}
	return (0);
}
