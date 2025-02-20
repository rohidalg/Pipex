/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:46:37 by rohidalg          #+#    #+#             */
/*   Updated: 2023/09/16 13:02:35 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	if (!dest && !src)
		return (0);
	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (i < len)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}

/* copia un bloque de memoria de un lugar a otro*/