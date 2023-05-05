/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:34:37 by daparici          #+#    #+#             */
/*   Updated: 2023/05/03 12:30:27 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize_p(*stack_a) == 2)
		ra(stack_a);
	else if (ft_lstsize_p(*stack_a) == 3)
		sort_3(stack_a);
	else if (ft_lstsize_p(*stack_a) == 4)
		sort_4(stack_a, stack_b, 1);
	else if (ft_lstsize_p(*stack_a) == 5)
		sort_5(stack_a, stack_b);
	else if (ft_lstsize_p(*stack_a) > 5 && ft_lstsize_p(*stack_a) < 100)
		sort_100(stack_a, stack_b);
	if (is_sort(*stack_a))
		exit(0);
}

void	sort_3(t_stack **stack_a)
{
	if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->next->index
		> (*stack_a)->next->next->index && (*stack_a)->index
		< (*stack_a)->next->next->index)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index
		< (*stack_a)->next->next->index)
		sa(stack_a);
	else if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->index
		> (*stack_a)->next->next->index && (*stack_a)->next->index
		> (*stack_a)->next->next->index) 
		rra(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index < (*stack_a)->next->next->index)
	{	
		ra(stack_a);
	}
}

void sort_4(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	distance;

	distance = distance_index((*stack_a), index);
	if (distance == 1)
		ra(stack_a);
	if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (distance == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

int	distance_index(t_stack *stack_a, int index)
{
	int	distance;

	distance = 0;
	while (stack_a)
	{
		if (stack_a->index == index)
			return (distance);
		distance++;
		stack_a = stack_a->next;
	}
	return (-1);
}

int	is_sort(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->index > stack_a->next->index)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	dt_to_first;
	int	tmp;

	dt_to_first = distance_index((*stack_a), 1);
	tmp = dt_to_first;
	while (tmp > 0 && tmp < 3)
	{
		ra(stack_a);
		tmp--;
	}
	while (dt_to_first > 2 && dt_to_first < 5)
	{
		rra(stack_a);
		dt_to_first++;
	}
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b, 2);
	pa(stack_a, stack_b);
}

void	sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int frag;
	int first;
	int second;

	frag = 20;
	if (stack_b)
		frag = 20;
	while (find_frag_first((*stack_a), frag) >= 0 && frag <= 100)
	{
		first = find_frag_first((*stack_a), frag);
		second = find_frag_second((*stack_a), frag);
		// printf("first-%i\n", first);
		// printf("second-%i\n", second);
		// break;
	}
}

int	find_frag_first(t_stack *stack_a, int frag)
{
	int distance;

	distance = 1;
	while (stack_a)
	{
		if (stack_a->index < frag && stack_a->index > frag - 20)
			return (distance);
		distance++;
		stack_a = stack_a->next;
	}
	return (-1);
}

int	find_frag_second(t_stack *stack_a, int frag)
{
	t_stack	*tmp;
	int		tmp_distance;
	int		distance;
	
	distance = 1;
	tmp_distance = 1;
	tmp = stack_a;
	while (stack_a->next)
	{
		if (stack_a->next->index < frag && stack_a->next->index > frag - 20)
		{
			tmp = stack_a;
			distance = tmp_distance + 1;
		}
		tmp_distance++;
		stack_a = stack_a->next;
	}
	if (tmp->index < frag && tmp->index > frag - 20)
		return (distance);
	else 
		return (-1);
}