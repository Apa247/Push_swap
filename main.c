/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:28:01 by daparici          #+#    #+#             */
/*   Updated: 2023/04/19 13:13:11 by daparici         ###   ########.fr       */
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

int	ft_repet_nb(char **list)
{
	int	i;
	int	k;
	int	nb;
	int	tmp;

	i = 0;
	while (list[i])
	{
		k = i + 1;
		while (list[k])
		{
			nb = ft_atoi(list[i]);
			tmp = ft_atoi(list[k]);
			if (nb == tmp)
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	ft_check_is_number(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_check_list(char **list, size_t i)
{
	long	nb;

	while (list[i])
	{
		nb = ft_atoi(list[i]);
		if (!ft_check_is_number(list[i]))
			msg_error("Error\nThe parameters must be numbers");
		if (nb < -2147483648 || nb > 2147483647)
			msg_error("Error\nThe numbers must be type int");
		i++;
	}
	if (i == 1)
		ft_printf("%s\n", list[i]);
}

char	**ft_check_arg(int ag, char **ar)
{
	char	**list;
	size_t	i;

	i = 0;
	if (ag == 2)
		list = ft_split(ar[1], ' ');
	if (ag > 2)
	{
		list = ar;
		i = 1;
	}
	ft_check_list(list, i);
	if (!ft_repet_nb(list))
		msg_error("Error\nRepeating numbers");
	return (list);
}

void	innit_stack(t_stack **stack_a, t_stack **stack_b, char **list)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (list[i])
	{
		//printf("%s\n", list[i]);
		new = ft_lstnew_p(ft_atoi(list[i]));
		ft_lstadd_back_p(stack_a, new);
		get_index_stack((*stack_a), new);
		i++;
	}
	rotate(stack_a);
	push(stack_a, stack_b);
	ft_lstlast_p_2((*stack_a));
	printf("hola\n");
	ft_lstlast_p_2((*stack_b));
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

void	rotate(t_stack **stack)
{
	t_stack	*old_first;

	old_first = (*stack);
	*stack = (*stack)->next;
	ft_lstadd_back_p(stack, old_first);
}