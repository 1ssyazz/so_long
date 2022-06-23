/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:14:21 by msukri            #+#    #+#             */
/*   Updated: 2022/02/17 19:24:03 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}	

void	*ft_calloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != (char)c)
		if (!str[i++])
			return (NULL);
	return ((char *)&str[i]);
}

char	*ft_solve_n_line(ssize_t r, char **n_line, char **tmp)
{
	char	*line;

	line = NULL;
	if (r == 0)
		line = ft_strdup(*n_line);
	else if (r > 0)
		line = ft_substr(*n_line, 0, (ft_strchr(*n_line, '\n') - *n_line + 1));
	*tmp = ft_strdup(*n_line + (ft_strlen(line)));
	ft_memfree((void **)n_line);
	*n_line = *tmp;
	if (r <= 0)
		ft_memfree((void **)n_line);
	if (!*line)
		ft_memfree((void **)&line);
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t		r;
	char		buf[BUFFER_SIZE + 1];
	static char	*n_line = NULL;
	char		*tmp;

	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (n_line == NULL)
		n_line = ft_calloc(1 * sizeof(char));
	while (!ft_strchr(n_line, '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
		{
			ft_memfree((void **)&n_line);
			return (NULL);
		}
		buf[r] = '\0';
		tmp = ft_strjoin(n_line, buf);
		ft_memfree((void **)&n_line);
		n_line = tmp;
	}
	return (ft_solve_n_line(r, (char **)&n_line, &tmp));
}
