/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:02:13 by malberte          #+#    #+#             */
/*   Updated: 2018/04/18 21:09:49 by malberte         ###   ########.fr       */
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

//extern char 			*g_filenames[];

typedef struct 	s_tetrimino_pattern
{
	unsigned int	blocks_pos[NB_BLOCKS][2];
	int				is_vertical;
}				t_tetrimino_pattern;

t_tetrimino_pattern		*ft_tetrimino_new(unsigned int *blocks_pos[4][2]);
t_tetrimino_pattern		*ft_tetrimino_new_str(const char *src);
t_tetrimino_pattern		**ft_tetrimino_new_sstr(const char ***src);
t_tetrimino_pattern		**ft_tetrimino_new_f(const char **filenames);

#endif