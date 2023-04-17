/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:45:41 by daparici          #+#    #+#             */
/*   Updated: 2023/04/17 13:17:26 by daparici         ###   ########.fr       */
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

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_stack;

size_t	ft_strlen_m(const char **str);

int		main(int ag, char **ar);
int		ft_check_number(char *str);
char	**ft_check_arg(int ag, char **ar);
void	ft_check_list(char **list, size_t i);
int		ft_repet_nb(char **list);
void	msg_error(char *str);

#endif