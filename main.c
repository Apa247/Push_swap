/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:28:01 by daparici          #+#    #+#             */
/*   Updated: 2023/05/27 21:35:49 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_leaks()
// {
// 	system("leaks -q push_swap");
// } 
//  atexit(ft_leaks);


void	innit_stack(t_stack **stack_a, char **list)
{
	t_stack	*new;
	int		i;
	int		k;
	long	nb;
	char	**tmp;

	i = 0;
	while (list[++i])
	{
		k = -1;
		if (list[i][0] == '\0')
			exit(1);
		tmp = ft_split(list[i], 32);
		while (tmp[++k])
		{
			nb = ft_check_arg(tmp, k);
			ft_repet_nb((*stack_a), nb);
			new = ft_lstnew_p(nb);
			ft_lstadd_back_p(stack_a, new);
			get_index_stack((*stack_a), new);
		}
		free_stack(tmp);
	}
}

void	free_stack(char **stack_a)
{
	int	i;

	i = 0;
	while (stack_a[i])
	{
		free(stack_a[i]);
		i++;
	}
	free(stack_a);
}

void	free_stack2(t_stack **stack_a, t_stack *stack_a_2,
			t_stack *stack_b_2)
{	
	while (*stack_a)
	{
		free(*stack_a);
		(*stack_a) = (*stack_a)->next;
	}
	free(stack_a_2);
	free(stack_b_2);
	
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
}

int	main(int ag, char *ar[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *stack_a_2;
	t_stack	*stack_b_2;

	if (ag <= 1)
		exit(1);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_a_2 = stack_a;
	stack_b_2 = stack_b;
	stack_a = stack_a->next;
	stack_b = stack_b->next;
	innit_stack(&stack_a, ar);
	if (ft_lstsize_p(stack_a) == 1 || is_sort(&(*stack_a)))
	{
		free_stack2(&stack_a, stack_a_2, stack_b_2);
		return (0);
	}
	sort_list(&stack_a, &stack_b);
	free_stack2(&stack_a, stack_a_2, stack_b_2);
	return (0);
}
