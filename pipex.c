/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:36:17 by rohidalg          #+#    #+#             */
/*   Updated: 2025/02/20 18:54:55 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_getenv(char *name, char **env)
{
	int i;
	int j;
	char *sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (0);
}
// busca la variable del entorno que deseemmos y nos devuelve su valor

char *ft_getpath(char *command, char **env)
{
	int i;
	char **path;
	char *tmp;
	char *path_part;
	char **cmmd;

	i = -1;
	path = ft_split(ft_getenv("PATH", env), ':');
	cmmd = ft_split(command, ' ');
	while (path[i++])
	{
		tmp = ft_strjoin(path[i], "/");		  // "/usr/bin/"
		path_part = ft_strjoin(tmp, cmmd[0]); // "/usr/bin/ls"
		free(tmp);
		if (access(path_part, F_OK | X_OK) == 0) // existe? | ejecutable?
		{
			ft_free(cmmd);
			return (path_part);
		}
		free(path_part);
	}
	ft_free(path);
	ft_free(cmmd);
	return (command);
}

void ft_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void ft_check_argv(int argc)//, char **argv)
{
	if (argc != 5)
		ft_exit("More or less than 5 arguments\n");
}





int main(int argc, char **argv, char **env)
{
	if (argc >= 2)
	{
		char *command_path = ft_getpath(argv[1], env);
		//ft_check_argv(argc);
		printf("Ruta de %s: %s\n", argv[1], command_path);
	}

	return (0);
}