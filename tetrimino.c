/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:51:06 by malberte          #+#    #+#             */
/*   Updated: 2018/04/22 18:52:47 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "libft/libft.h"
#include "tetrimino.h"

// void heap_permutation_it(t_tetrimino **A, size_t n)
// {
// 	int c[n];
// 	int i;
// 	t_tetrimino *swap;

// 	i = 0;
// 	while (i < n)
// 	{
// 		c[i] = 0;
// 		++i;
// 	}

// 	printf("%s\n", A);

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (c[i] < i)
// 		{
// 			if (i % 2 == 0)
// 			{
// 				swap = A[0];
// 				A[0] = A[i];
// 				A[i] = swap;
// 			}
// 			else
// 			{
// 				swap = A[c[i]];
// 				A[c[i]] = A[i];
// 				A[i] = swap;
// 			}
// 			printf("%s\n", A);
// 			++c[i];
// 			i = 0;
// 		}
// 		else
// 		{
// 			c[i] = 0;
// 			++i;
// 		}
// 	}
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

t_tetrimino 	**ft_read_tetriminos(int *nb_tetri, const char *filename)
{
	t_tetrimino **tetri;
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
		return (NULL);
	ft_bzero(buf, BUF_SIZE);
	bytes = read(fd, buf, BUF_SIZE - 1);
	if (bytes == -1)
		return (NULL);
	close(fd);
	tetri = (t_tetrimino**) ft_memalloc(sizeof(t_tetrimino*) * MAX_TETRIMINOS);
	if (tetri == NULL)
	{
		return (0);
	}
	pbuf = buf;
	*nb_tetri = 0;
	while (*pbuf)
	{
		if (*nb_tetri == MAX_TETRIMINOS)
		{
			//free(tetri); FONCTION DE DESTRUCTION
			*nb_tetri = 0;
			return (NULL);
		}
		pbuf = read_tetrimino(&(tetri[*nb_tetri]), nb_tetri, pbuf);
		if (pbuf == NULL)
		{
			//free(tetri); FONCTION DE DUSTRUCTION
			return (NULL);
		}
		++*nb_tetri;
	}
	return (tetri);
}
