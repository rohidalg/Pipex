/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:00:07 by rohidalg          #+#    #+#             */
/*   Updated: 2023/09/25 20:26:15 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)ptr1;
	s2 = (unsigned char *)ptr2;
	if (!ptr1 && !ptr2)
		return (0);
	while (num)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		num--;
	}
	return (0);
}

/*compara los primeros num bytes de dos bloques de memoria,
Si encuentra una diferencia en los bytes, devuelve la diferencia
entre los primeros bytes diferentes.*/