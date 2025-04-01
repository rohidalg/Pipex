/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:36:17 by rohidalg          #+#    #+#             */
/*   Updated: 2025/04/01 13:27:59 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		len;
	char	*result;

	if (!env || !name)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], name, len) && env[i][len] == '=')
		{
			result = env[i] + len + 1;
			return (result);
		}
		i++;
	}
	return (NULL);
}

char	*ft_getpath(char *command, char **env)
{
	char	**path;
	char	**cmmd;
	char	*result;

	if (!command)
		return (NULL);
	cmmd = ft_split(command, ' ');
	if (!cmmd)
		return (NULL);
	path = ft_split(ft_getenv("PATH", env), ':');
	if (!path)
	{
		ft_free(cmmd);
		return (NULL);
	}
	result = ft_check_path(path, cmmd[0]);
	ft_free(cmmd);
	ft_free(path);
	return (result);
}

void	ft_son(char **argv, char **env, int *fd_p)
{
	int	fd;

	fd = ft_file(argv[1], 0);
	dup2(fd, 0);
	dup2(fd_p[1], 1);
	close(fd_p[0]);
	ft_exec(argv[2], env);
}

void	ft_father(char **argv, char **env, int *fd_p)
{
	int	fd;

	fd = ft_file(argv[4], 1);
	dup2(fd, 1);
	dup2(fd_p[0], 0);
	close(fd_p[1]);
	ft_exec(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_p[2];
	pid_t	pid;
	int		status;

	ft_check_argv(argc, argv);
	if (pipe(fd_p) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		ft_son(argv, env, fd_p);
	waitpid(pid, &status, 0);
	ft_father(argv, env, fd_p);
	return (0);
}
