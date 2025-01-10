/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:29:24 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/09 22:30:15 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	son_process1(char **argv, char **envp, int *fd);
static void	son_process2(char **argv, char **envp, int *fd);
static int	ft_open_file(const char *fileopen, int mode);

static void	exit_failure(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

static void	son_process1(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = ft_open_file(argv[1], O_RDONLY);
	if (filein == -1)
	{
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1 || dup2(filein, STDIN_FILENO) == -1)
	{
		perror("Error verifying file descriptors1");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	close(fd[1]);
	close(filein);
	ft_exec(argv[2], envp);
}

static void	son_process2(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = ft_open_file(argv[4], O_WRONLY);
	if (fileout == -1)
	{
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(fileout, STDOUT_FILENO) == -1)
	{
		perror("Error verifying file descriptors2");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	close(fd[1]);
	close(fileout);
	ft_exec(argv[3], envp);
}

static int	ft_open_file(const char *fileopen, int mode)
{
	int	file;

	file = -1;
	if (mode == O_RDONLY)
		file = open(fileopen, O_RDONLY, 0644);
	else if (mode == O_WRONLY)
		file = open(fileopen, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		perror("ERROR OPENING FILE");
		exit(EXIT_FAILURE);
	}
	return (file);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	check(argc);
	if (pipe(fd) == -1)
		exit_failure("Error creating pipe");
	pid1 = fork();
	if (pid1 == -1)
		exit_failure("Error creating fork");
	if (pid1 == 0)
	{
		close(fd[0]);
		son_process1(argv, envp, fd);
	}
	pid2 = fork();
	if (pid2 == -1)
		exit_failure("Error creating fork");
	if (pid2 == 0)
	{
		close(fd[1]);
		son_process2(argv, envp, fd);
	}
	close(fd[0]);
	close(fd[1]);
}
