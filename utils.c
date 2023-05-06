/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:54:37 by daparici          #+#    #+#             */
/*   Updated: 2023/05/06 12:46:29 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew_p(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->index = 1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_p(t_stack **lst, t_stack *new)
{
	t_stack	*dest;

	if (!lst)
		return ;
	if (*lst)
	{
		dest = ft_lstlast_p(*(lst));
		dest->next = new;
		new->next = NULL;
	}
	else
		(*lst) = new;
}

t_stack	*ft_lstlast_p(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstlast_p_2(t_stack *lst)
{
	while (lst)
	{
		printf("%i", lst->value);
		printf("-%i-\n", lst->index);
		lst = lst->next;
	}
}

t_stack	*ft_lstpenultimate(t_stack *lst)
{
	t_stack	*tmp;

	tmp = NULL;
	if (lst)
	{
		while (lst->next)
		{
			tmp = lst;
			lst = lst->next;
		}
	}
	return (tmp);
}

int	ft_lstsize_p_2(t_stack **lst)
{
	int	i;

	i = 0;
	while (*lst)
	{
		(*lst) = (*lst)->next;
		i++;
	}
	return (i);
}

int	ft_lstsize_p(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
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