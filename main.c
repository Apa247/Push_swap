/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:28:01 by daparici          #+#    #+#             */
/*   Updated: 2023/04/17 13:25:17 by daparici         ###   ########.fr       */
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
			msg_error("Error, the parameters must be numbers");
		if (nb < -2147483648 || nb > 2147483647)
			msg_error("Error, the numbers must be type int");
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
		msg_error("Error, repeating numbers");
	return (list);
}

void	innit_stack(t_stack **stack_a, char **list)
{
	t_stack *new;
	int		i;

	i = 0;
	while (list[i])
	{
		new = ft_lstnew(ft_atoi(list[i]);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	
}

int	main(int ag, char **ar)
{
	char	**list;
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ag <= 1)
		msg_error("Invalid number of parameters");
	list = ft_check_arg(ag, ar);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	innit_stack(stack_a, list);
	return (0);
}
