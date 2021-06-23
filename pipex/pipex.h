/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:37:36 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/23 15:03:21 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define FILE1 av[1]
# define FILE2 av[4]
# define CMD1 av[2]
# define CMD2 av[3]

typedef struct	s_cmd
{
	char	*cmd[5];
	char	**av;
	char	**en;
}				t_cmd;

void		print_error(char *err);

char		**ft_split(char *str);
char		*ft_strjoin(char *s1, char *s2);

#endif
