/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:28:01 by daparici          #+#    #+#             */
/*   Updated: 2023/04/26 13:10:04 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// size_t	ft_strlen_m(const char **str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{	
// 		i++;
// 	}
// 	return (i);
// }

void	msg_error(char *str)
{
	perror(str);
	exit (1);
}

void	innit_stack(t_stack **stack_a, char **list)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (list[i])
	{
		new = ft_lstnew_p(ft_atoi(list[i]));
		ft_lstadd_back_p(stack_a, new);
		get_index_stack((*stack_a), new);
		i++;
	}
	// sa(stack_a);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// rrr(stack_a, stack_b);
	// rr(stack_a, stack_b);
	// ft_lstlast_p_2((*stack_a));
	// printf("hola\n");
	//ft_lstlast_p_2((*stack_a));
}

void	get_index_stack(t_stack *stack_a, t_stack *new)
{
	while (stack_a->next)
	{
		if (stack_a->value > new->value)
			stack_a->index++;
		if (stack_a->value < new->value)
			new->index++;
		stack_a = stack_a->next;
	}
	// printf("%i", new->value);
	// printf("-%i-\n", new->index);
}

int	main(int ag, char *ar[])
{
	char	**list;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ag <= 1)
		msg_error("Error\nInvalid number of parameters");
	list = ft_check_arg(ag, ar);
	if (!list)
		return (0);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_a = NULL;
	stack_b = NULL;
	innit_stack(&stack_a, list);
	if (is_sort(&(*stack_a)))
		return (0);
	sort_list(&stack_a, &stack_b);
	return (0);
}

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	//ft_lstlast_p_2(*stack_a);
	if (ft_lstsize_p(*stack_a) == 2)
		ra(stack_a);
	if (ft_lstsize_p(*stack_a) == 3)
		sort_3(stack_a);
	if (ft_lstsize_p(*stack_a) == 4)
		sort_4(stack_a, stack_b, 1);
	if (ft_lstsize_p(*stack_a) == 5)
		sort_5(stack_a, stack_b);
	//ft_lstlast_p_2(*stack_a);
	if (is_sort(*stack_a))
		exit(0);
}

void	sort_3(t_stack **stack_a)
{
	if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->next->index
		> (*stack_a)->next->next->index)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->index
		< (*stack_a)->next->next->index)
		sa(stack_a);
	if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->index
		> (*stack_a)->next->next->index)
		rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index < (*stack_a)->next->next->index)
	{	
		ra(stack_a);
	}
	//ft_lstlast_p_2(*stack_a);
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
	//ft_lstlast_p_2(*stack_a);
	while (dt_to_first > 2 && dt_to_first < 5)
	{
		rra(stack_a);
		dt_to_first++;
	}
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b, 2);
	pa(stack_a, stack_b);
}