/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:40:41 by rohidalg          #+#    #+#             */
/*   Updated: 2025/01/21 18:33:40 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}
/*cuenta palabras utilizando el delimitador c,
y count se imcrementa cada vez que encuentra el primer caracter de la palabra*/

char	*ft_words(char const *str, char c, int *i)
{
	char	*word;
	int		start;
	int		len;

	while (str[*i] && str[*i] == c)
		(*i)++;
	start = *i;
	while (str[*i] && str[*i] != c)
		(*i)++;
	len = *i - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	ft_strlcpy(word, str + start, len + 1);
	return (word);
}
/*i rastrea la posicion de la palabra y len coge el tamaño 
para el espacio de memoria*/

char	**ft_free(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
	return (0);
}
/*libera memoria asiganada en bucle para las string y luego para la matriz*/

char	**ft_split(char const *str, char c)
{
	int		countwords;
	char	**string;
	int		i_string;
	int		i;

	if (!str)
		return (0);
	countwords = ft_countwords(str, c);
	string = ft_calloc(countwords + 1, sizeof(char *));
	if (string == 0)
		return (0);
	i_string = 0;
	i = 0;
	while (i_string < countwords)
	{
		string[i_string] = ft_words(str, c, &i);
		if (!string[i_string])
			return (ft_free(string));
		i_string++;
	}
	string[i_string] = 0;
	return (string);
}

/*asigno memoria con calloc y sabiendo las palabras que hay, hago el tamaño,
luego con ft_words las agrega a la matriz, y en caso de error uso el free*/