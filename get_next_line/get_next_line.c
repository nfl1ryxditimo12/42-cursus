/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:42:10 by seonkim           #+#    #+#             */
/*   Updated: 2021/05/20 13:20:16 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nextstr(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	if (!(ret = malloc(ft_strlen(str) - i + 1)))
		return (0);
	i++;
	while (str[i])
		ret[j++] = str[i++];
	ret[j] = 0;
	free(str);
	return (ret);
}

char	*ft_linecpy(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(ret = malloc(i + 1)))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	int			byte;
	char		*buf;
	static char	*set[OPEN_MAX];

	byte = 1;
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_newline(set[fd]) && byte != 0)
	{
		if ((byte = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[byte] = 0;
		set[fd] = ft_strjoin(set[fd], buf);
	}
	free(buf);
	*line = ft_linecpy(set[fd]);
	set[fd] = ft_nextstr(set[fd]);
	if (byte == 0)
		return (0);
	return (1);
}
