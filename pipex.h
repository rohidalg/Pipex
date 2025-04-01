/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:24:05 by rohidalg          #+#    #+#             */
/*   Updated: 2025/04/01 13:22:21 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

//------------------------pipex.c------------------------//

char	*ft_getenv(char *name, char **env);
char	*ft_getpath(char *command, char **env);
void	ft_son(char **argv, char **env, int *fd_p);
void	ft_father(char **argv, char **env, int *fd_p);

//------------------------ft_utils.c------------------------//

void	ft_exit(char *str, int ex);
void	ft_check_argv(int argc, char **argv);
char	*ft_check_path(char **path, char *cmd);
int		ft_file(char *file, int option);
void	ft_exec(char *command, char **env);

#endif
