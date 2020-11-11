/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:21:39 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 12:07:57 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static char	*ft_realloc(char *ptr, size_t size)
{
	char	*new_ptr;
	int		ptr_len;
	int		i;

	if (!(new_ptr = malloc(size)))
	{
		free(ptr);
		ptr = NULL;
		return (0);
	}
	i = 0;
	ptr_len = ft_strlen(ptr);
	while (i < ptr_len)
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	new_ptr[i] = '\0';
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

static int	ft_buf_cut(char buf[BUFFER_SIZE + 1], int nl_pos)
{
	char	tmp[BUFFER_SIZE + 1];
	int		i;
	int		ret;

	ret = (buf[nl_pos] == '\n') ? GNL_OK : GNL_END;
	i = 0;
	while (buf[nl_pos + i + 1] && (nl_pos + i + 1) < BUFFER_SIZE)
	{
		tmp[i] = buf[nl_pos + i + 1];
		i++;
	}
	tmp[i] = '\0';
	i = 0;
	while (buf[i])
		buf[i++] = '\0';
	i = 0;
	while (tmp[i])
	{
		buf[i] = tmp[i];
		i++;
	}
	buf[i] = '\0';
	return (ret);
}

static int	ft_buf_cpy(char **line, char buf[BUFFER_SIZE + 1], int nl_pos)
{
	int	line_len;
	int	i;

	line_len = ft_strlen(*line);
	i = 0;
	while (i < nl_pos)
	{
		line[0][line_len + i] = buf[i];
		i++;
	}
	line[0][line_len + i] = '\0';
	return (ft_buf_cut(buf, nl_pos));
}

static int	ft_get_nl_pos(int fd, char **line, char buf[BUFFER_SIZE + 1])
{
	int	nl_pos;
	int	b_read;

	nl_pos = 0;
	while (buf[nl_pos] && buf[nl_pos] != '\n')
		nl_pos++;
	if (nl_pos == 0 && buf[0] != '\n')
	{
		b_read = read(fd, buf, BUFFER_SIZE);
		if (b_read <= 0)
			return (b_read);
		buf[BUFFER_SIZE] = '\0';
		while (buf[nl_pos] && buf[nl_pos] != '\n')
			nl_pos++;
	}
	if (!(*line = ft_realloc(*line, sizeof(char) *
										(ft_strlen(*line) + nl_pos + 1))))
		return (GNL_ERR);
	if (nl_pos == BUFFER_SIZE || buf[nl_pos] != '\n')
	{
		ft_buf_cpy(line, buf, nl_pos);
		return (ft_get_nl_pos(fd, line, buf));
	}
	return (ft_buf_cpy(line, buf, nl_pos));
}

int			get_next_line(int fd, char **line)
{
	static char buf[_SC_OPEN_MAX][BUFFER_SIZE + 1];

	if (fd == GNL_ERR || !line || BUFFER_SIZE <= 0)
		return (GNL_ERR);
	if (!(*line = malloc(sizeof(char))))
		return (GNL_ERR);
	*line[0] = '\0';
	return (ft_get_nl_pos(fd, line, buf[fd]));
}
