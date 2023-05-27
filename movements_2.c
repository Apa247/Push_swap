/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:25:33 by davidaparic       #+#    #+#             */
/*   Updated: 2023/05/27 21:26:32 by davidaparic      ###   ########.fr       */
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
