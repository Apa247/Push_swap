/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:45:41 by daparici          #+#    #+#             */
/*   Updated: 2023/05/08 12:26:37 by davidaparic      ###   ########.fr       */
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
void	innit_stack(t_stack **stack_a, char **s_list);
int		ft_check_is_number(char *str);
int		ft_check_number(char *str);
int		ft_check_arg(char **tmp, int k);
void	ft_check_list(char **list, size_t i);
void	ft_repet_nb(t_stack *list, long cmp);
void	get_index_stack(t_stack *stack_a, t_stack *new);
// funciones de movimientos
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	push(t_stack **stack_from, t_stack **stack_to);
void	reverse_rotate(t_stack **stack);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// funciones utiles de libft
t_stack	*ft_lstnew_p(int content);
int		ft_lstsize_p(t_stack *lst);
int	ft_lstsize_p_2(t_stack **lst);
void	ft_lstadd_back_p(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast_p(t_stack *lst);
void	ft_lstlast_p_2(t_stack *lst);
t_stack	*ft_lstpenultimate(t_stack *lst);
int		ft_atoi_p(char *str);
// funcion de error
void	msg_error(char *str);
void	free_stack(char **stack_a);

// funciones de algoritmo
int		is_sort(t_stack *stack_a);
int		distance_index(t_stack *stack_a, int index);
void	sort_list(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b, int index);
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	sort_100(t_stack **stack_a, t_stack **stack_b);
int		find_frag_first(t_stack *stack_a, int frag);
int		find_frag_second(t_stack *stack_a, int frag);
void	ft_rotate_up(t_stack **stack_a, int distance);
void	ft_reverse_rotate_down(t_stack **stack_a, int distance);
void	put_in_stack_b(t_stack **stack_a, t_stack **stack_b);
int		ft_get_previous(t_stack *stack_a, t_stack *stack_b);
int		find_bigger_index(t_stack *stack_a, t_stack *stack_b);
#endif