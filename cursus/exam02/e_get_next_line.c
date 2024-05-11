/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_get_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonkim <seonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:43:17 by seonkim           #+#    #+#             */
/*   Updated: 2021/06/14 17:32:01 by seonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 3

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (!dst && !src)
		return (0);
	if (s2 < s1)
	{
		while (len--)
			*(s1 + len) = *(s2 + len);
		return (dst);
	}
	while (len--)
		*(s1++) = *(s2++);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	if (!s1 && !s2)
		return (0);
	if (!(ret = malloc(s1_len + s2_len + 1)))
		return (0);
	ft_memmove(ret, s1, s1_len);
	ft_memmove(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = 0;
	free((char *)s1);
	return (ret);
}

int		ft_newline(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

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
	static char	*set;

	byte = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!ft_newline(set) && byte != 0)
	{
		if ((byte = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[byte] = 0;
		set = ft_strjoin(set, buf);
	}
	free(buf);
	*line = ft_linecpy(set);
	set = ft_nextstr(set);
	if (byte == 0)
		return (0);
	return (1);
}

int main()
{
	int fd;
	int i;
	char *line;

	fd = open("test", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	//printf("%s\n", line);
	//free(line);
	close(fd);
}
