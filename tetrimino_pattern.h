/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_pattern.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:02:13 by malberte          #+#    #+#             */
/*   Updated: 2018/04/19 16:39:32 by malberte         ###   ########.fr       */
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

typedef struct 	s_tetrimino_pattern
{
	unsigned int	blocks_pos[NB_BLOCKS][2];
//	int				is_vertical;
	char			name[3];
	int 			dim[2];
}				t_tetrimino_pattern;



#endif