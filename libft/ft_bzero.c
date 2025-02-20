/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:52:26 by rohidalg          #+#    #+#             */
/*   Updated: 2023/09/18 13:56:50 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	while (i < (int)n)
	{
		s2[i] = 0;
		i++;
	}
}

/*se utiliza para establecer en cero un bloque de memoria ya existente,
no realiza la asignación de memoria*/