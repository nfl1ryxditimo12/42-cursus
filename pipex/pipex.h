/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:37:36 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/23 17:32:29 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define MEM_ERR "Memory Error"
# define CMD_ERR "Invalid Command"

typedef struct	s_cmd
{
	char	*cmd[5];
	char	**av;
	char	**en;
}				t_cmd;

void			print_error(char *err);

char			**ft_split(char *str);
char			*ft_strjoin(char *s1, char *s2);

#endif
