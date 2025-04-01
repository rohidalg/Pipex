/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:29:46 by rohidalg          #+#    #+#             */
/*   Updated: 2025/04/01 13:22:00 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *str, int ex)
{
	ft_putstr_fd(str, 2);
	exit(ex);
}

void	ft_check_argv(int argc, char **argv)
{
	if (argc != 5)
		ft_exit("more or less than 5 arguments\n", 0);
	ft_file(argv[4], 1);
	if (open(argv[1], O_RDONLY) == -1)
		ft_exit("no such file or directory\n", 0);
	if (!argv[2][0] && !argv[3][0])
		ft_exit("permission denied\n", 126);
	if (!argv[3][0])
		ft_exit("permission denied\n", 127);
	if (!argv[2][0])
		ft_exit("permission denied\n", 0);
}

char	*ft_check_path(char **path, char *cmd)
{
	int		i;
	char	*tmp;
	char	*path_part;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		path_part = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!access(path_part, F_OK | X_OK))
			return (path_part);
		free(path_part);
		i++;
	}
	return (NULL);
}

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

void	ft_exec(char *command, char **env)
{
	char	**cmmd_part;

	cmmd_part = ft_split(command, ' ');
	if (execve(ft_getpath(cmmd_part[0], env), cmmd_part, env) == -1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmmd_part[0], 2);
		ft_free(cmmd_part);
		exit(127);
	}
}
