/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:45:41 by daparici          #+#    #+#             */
/*   Updated: 2023/03/25 20:15:39 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include "./printf/ft_printf.h"
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>
# include <xlocale.h>
# include <stdlib.h>

typedef struct s_push_swap
{
	char	**list;
}			t_push_swap;

size_t	ft_strlen_m(const char **str);
int	main(int ag, char **ar);
int	ft_check_number(char *str);

#endif