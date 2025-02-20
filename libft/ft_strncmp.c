/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:45:25 by rohidalg          #+#    #+#             */
/*   Updated: 2023/09/21 12:19:53 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	if (!str1 && !str2)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < num)
		i++;
	if (i == num)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

/*te compara dos strings y te devuelve la resta de los caracteres asci*/