/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:51:06 by malberte          #+#    #+#             */
/*   Updated: 2018/04/19 18:18:42 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "tetrimino.h"
#include "./libft/libft.h"

#define BUF_SIZE 2000

t_tetrimino_pattern **ft_read_patterns(const char *file)
{
	t_tetrimino_pattern **patterns;
	char str[BUF_SIZE];
	int fd;
	int k;
	unsigned int size;
	int h;
	int w;
	int nb_block;

	k = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (read(fd, str, BUF_SIZE - 1) == -1)
		return (NULL);
	size = ft_atoi(str);
	if (!(patterns = (t_tetrimino_pattern **)ft_memalloc(sizeof(t_tetrimino_pattern *) * size + 1)))
		return (NULL);
	patterns[size] = NULL;
	k += 3;
	while (str[k])
	{
		--size;
		if (!(patterns[size] = (t_tetrimino_pattern *)ft_memalloc(sizeof(t_tetrimino_pattern))))
			return (NULL);
		ft_strncpy(patterns[size]->name, str + k, 2);
		k += 3;
		patterns[size]->dim[HEIGHT] = ft_atoi(str + k);
		k += 2;
		patterns[size]->dim[WIDTH] = ft_atoi(str + k);
		k += 2;
		nb_block = 0;
		h = -1;
		while (++h < patterns[size]->dim[HEIGHT])
		{
			w = -1;
			while (++w < patterns[size]->dim[WIDTH])
			{
				if (str[k] == '#')
				{
					patterns[size]->blocks_pos[nb_block][HEIGHT] = h;
					patterns[size]->blocks_pos[nb_block][WIDTH] = w;
					nb_block++;
				}
				k++;
			}
			k++;
		}
	}
	return (patterns);
}