/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rohidalg <rohidalg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:29:46 by rohidalg          #+#    #+#             */
/*   Updated: 2025/03/26 00:32:17 by rohidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_exit(char *str)
{
    ft_putstr_fd(str, 2);
    exit(0);
}

void ft_check_argv(int argc, char **argv)
{
    if (argc != 5)
        ft_exit("more or less than 5 arguments\n");
    if (!argv[3][0])
        exit(127);
}

int ft_file(char *file, int option)
{
    int tmp;

    tmp = 0;
    if (option == 0)
        tmp = open(file, O_RDONLY, 0777);
    if (option == 1)
        tmp = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (tmp == -1)
        exit(EXIT_FAILURE);
    return (tmp);
}

void ft_exec(char *command, char **env)
{
    char **cmmd_part;

    cmmd_part = ft_split(command, ' ');
    if (execve(ft_getpath(cmmd_part[0], env), cmmd_part, env) == -1)
    {
        ft_putstr_fd("command not found: ", 2);
        ft_putendl_fd(cmmd_part[0], 2);
        ft_free(cmmd_part);
        exit(127);
    }
}
// exec reemplaza la funcion para ejecutar el comando si llega a encontrarlo
