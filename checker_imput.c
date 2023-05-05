/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_imput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:16:46 by daparici          #+#    #+#             */
/*   Updated: 2023/05/05 11:20:38 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_repet_nb(t_stack *list, long cmp)
{
	while (list)
	{
		if (list->value == cmp)
			msg_error("Error\n");
		list = list->next;
	}
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
