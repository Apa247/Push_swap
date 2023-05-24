/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:34:37 by daparici          #+#    #+#             */
/*   Updated: 2023/05/24 18:09:10 by daparici         ###   ########.fr       */
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
	else if (ft_lstsize_p(*stack_a) > 100)
		sort_500(stack_a, stack_b);
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
	int	tmp_frag;
	int	d_up;
	int	d_down;

	frag = 20;
	tmp_frag = 20;
	while (find_frag_first((*stack_a), frag, tmp_frag) >= 0 && frag <= 100)
	{
		d_up = find_frag_first((*stack_a), frag, tmp_frag);
		d_down = find_frag_second((*stack_a), frag, tmp_frag);
		if (d_up <= d_down)
			rot_up(stack_a, stack_b, d_up, frag);
		else if (d_down < d_up)
			rot_down(stack_a, stack_b, d_down, frag);
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
	int	d_down;

	frag = 46;
	tmp_frag = 46;
	while (find_frag_first((*stack_a), frag, tmp_frag) >= 0 && frag <= 506)
	{
		d_up = find_frag_first((*stack_a), frag, tmp_frag);
		d_down = find_frag_second((*stack_a), frag, tmp_frag);
		if (d_up <= d_down)
			rot_up(stack_a, stack_b, d_up, frag);
		else if (d_down < d_up)
			rot_down(stack_a, stack_b, d_down, frag);
		put_in_stack_b(stack_a, stack_b, frag);
		if (find_frag_first((*stack_a), frag, tmp_frag) < 0)
			frag += 46;
	}
	put_in_stack_a(stack_a, stack_b);
}

void	put_in_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size_stack;
	int	distance;
	//int	distance_sec;

	while (ft_lstsize_p(*stack_b) > 0)
	{
		distance = distance_to_max_index(*stack_b);
		//distance_sec = distance_to_second_max(*stack_b);
		size_stack = ft_lstsize_p(*stack_b);
		if (distance <= size_stack - distance)
		{
			while (distance >= 1)
			{
				if ((*stack_b)->index == size_stack - 1)
					distance = 0;
				if (distance > 0)
					rb(stack_b);
				distance--;
			}
		}
		else if (distance > size_stack - distance)
		{
			distance = size_stack - distance;
			while (distance >= 1)
			{
				if ((*stack_b)->index == size_stack - 1)
					distance = 0;
				if (distance > 0)
					rrb(stack_b);
				distance--;
			}
		}
		pa(stack_a, stack_b);
		if (ft_lstsize_p(*stack_a) >= 2 && ft_lstsize_p(*stack_b) >= 2
			&& (*stack_a)->index > (*stack_a)->next->index
			&& (*stack_b)->index < (*stack_b)->next->index)
			ss(stack_a, stack_b);
		if (ft_lstsize_p(*stack_a) >= 2
			&& (*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
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

// int	distance_to_second_max(t_stack *stack_b)
// {
// 	int	distance;
// 	int	second_max;

// 	distance = 0;
// 	second_max = ft_lstsize_p(stack_b) - 1;
// 	while (stack_b && second_max != 0)
// 	{
// 		if (stack_b->index == second_max)
// 			return (distance);
// 		distance++;
// 		stack_b = stack_b->next;
// 	}
// 	return (-1);
// }

void	put_in_stack_b(t_stack **stack_a, t_stack **stack_b, int frag)
{
	// int	size_stack;

	int	distance;
	int	size;
	int	limit;

	distance = 0;
	limit = 0;
	size = ft_lstsize_p(*stack_a) + ft_lstsize_p(*stack_b);
	if (size > 5 && size < 500)
		limit = 10;
	else if (size >= 500)
		limit = 23;
	pb(stack_a, stack_b);
	if (ft_lstsize_p(*stack_b) >= 2 && ft_lstsize_p(*stack_a) >= 2
		&& (*stack_b)->index < frag - limit && (*stack_a)->index > frag)
		rr(stack_a, stack_b);
	if (ft_lstsize_p(*stack_b) >= 2 && (*stack_b)->index < frag - limit)
		rb(stack_b);
	// else if (!find_smaller_index((*stack_a), (*stack_b)))
	// {
	// 	distance = ft_get_previous((*stack_a), (*stack_b));
	// 	size_stack = ft_lstsize_p(*stack_b);
	// 	if (distance <= size_stack - distance)
	// 		ft_rotate_up(stack_b, distance, 'b');
	// 	else if (distance > size_stack - distance)
	// 		ft_reverse_rotate_down(stack_b, size_stack - distance, 'b');
	// 	pb(stack_a, stack_b);
	// }
	// else if (!find_bigger_index((*stack_a), (*stack_b)))
	// {
	// 	distance = ft_get_smaller((*stack_a), (*stack_b));
	// 	if (distance <= ft_lstsize_p(*stack_b) - distance)
	// 		ft_rotate_up(stack_b, distance, 'b');
	// 	else if (distance > ft_lstsize_p(*stack_b) - distance)
	// 		ft_reverse_rotate_down(stack_b,
	// 			ft_lstsize_p(*stack_b) - distance, 'b');
	// 	pb(stack_a, stack_b);
	// }
	// else
	// 	pb(stack_a, stack_b);
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
		if (stack_a->index < stack_b->index && min_distance == -1)
		{
			min_distance = stack_a->index - stack_b->index;
			distance = tmp_distance;
		}
		else if (stack_a->index > stack_b->index
			&& stack_a->index - stack_b->index > min_distance)
		{
			min_distance = stack_a->index - stack_b->index;
			distance = tmp_distance;
		}
		tmp_distance++;
		stack_b = stack_b->next;
	}
	return (distance);
}

int	find_smaller_index(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b)
	{
		if (stack_a->index > stack_b->index)
			return (1);
		stack_b = stack_b->next;
	}
	return (0);
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
		if (stack_a->index > stack_b->index && min_distance == -1)
		{
			min_distance = stack_b->index - stack_a->index;
			distance = tmp_distance;
		}
		else if (stack_a->index > stack_b->index
			&& stack_b->index - stack_a->index > min_distance)
		{
			min_distance = stack_b->index - stack_a->index;
			distance = tmp_distance;
		}
		tmp_distance++;
		stack_b = stack_b->next;
	}
	return (distance);
}

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

int	find_frag_second(t_stack *stack_a, int frag, int tmp_frag)
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
		if (stack_a->next->index < frag
			&& stack_a->next->index >= frag - tmp_frag)
		{
			tmp = stack_a->next;
			distance = tmp_distance + 1;
		}
		tmp_distance++;
		stack_a = stack_a->next;
	}
	if (tmp->index < frag && tmp->index >= frag - tmp_frag)
		return (size - distance + 1);
	else
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
		limit = 23;
	while (distance > 0)
	{
		if (ft_lstsize_p(*stack_b) >= 2 && (*stack_b)->index < frag - limit)
			rr(stack_a, stack_b);
		else
			ra(stack_a);
		distance--;
	}
}

void	rot_down(t_stack **stack_a, t_stack **stack_b, int distance, int frag)
{
	int	size;
	int	limit;

	limit = 0;
	size = ft_lstsize_p(*stack_a) + ft_lstsize_p(*stack_b);
	if (size > 5 && size < 500)
		limit = 10;
	else if (size >= 500)
		limit = 23;
	while (distance > 0)
	{
		if (ft_lstsize_p(*stack_b) >= 2 && (*stack_b)->index < frag - limit)
			rrr(stack_a, stack_b);
		else
			rra(stack_a);
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
