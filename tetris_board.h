/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_board.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:14:46 by malberte          #+#    #+#             */
/*   Updated: 2018/04/24 17:52:52 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_BOARD_H
# define TETRIS_BOARD_H

# include <stdlib.h>
# include "tetrimino.h"

# define UNAVAILABLE_SQUARE 0
# define AVAILABLE_SQUARE 1

typedef struct 	s_tetris_board
{
	char	**board;
	int 	size;
	t_tetrimino *tetriminos[MAX_TETRIMINOS];
	int nb_tetrimino;
}				t_tetris_board;

// typedef enum	e_option
// {
// 	PUT,
// 	DELETE
// }				t_option;

int ft_fill_tetrimino(	t_tetris_board *board,
						const int pos[2],
						const int tetrimino_layout[NB_BLOCKS][2]);

void ft_unblock_tetrimino(	t_tetris_board *board,
							const int pos[2],
							const int tetrimino_layout[NB_BLOCKS][2]);

int	ft_next_available_square(	int next_pos[2],
								const t_tetrimino *tetrimino,
								const t_tetris_board *board);

int ft_solve_fillit(t_tetris_board *board);
void ft_print_solution(const t_tetris_board *board);							
#endif