/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:02:13 by malberte          #+#    #+#             */
/*   Updated: 2018/04/18 20:09:08 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# define HEIGHT 0
# define WIDTH 1
# define HEIGHEST_BLOCK 0
# define LEFTMOST_BLOCK 1

typedef struct 	s_tetrimino_pattern
{
	unsigned int	blocks_pos[4][2];
	int				is_vertical;
}				t_tetrimino_pattern;

t_tetrimino_pattern		*ft_tetrimino_new(unsigned int blocks_pos[4][2]);
t_tetrimino_pattern		*ft_tetrimino_new_str(const char **src);
t_tetrimino_pattern		**ft_tetrimino_new_f(const char **filenames);


#endif