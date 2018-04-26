/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_pattern.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:21:50 by malberte          #+#    #+#             */
/*   Updated: 2018/04/26 09:19:29 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "tetrimino_pattern.h"
#include "safe_exit.h"

static int file_to_str(char *dst, const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	ft_bzero(dst, BUF_SIZE);
	if (read(fd, dst, BUF_SIZE - 1) == -1)
		return (0);
	return (1);
}

t_tetrimino_pattern **ft_read_patterns(const char *file)
{
	t_tetrimino_pattern **patterns;
	char str[BUF_SIZE];
	int k;
	unsigned int size;
	int h;
	int w;
	int nb_block;

	k = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ft_bzero(str, BUF_SIZE);
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

void ft_pattern(int pos[NB_BLOCKS][2])
{
	int block;
	int dimension;
	int extra[2];

	extra[HEIGHT] = pos[0][HEIGHT];
	extra[WIDTH] = pos[0][WIDTH];
	block = 1;
	while (block < NB_BLOCKS)
	{
		dimension = 0;
		while (dimension < 2)
		{
			if (extra[HEIGHT] > pos[block][HEIGHT])
				 extra[HEIGHT] = pos[block][HEIGHT];
			if (extra[WIDTH] > pos[block][WIDTH])
				 extra[WIDTH] = pos[block][WIDTH];
			++dimension;
		}
		++block;
	}
	block = 0;
	while (block < NB_BLOCKS)
	{
		dimension = 0;
		while (dimension < 2)
		{
			pos[block][dimension] -= extra[dimension];
			++dimension;
		}
		++block;
	}
}

t_tetrimino_pattern *ft_pattern_recognition(int pos[NB_BLOCKS][2])
{
	int block;
	int dim;
	int is_equ;
	t_tetrimino_pattern **pat;

	pat = g_patterns;
	if (pat == NULL)
		return (NULL);
	ft_pattern(pos);
	while ((*pat) != NULL)
	{
		block = 0;
		is_equ = 1;
		while (is_equ && block < NB_BLOCKS)
		{
			dim = 0;
			while (is_equ && dim < 2)
			{
				if (pos[block][dim] != (*pat)->blocks_pos[block][dim])
					is_equ = 0;
				++dim;
			}
			++block;
		}
		if (is_equ)
			return ((t_tetrimino_pattern*) (*pat));
		++pat;
	}
	return (NULL);
}
