/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:28:01 by daparici          #+#    #+#             */
/*   Updated: 2023/03/25 20:28:55 by daparici         ###   ########.fr       */
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
	exit (0);
}

int		ft_repet_nb()

int	ft_check_number(char *str)
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

int	main(int ag, char **ar)
{
	char	**list;
	size_t	i;
	long	nb;

	i = 0;
	printf("hola\n");
	if (ag <= 1)
		msg_error("Invalid number of parameters");
	if (ag == 2)
		list = ft_split(ar[1], ' ');
	if (ag > 2)
	{
		list = ar;
		i = 1;
	}
	while (list[i])
	{
		nb = ft_atoi(list[i]);
		if (!ft_check_number(list[i]))
			msg_error("Error, the parameters must be numbers");
		if (nb < -2147483648 || nb > 2147483647)
			msg_error("Error, the numbers must be type int");
		if (!ft_repet_nb(nb))
			msg_error("Error, repeating numbers")
		i++;
	}
	if (i == 1)
		ft_printf("%s\n", list[i]);
	return (0);
}
