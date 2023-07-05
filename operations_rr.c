// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	ft_reverse_rotate_a(t_list **stack)
{
	ft_reverse_rotate(stack);
	write(1, "rra\n", 4);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	ft_reverse_rotate_b(t_list **stack)
{
	ft_reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

// rrr : rra and rrb at the same time.
void	ft_reverse_rotate_r(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
