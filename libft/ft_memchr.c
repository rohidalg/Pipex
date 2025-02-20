/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:20:07 by rohidalg          #+#    #+#             */
/*   Updated: 2023/09/21 12:58:50 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;

	i = 0;
	s = str;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}

/*busca la primera aparición del carácter c
en los primeros n bytes de la memoria apuntada por str*/