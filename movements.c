/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:19:19 by daparici          #+#    #+#             */
/*   Updated: 2023/04/26 12:48:14 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp_value;
	int		tmp_index;

	first = (*stack);
	second = first->next;
	tmp_value = first->value;
	tmp_index = first->index;
	first->value = second->value;
	first->index = second->index;
	second->value = tmp_value;
	second->index = tmp_index;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*tmp;

	tmp = (*stack_from);
	(*stack_from) = (*stack_from)->next;
	if (!(*stack_to))
	{
		(*stack_to) = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = (*stack_to);
		(*stack_to) = tmp;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}

void	rotate(t_stack **stack)
{
	t_stack	*old_first;

	old_first = (*stack);
	*stack = (*stack)->next;
	ft_lstadd_back_p(stack, old_first);
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*old_last;
	t_stack	*penultimate;

	penultimate = ft_lstpenultimate(*(stack));
	old_last = ft_lstlast_p(*(stack));
	old_last->next = *stack;
	*stack = old_last;
	penultimate->next = NULL;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
