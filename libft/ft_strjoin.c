/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:37:57 by rohidalg          #+#    #+#             */
/*   Updated: 2023/09/27 16:06:01 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dest = (char *)malloc(sizeof(*dest) * (i + j + 1));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, i + j + 1);
	ft_strlcat(dest, s2, i + j + 1);
	return (dest);
}

/*concatena 2 strings y la asigna en la nueva cadena resultante*/