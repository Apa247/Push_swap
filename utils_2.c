/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:50:15 by davidaparic       #+#    #+#             */
/*   Updated: 2023/05/27 21:58:20 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_frag_first(t_stack *stack_a, int frag, int tmp_frag)
{
	int	distance;

	distance = 0;
	if (!(stack_a))
		return (-1);
	while (stack_a)
	{
		if (stack_a->index < frag && stack_a->index >= frag - tmp_frag)
			return (distance);
		distance++;
		stack_a = stack_a->next;
	}
	return (-1);
}

void	rot_up(t_stack **stack_a, t_stack **stack_b, int distance, int frag)
{
	int	size;
	int	limit;

	limit = 0;
	size = ft_lstsize_p(*stack_a) + ft_lstsize_p(*stack_b);
	if (size > 5 && size < 500)
		limit = 10;
	else if (size >= 500)
		limit = 25;
	while (distance > 0)
	{
		if (ft_lstsize_p(*stack_b) >= 2 && (*stack_b)->index < frag - limit)
			rr(stack_a, stack_b);
		else
			ra(stack_a);
		distance--;
	}
}

void	rotate_b(t_stack **stack_b, int distance, char c)
{
	while (distance > 0 && c == 'u')
	{
		rb(stack_b);
		distance--;
	}
	while (distance > 0 && c == 'd')
	{
		rrb(stack_b);
		distance--;
	}
}

int	is_sort(t_stack *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->index > stack_a->next->index)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	distance_to_max_index(t_stack *stack_b)
{
	int	distance;
	int	d_tmp;
	int	size_s;

	size_s = stack_b->index;
	d_tmp = 0;
	distance = 0;
	while (stack_b)
	{
		if (stack_b->index > size_s)
		{
			size_s = stack_b->index;
			distance = d_tmp;
		}
		d_tmp++;
		stack_b = stack_b->next;
	}
	return (distance);
}
