/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:33:24 by msuarez-          #+#    #+#             */
/*   Updated: 2020/01/08 12:07:03 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	count_words(const char *line)
{
	int		count;
	int		i;
	int		len;
	int		numcount;
	char	lastchar;

	i = 0;
	count = 0;
	numcount = 0;
	len = ft_strlen(line);
	if (len > 0)
		lastchar = line[0];
	while (i <= len)
	{
		if ((line[i] == ' ' || line[i] == '\0') && lastchar != ' ')
			count++;
		if (ft_isdigit(line[i]))
			numcount++;
		lastchar = line[i];
		i++;
	}
	if (numcount == 0)
		exit_error(1);
	return (count);
}

int			get_height(char *filepath)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(filepath, O_RDONLY);
	ret = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ret++;
		free(line);
		line = 0;
	}
	close(fd);
	return (ret);
}

int			get_width(char *filepath)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(filepath, O_RDONLY);
	ret = 0;
	get_next_line(fd, &line);
	ret = count_words(line);
	free(line);
	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (count_words(line) != ret)
			exit_error(1);
		free(line);
		line = 0;
	}
	close(fd);
	return (ret);
}
