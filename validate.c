/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:18:48 by msuarez-          #+#    #+#             */
/*   Updated: 2020/01/07 15:32:34 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		check_args(char *filepath, int ac)
{
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (ac != 2)
	{
		ft_putstr_fd("You did not pass the right number of arguments.\n", 2);
		ft_putstr_fd("Usage: ./fdf file.fdf\n", 2);
		exit(0);
	}
	if (fd < 0)
	{
		ft_putstr_fd("Error: The file is invalid or does not exist!\n", 2);
		exit(0);
	}
	close(fd);
}

void		exit_error(int c)
{
	if (c == 1)
		ft_putstr_fd("Error: Map is invalid.\n", 2);
	if (c == 2)
		ft_putstr_fd("Error: mlx failed.\n", 2);
	exit(0);
}
