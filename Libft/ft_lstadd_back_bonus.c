/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:36:43 by daparici          #+#    #+#             */
/*   Updated: 2023/04/18 11:58:01 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*dest;

	if (!lst)
		return ;
	if (*lst)
	{
		dest = ft_lstlast(*(lst));
		dest->next = new;
	}
	else
		(*lst) = new;
}
