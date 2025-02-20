/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:09:51 by rohidalg          #+#    #+#             */
/*   Updated: 2024/06/19 12:50:44 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*current;
	t_list	*tmp;

	current = *lst;
	while (current)
	{
		tmp = current->next;
		del(current->nmb);
		free(current);
		current = tmp;
	}
	*lst = 0;
}
