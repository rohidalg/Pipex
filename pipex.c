/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:36:17 by rohidalg          #+#    #+#             */
/*   Updated: 2025/03/05 18:41:56 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

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

char	*ft_getpath(char *command, char **env)
{
	int		i;
	char	**path;
	char	*tmp;
	char	*path_part;
	char	**cmmd;

	i = -1;
	path = ft_split(ft_getenv("PATH", env), ':');
	cmmd = ft_split(command, ' ');
	while (path[i++])
	{
		tmp = ft_strjoin(path[i], "/");       // "/usr/bin/"
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

void	ft_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_check_argv(int argc) //, char **argv)
{
	if (argc != 5)
		ft_exit("More or less than 5 arguments\n");
}

void	ft_exec(char *command, char *env)
{
	char	**cmmd_part;

	cmmd_part = ft_split(command, ' ');
	if (execve(ft_getpath(cmmd_part[0], env), cmmd_part, env) == -1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmmd_part[0], 2);
		ft_free(cmmd_part);
		exit(0);
	}
}
// exec reemplaza la funcion para ejecutar el comando si llega a encontrarlo

int	ft_file(char *file, int option)
{
	int	tmp;

	if (option == 0)
		tmp = open(file, O_RDONLY, 0777);
	if (option == 1)
		tmp = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (tmp == -1)
		exit(0);
	return (tmp);
}

int	main(int argc, char **argv, char **env)
{
	if (argc >= 2)
	{
		char *command_path = ft_getpath(argv[1], env);
		// ft_check_argv(argc);
		printf("Ruta de %s: %s\n", argv[1], command_path);
	}
	return (0);
}