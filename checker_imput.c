/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_imput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:16:46 by daparici          #+#    #+#             */
/*   Updated: 2023/05/27 21:58:26 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	msg_error(char *str)
{
	perror(str);
	exit (1);
}

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
	if (*str == '-' || *str == '+')
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

int	ft_atoi_p(char *str)
{
	unsigned long long int		valor;
	int							signo;
	unsigned int				i;

	i = 0;
	signo = 1;
	valor = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -signo;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		valor = valor * 10 + (str[i] - '0');
		if (valor > 2147483647 && signo == 1)
			msg_error("Error\n");
		if (valor > 2147483648 && signo == -1)
			msg_error("Error\n");
		i++;
	}
	return ((int)(valor * signo));
}
