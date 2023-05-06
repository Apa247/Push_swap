/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:34:37 by daparici          #+#    #+#             */
/*   Updated: 2023/05/06 02:29:29 by davidaparic      ###   ########.fr       */
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

void	sort_4(t_stack **stack_a, t_stack **stack_b, int index)
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
	int	frag;
	int	d_up;
	int	d_down;

	frag = 20;
	if (stack_b)
		frag = 20;
	while (find_frag_first((*stack_a), frag) >= 0 && frag <= 100)
	{
		d_up = find_frag_first((*stack_a), frag);
		d_down = find_frag_second((*stack_a), frag);
		printf("first-%i\n", d_up);
		printf("second-%i\n", d_down);
		if (d_up <= d_down)
			ft_rotate_up(stack_a, d_up);
		else if (d_down < d_up)
			ft_reverse_rotate_down(stack_a, d_down);
		ft_lstlast_p_2(*stack_a);
		if (find_frag_first((*stack_a), frag) < 0)
			frag += 20;
	}
}

int	find_frag_first(t_stack *stack_a, int frag)
{
	int	distance;

	distance = 0;
	while (stack_a)
	{
		if (stack_a->index < frag && stack_a->index >= frag - 20)
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
	int		size;

	size = ft_lstsize_p(stack_a);
	distance = 1;
	tmp_distance = 1;
	tmp = stack_a;
	while (stack_a->next)
	{
		if (stack_a->next->index < frag && stack_a->next->index >= frag - 20)
		{
			tmp = stack_a->next;
			distance = tmp_distance + 1;
			//printf("frag-%i valor-%i\n", frag, tmp->index);
		}
		tmp_distance++;
		stack_a = stack_a->next;
	}
	//printf("distance- %i\n", distance);
	if (tmp->index < frag && tmp->index >= frag - 20)
		return (size - distance + 1);
	else
		return (-1);
}

void	ft_rotate_up(t_stack **stack_a, int distance)
{
	while (distance > 0)
	{
		ra(stack_a);
		distance--;
	}	
}

void	ft_reverse_rotate_down(t_stack **stack_a, int distance)
{
	while (distance > 0)
	{
		rra(stack_a);
		distance--;
	}
}