/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_imput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:16:46 by daparici          #+#    #+#             */
/*   Updated: 2023/04/27 12:52:51 by daparici         ###   ########.fr       */
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

int	ft_check_arg(char **tmp, int k)
{
	long	nb;

	if (!ft_check_is_number(tmp[k]))
		msg_error("Error\n");
	nb = ft_atoi_p(tmp[k]);
	return (nb);
}
