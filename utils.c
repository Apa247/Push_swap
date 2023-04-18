/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:54:37 by daparici          #+#    #+#             */
/*   Updated: 2023/04/18 13:14:43 by daparici         ###   ########.fr       */
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

