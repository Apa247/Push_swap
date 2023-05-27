/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_100:500.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:53:57 by davidaparic       #+#    #+#             */
/*   Updated: 2023/05/27 22:03:02 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int	frag;
	int	tmp_frag;
	int	d_up;

	frag = 20;
	tmp_frag = 20;
	while (find_frag_first((*stack_a), frag, tmp_frag) >= 0 && frag <= 100)
	{
		d_up = find_frag_first((*stack_a), frag, tmp_frag);
		rot_up(stack_a, stack_b, d_up, frag);
		put_in_stack_b(stack_a, stack_b, frag);
		if (find_frag_first((*stack_a), frag, tmp_frag) < 0)
			frag += 20;
	}
	put_in_stack_a(stack_a, stack_b);
}

void	sort_500(t_stack **stack_a, t_stack **stack_b)
{
	int	frag;
	int	tmp_frag;
	int	d_up;

	frag = 50;
	tmp_frag = 50;
	while (find_frag_first((*stack_a), frag, tmp_frag) >= 0 && frag <= 500)
	{
		d_up = find_frag_first((*stack_a), frag, tmp_frag);
		rot_up(stack_a, stack_b, d_up, frag);
		put_in_stack_b(stack_a, stack_b, frag);
		if (find_frag_first((*stack_a), frag, tmp_frag) < 0)
			frag += 50;
	}
	put_in_stack_a(stack_a, stack_b);
}

void	put_in_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size_stack;
	int	distance;
	int	flag;
	int	d_tmp;

	while (ft_lstsize_p(*stack_b) > 0)
	{
		distance = distance_to_max_index(*stack_b);
		size_stack = ft_lstsize_p(*stack_b);
		d_tmp = distance;
		if (distance > size_stack - distance)
			distance = size_stack - distance;
		while (distance > 0 && size_stack > 1)
		{
			if (size_stack >= 2 && (*stack_b)->index == size_stack - 1
				&& flag == 0)
			{
				pa(stack_a, stack_b);
				distance = 0;
				flag = 1;
			}
			if (d_tmp > size_stack / 2)
				rrb(stack_b);
			else
				rb(stack_b);
			distance--;
		}
		if (distance == 0)
		{
			pa(stack_a, stack_b);
			flag = 0;
		}
		if (ft_lstsize_p(*stack_a) >= 2 && ft_lstsize_p(*stack_b) >= 2
			&& (*stack_a)->index > (*stack_a)->next->index
			&& (*stack_b)->index < (*stack_b)->next->index)
			ss(stack_a, stack_b);
		else if (ft_lstsize_p(*stack_a) >= 2
			&& (*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
}


void	put_in_stack_b(t_stack **stack_a, t_stack **stack_b, int frag)
{
	int	distance;
	int	size;
	int	limit;

	distance = 0;
	limit = 0;
	size = ft_lstsize_p(*stack_a) + ft_lstsize_p(*stack_b);
	if (size > 5 && size < 500)
		limit = 10;
	else if (size >= 500)
		limit = 25;
	pb(stack_a, stack_b);
	if (ft_lstsize_p(*stack_b) >= 2 && ft_lstsize_p(*stack_a) >= 2
		&& (*stack_b)->index < frag - limit && (*stack_a)->index > frag)
		rr(stack_a, stack_b);
	if (ft_lstsize_p(*stack_b) >= 2 && (*stack_b)->index < frag - limit)
		rb(stack_b);
}