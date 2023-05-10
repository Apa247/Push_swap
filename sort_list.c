/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:34:37 by daparici          #+#    #+#             */
/*   Updated: 2023/05/10 12:22:45 by daparici         ###   ########.fr       */
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
	else if (ft_lstsize_p(*stack_a) > 5 && ft_lstsize_p(*stack_a) <= 100)
		sort_100(stack_a, stack_b);
	// printf("stack a\n");
	// ft_lstlast_p_2(*stack_a);
	// printf("stack b\n");
	// ft_lstlast_p_2(*stack_b);
	if (is_sort(*stack_b))
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
	int	distance_to_max;

	frag = 20;
	while (find_frag_first((*stack_a), frag) >= 0 && frag <= 100)
	{
		d_up = find_frag_first((*stack_a), frag);
		d_down = find_frag_second((*stack_a), frag);
		if (d_up <= d_down)
			ft_rotate_up(stack_a, d_up, 'a');
		else if (d_down < d_up)
			ft_reverse_rotate_down(stack_a, d_down, 'a');
		put_in_stack_b(stack_a, stack_b);
		// if (*stack_a)
		// {
		// 	printf("stack a\n");
		// 	ft_lstlast_p_2(*stack_a);
		// }
		// if (*stack_b)
		// {
		// 	printf("stack b\n");
		// 	ft_lstlast_p_2(*stack_b);
		// }
		if (find_frag_first((*stack_a), frag) < 0)
			frag += 20;
	}
	distance_to_max = distance_to_max_index(*stack_b);
	if (distance_to_max == -1)
		msg_error("Error en distance_to_max");
	put_in_stack_a(stack_a, stack_b, distance_to_max);
}

void	put_in_stack_a(t_stack **stack_a, t_stack **stack_b, int distance)
{
	int	size_stack;

	size_stack = ft_lstsize_p(*stack_b);
	// printf("size%i\n", size_stack);
	if (distance <= size_stack - distance)
	{
		while (distance > 1)
		{
			rb(stack_b);
			distance--;
		}
	}
	else if (distance > size_stack - distance)
	{
		while (distance > 1)
		{
			rrb(stack_b);
			distance--;
		}
	}
	// printf("stack b\n");
	// ft_lstlast_p_2(*stack_b);
	while (size_stack > 0)
	{
		pa(stack_a, stack_b);
		size_stack--;
	}
}

int	distance_to_max_index(t_stack *stack_b)
{
	int	distance;
	int	max_index;

	distance = 0;
	max_index = ft_lstsize_p(stack_b);
	while (stack_b)
	{
		if (stack_b->index == max_index)
			return (distance);
		distance++;
		stack_b = stack_b->next;
	}
	return (-1);
}

void	put_in_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;
	int	size_stack;

	distance = 0;
	if (!stack_b)
		pb(stack_a, stack_b);
	else if (ft_lstsize_p(*stack_b) == 1 && (*stack_a)->index
		> (*stack_b)->index)
		pb(stack_a, stack_b);
	else if (ft_lstsize_p(*stack_b) == 1 && (*stack_a)->index
		< (*stack_b)->index)
	{
		pb(stack_a, stack_b);
		sb(stack_b);
	}
	else if (find_bigger_index((*stack_a), (*stack_b)))
	{
		distance = ft_get_previous((*stack_a), (*stack_b));
		size_stack = ft_lstsize_p(*stack_b);
		if (size_stack - distance == 1)
		{
			pb(stack_a, stack_b);
			rrb(stack_b);
		}
		else if (distance <= size_stack - distance)
			ft_rotate_up(stack_b, distance, 'b');
		else if (distance > size_stack - distance)
			ft_reverse_rotate_down(stack_b, size_stack - distance, 'b');
		if (size_stack - distance != 1)
		{
			rb(stack_b);
			pb(stack_a, stack_b);
			rrb(stack_b);
		}
	}
	else if (!find_bigger_index((*stack_a), (*stack_b)))
	{
		distance = ft_get_smaller((*stack_a), (*stack_b));
		if (distance <= ft_lstsize_p(*stack_b) - distance)
			ft_rotate_up(stack_b, distance, 'b');
		else if (distance > ft_lstsize_p(*stack_b) - distance)
			ft_reverse_rotate_down(stack_b,
				ft_lstsize_p(*stack_b) - distance, 'b');
		pb(stack_a, stack_b);
	}
}

int	ft_get_smaller(t_stack *stack_a, t_stack *stack_b)
{
	int	distance;
	int	tmp_distance;
	int	min_distance;

	tmp_distance = 0;
	min_distance = -1;
	while (stack_b)
	{
		if (stack_a->index > stack_b->index && min_distance == -1)
		{
			min_distance = stack_a->index - stack_b->index;
			distance = tmp_distance;
		}
		else if (stack_a->index > stack_b->index
			&& stack_a->index - stack_b->index < min_distance)
		{
			min_distance = stack_a->index - stack_b->index;
			distance = tmp_distance;
		}
		tmp_distance++;
		stack_b = stack_b->next;
	}
	return (distance);
}

int	find_bigger_index(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_a->index < stack_b->index)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
}

int	ft_get_previous(t_stack *stack_a, t_stack *stack_b)
{
	int		distance;
	int		tmp_distance;
	int		min_distance;

	tmp_distance = 0;
	min_distance = -1;
	while (stack_b)
	{
		if (stack_a->index < stack_b->index && min_distance == -1)
		{
			min_distance = stack_b->index - stack_a->index;
			distance = tmp_distance;
		}
		else if (stack_a->index < stack_b->index
			&& stack_b->index - stack_a->index < min_distance)
		{
			min_distance = stack_b->index - stack_a->index;
			distance = tmp_distance;
		}
		tmp_distance++;
		stack_b = stack_b->next;
	}
	return (distance);
}

int	find_frag_first(t_stack *stack_a, int frag)
{
	int	distance;

	distance = 0;
	if (!(stack_a))
		return (-1);
	while (stack_a)
	{
		if (stack_a->index <= frag && stack_a->index >= frag - 20)
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
		}
		tmp_distance++;
		stack_a = stack_a->next;
	}
	if (tmp->index < frag && tmp->index >= frag - 20)
		return (size - distance + 1);
	else
		return (-1);
}

void	ft_rotate_up(t_stack **stack, int distance, char c)
{
	while (distance > 0 && c == 'a')
	{
		ra(stack);
		distance--;
	}
	while (distance > 0 && c == 'b')
	{
		rb(stack);
		distance--;
	}
}

void	ft_reverse_rotate_down(t_stack **stack, int distance, char c)
{
	while (distance > 0 && c == 'a')
	{
		rra(stack);
		distance--;
	}
	while (distance > 0 && c == 'b')
	{
		rrb(stack);
		distance--;
	}
}
