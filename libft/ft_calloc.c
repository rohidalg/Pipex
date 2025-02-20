/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:53:39 by rohidalg          #+#    #+#             */
/*   Updated: 2024/05/24 11:34:57 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*tab;
	size_t			i;

	if (nitems == __SIZE_MAX__ || size == __SIZE_MAX__)
		return (0);
	i = 0;
	tab = (unsigned char *)malloc(size * nitems);
	if (!tab)
		return (0);
	while (i < nitems * size)
		tab[i++] = '\0';
	return (tab);
}

/*se usa para asignar nueva memoria, inicializarla en cero 
y luego devolver un puntero al inicio de esa memoria asignada*/