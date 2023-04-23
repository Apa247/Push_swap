/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:54:37 by daparici          #+#    #+#             */
/*   Updated: 2023/04/23 21:49:48 by daparici         ###   ########.fr       */
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
	t_stack *tmp;

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