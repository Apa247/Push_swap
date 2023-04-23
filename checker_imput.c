/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_imput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:16:46 by daparici          #+#    #+#             */
/*   Updated: 2023/04/23 18:18:12 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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