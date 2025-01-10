/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:16:16 by arosa-di          #+#    #+#             */
/*   Updated: 2025/01/09 21:41:22 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libft/libft.h"

char	*find_paths(char *cmd, char **envp);
char	*checks_paths(char **paths, char *cmd);
void	ft_free(char **paths);
void	ft_exec(char *argv, char **envp);
int		check(int argc);

#endif