/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:08:23 by rohidalg          #+#    #+#             */
/*   Updated: 2023/09/20 20:51:44 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	ssize_t	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == ((unsigned char)c))
			return ((char *)s + i);
		i--;
	}
	return (0);
}

/*busca el carácter en la cadena desde el final hacia el principio
hasta que encuentra el carácter deseado o llega al inicio de la cadena */