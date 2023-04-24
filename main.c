/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:28:01 by daparici          #+#    #+#             */
/*   Updated: 2023/04/24 13:10:33 by daparici         ###   ########.fr       */
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

void	innit_stack(t_stack **stack_a, t_stack **stack_b, char **list)
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
	// ft_lstlast_p_2((*stack_b));
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

int	main(int ag, char **ar)
{
	char	**list;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ag <= 1)
		msg_error("Error\nInvalid number of parameters");
	list = ft_check_arg(ag, ar);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_a = NULL;
	stack_b = NULL;
	innit_stack(&stack_a, &stack_b, list);
	
	return (0);
}

void	sort_list(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) <= 3)
		sort_3(stack_a, stack_b);
	if (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_a) <= 5)
		sort_5(stack_a, stack_b);
	else
		
}

void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	
}

void	radix_sort