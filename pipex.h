/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:24:05 by rohidalg          #+#    #+#             */
/*   Updated: 2025/03/06 14:09:05 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>

//------------------------pipex.c------------------------//

char	*ft_getenv(char *name, char **env);
char	*ft_getpath(char *command, char **env);
void	ft_check_argv(int argc);
void	ft_exit(char *str);
void	ft_exec(char *command, char **env);
int		ft_file(char *file, int option);
// void	ft_father(char **argv)//, char **env);
void	ft_son(char **argv)//, char **env);

#endif
