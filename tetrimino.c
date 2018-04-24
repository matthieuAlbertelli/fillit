/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:51:06 by malberte          #+#    #+#             */
/*   Updated: 2018/04/24 18:05:14 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "libft/libft.h"
#include "tetrimino.h"

// static int		check_file_size(ssize_t bytes)
// {
// 	if (bytes < TETRIMINO_INPUT_SIZE)
// 		return (0);
// 	if (bytes )
// }

static char		*read_line(int pos[NB_BLOCKS][2], int *nb_blocks, const char *buf, int height)
{
	int w;

	w = 0;
	while (w < NB_BLOCKS && buf[w])
	{
		if (buf[w] == '#')
		{
			if(*nb_blocks < NB_BLOCKS)
			{
				pos[*nb_blocks][HEIGHT] = height;
				pos[*nb_blocks][WIDTH] = w;
			}
			else 
			{
				return (NULL);
			}
			++*nb_blocks;
		}
		else if (buf[w] != '.')
		{
			printf("Un caractere autre qu'un '.' ou un '#' a ete trouve sur la ligne.\n");
			return(NULL);
		}
		++w;
	}
	if (w < NB_BLOCKS)
	{
		printf("Moins de 4 caracteres ont ete trouves sur la ligne !\n%s\n", buf);
		return(NULL);
	}
	if (buf[w] != '\n')
	{
		printf("Apres 4 caracteres, il doit y avoir un retour chariot.\nEtat du buffer: %s\n", buf);
		return (NULL);
	}
	// if (*nb_blocks == NB_BLOCKS)
	// {
	// 	printf("Plus de 4 '#' ont ete trouves.\n");
	// 	return (NULL);
	// }
	++w;
	return ((char *)(buf + w));
}

static char		*read_tetrimino(t_tetrimino **new, int *nb_tetri, const char *buf)
{
	int h;
	int nb_blocks;
	int pos[NB_BLOCKS][2];
	t_tetrimino_pattern *pat;

	h = 0;
	nb_blocks = 0;
	while (*buf && h < 4)
	{
		buf = read_line(pos, &nb_blocks, buf, h);
		if (buf == NULL)
		{
			*nb_tetri = 0;
			return (0);
		}
		h++;
		// ++buf;
	}
	// buf++;
	if (h != NB_BLOCKS)
	{
		return (NULL);
	}
	if (*buf == '\n')
	{
		buf++;
	}
	else if (*buf != '\0')
	{
		printf("Un tetrimino doit se finir soit par un retour chariot soit par la fin de fichier.\n");
		return (NULL);
	}
	pat = ft_pattern_recognition(pos);
	if (pat == NULL)
	{
		printf("Pattern non reconnu\n");
		return (NULL);
	}
	*new = (t_tetrimino*)ft_memalloc(sizeof(t_tetrimino));
	if (*new == NULL)
	{
		return (NULL);
	}
	(*new)->pattern = pat;
	(*new)->pos[HEIGHT] = 0;
	(*new)->pos[WIDTH] = 0;
	return ((char*)buf);
}

int	ft_read_tetriminos(t_tetrimino **tetri, int *nb_tetri, const char *filename)
{
	int fd;
	char buf[BUF_SIZE];
	char *pbuf;
	ssize_t bytes;
	
	if (nb_tetri == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	ft_bzero(buf, BUF_SIZE);
	bytes = read(fd, buf, BUF_SIZE - 1);
	if (bytes == -1 || bytes == 0)
		return (0);
	close(fd);
	// tetri = (t_tetrimino**) ft_memalloc(sizeof(t_tetrimino*) * (MAX_TETRIMINOS + 1));
	// if (tetri == NULL)
	// {
	// 	return (0);
	// }
	pbuf = buf;
	*nb_tetri = 0;
	while (*pbuf)
	{
		if (*nb_tetri == MAX_TETRIMINOS)
		{
			//free(tetri); FONCTION DE DESTRUCTION
			*nb_tetri = 0;
			return (0);
		}
		pbuf = read_tetrimino(&(tetri[*nb_tetri]), nb_tetri, pbuf);
		if (pbuf == 0)
		{
			//free(tetri); FONCTION DE DUSTRUCTION
			return (0);
		}
		++*nb_tetri;
	}
	return (1);
}
