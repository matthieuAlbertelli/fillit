/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_pattern.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:02:13 by malberte          #+#    #+#             */
/*   Updated: 2018/04/20 22:50:09 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

#include <stdlib.h>

# define HEIGHT 0
# define WIDTH 1
# define HEIGHEST_BLOCK 0
# define LEFTMOST_BLOCK 1
# define NB_BLOCKS 4
# define BLOCK_CHARACTER '#'
# define BUF_SIZE 2000

typedef struct 	s_tetrimino_pattern
{
	unsigned int	blocks_pos[NB_BLOCKS][2];
//	int				is_vertical;
	char			name[3];
	int 			dim[2];
}				t_tetrimino_pattern;

extern t_tetrimino_pattern **g_patterns;

t_tetrimino_pattern **ft_read_patterns(const char *file);
void ft_pattern(int **pos);
t_tetrimino_pattern *ft_pattern_recognition(const t_tetrimino_pattern *patterns, unsigned int pos[NB_BLOCKS][2]);

#endif