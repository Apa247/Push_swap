/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:45:41 by daparici          #+#    #+#             */
/*   Updated: 2023/04/19 13:03:56 by daparici         ###   ########.fr       */
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
	struct s_stack	*next;
}				t_stack;

size_t	ft_strlen_m(const char **str);

int		main(int ag, char **ar);
void	innit_stack(t_stack **stack_a, t_stack **stack_b, char **list);
int		ft_check_number(char *str);
char	**ft_check_arg(int ag, char **ar);
void	ft_check_list(char **list, size_t i);
int		ft_repet_nb(char **list);
void	msg_error(char *str);
t_stack	*ft_lstnew_p(int content);
void	ft_lstadd_back_p(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast_p(t_stack *lst);
void	get_index_stack(t_stack *stack_a, t_stack *new);
void	ft_lstlast_p_2(t_stack *lst);
void	rotate(t_stack **stack);
void	push(t_stack **stack_from, t_stack **stack_to);
#endif