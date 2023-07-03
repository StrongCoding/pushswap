/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:37:46 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/03 08:52:57 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	int digit = 7;
	int digit1 = 8;
	int digit2 = 6;
	int digit3 = 1;
	int digit4 = 2;
	int j = 0;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_lstnew(&digit);
	ft_lstadd_back(&stack_a, ft_lstnew(&digit1));
	ft_lstadd_back(&stack_a, ft_lstnew(&digit2));
	ft_lstadd_back(&stack_a, ft_lstnew(&digit3));
	ft_lstadd_back(&stack_a, ft_lstnew(&digit4));
	if (argc > 2)
	{
		i = 0;
		while (++i < argc)
		{
			ft_printf("args[%i]: %s\n", i, argv[i]);
		}
	}
	if (argc == 2)
		ft_printf("hier muss ich splitten\n");
	printf("stack_a: %i adress: %p next-> %p\n", *(int *)stack_a->content, stack_a, stack_a->next);	tmp = stack_a;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		printf("stack_a: %i adress: %p next-> %p\n", *(int *)tmp->content, tmp, tmp->next);
	}
	printf("\n");
	//ft_reverse_rotate(&stack_a);
	ft_push(&stack_a, &stack_b);
	ft_push(&stack_a, &stack_b);
	printf("stack_b: %i\n", *(int *)stack_b->content);
	printf("2x push wurde ausgefuehrt!\n");
	printf("stack_a: %i\n", *(int *)stack_a->content);
	printf("stack_a: %i adress: %p next-> %p\n", *(int *)stack_a->content, stack_a, stack_a->next);
	tmp = stack_a;
	while (tmp->next != NULL && j++ < 10)
	{
		tmp = tmp->next;
		printf("stack_a: %i adress: %p next-> %p\n", *(int *)tmp->content, tmp, tmp->next);
		j++;
	}
	j = 0;
	printf("\n");

	printf("stack_b: %i\n", *(int *)stack_b->content);
	tmp = stack_b;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		printf("stack_b: %i\n", *(int *)tmp->content);
	}
	printf("\n");
	//ft_reverse_rotate(&stack_b);
	printf("stack_b: %i adress: %p next-> %p\n", *(int *)stack_b->content, stack_b, stack_b->next);
	tmp = stack_b;
	while (tmp->next != NULL && j++ < 10)
	{
		tmp = tmp->next;
		printf("stack_b: %i adress: %p next-> %p\n", *(int *)tmp->content, tmp, tmp->next);
		j++;
	}
}
//ft_fill_list()