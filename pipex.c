/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:36:17 by rohidalg          #+#    #+#             */
/*   Updated: 2025/03/19 19:43:22 by rohidalg         ###   ########.fr       */
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

void	ft_check_argv(int argc, char **argv)
{
	if (argc != 5)
		ft_exit("more or less than 5 arguments\n");
	if (access(argv[1], F_OK) == -1)
		ft_exit("no such file or directory\n");
	// if (access(argv[4], F_OK) == -1)
	// 	ft_exit("No such file or directory\n");
	// if (!argv[2][0] && !argv[3][0])
    //     ft_exit("Command not found\n");
    // if (!argv[3][0])
    //     ft_exit("Command not found\n");
    // if (!argv[2][0])
    //     ft_exit("Command not found\n");
}

void	ft_exec(char *command, char **env)
{
	char	**cmmd_part;

	cmmd_part = ft_split(command, ' ');
	if (execve(ft_getpath(cmmd_part[0], env), cmmd_part, env) == -1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmmd_part[0], 2);
		ft_free(cmmd_part);
		perror(""); //para que termine el hijo si falla
	}
}
// exec reemplaza la funcion para ejecutar el comando si llega a encontrarlo

int	ft_file(char *file, int option)
{
	int	tmp;

	tmp = 0;
	if (option == 0)
		tmp = open(file, O_RDONLY, 0777);
	if (option == 1)
		tmp = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (tmp == -1)
		exit(EXIT_FAILURE);
	return (tmp);
}

void	ft_son(char **argv, char **env, int *fd_p)
{
	int	fd;

	fd = ft_file(argv[1], 0);
	// printf("soy el hijo\n");
	dup2(fd, 0);      // redirige stdin al archivo
	dup2(fd_p[1], 1); // redirige stdout al pipe de escritura
	close(fd);
	ft_exec(argv[2], env);
	exit(EXIT_FAILURE);
}

void	ft_father(char **argv, char **env, int *fd_p)
{
	int	fd;

	fd = ft_file(argv[4], 1);
	// printf("soy el padre\n");
	dup2(fd, 1);      // redirige stdout al archivo
	dup2(fd_p[0], 0); // redirige stdin a la lectura del pipe
	close(fd);
	close(fd_p[0]);
	ft_exec(argv[3], env);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **env)
{
	int fd_p[2];
	pid_t pid;
	// pid_t pid2;
	// int status;

	ft_check_argv(argc, argv);
	if (pipe(fd_p) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		ft_son(argv, env, fd_p);
	// waitpid(pid1, &status, 0);
	// if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	// {
	// 	// Si el hijo falló, el padre no ejecuta nada
	// 	exit(WEXITSTATUS(status));
	// }
	ft_father(argv, env, fd_p);
	return (0);
}
