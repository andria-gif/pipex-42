/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:16:23 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/09 22:31:18 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_paths(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
				return (NULL);
			path = checks_paths(paths, cmd);
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*checks_paths(char **paths, char *cmd)
{
	char	*paths_part;
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		if (!path)
			return (NULL);
		paths_part = ft_strjoin(path, cmd);
		if (!paths_part)
			return (NULL);
		if (access(paths_part, F_OK | X_OK) == 0)
			return (paths_part);
		i++;
	}
	return (NULL);
}

void	ft_free(char **paths)
{
	int	i;

	i = 0;
	if (paths)
	{
		i = 0;
		while (paths[i])
		{
			free(paths[i]);
			i++;
		}
		free(paths);
	}
}

void	ft_exec(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		perror("comand not faund");
		exit(127);
	}
	path = find_paths(*cmd, envp);
	if (!path)
	{
		ft_free(&path);
		perror("Command not found");
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free(&path);
		ft_free(cmd);
		perror("Command not");
		exit(EXIT_FAILURE);
	}
}

int	check(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Bad request", 2);
		ft_putstr_fd("./pipex <file> <cmd1> <cmd2> <file2>", 1);
		exit(1);
	}
	return (0);
}
