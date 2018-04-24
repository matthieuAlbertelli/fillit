/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_board.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:14:46 by malberte          #+#    #+#             */
/*   Updated: 2018/04/24 17:31:53 by malberte         ###   ########.fr       */
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
	t_tetrimino *tetriminos;
	int nb_tetrimino;
}				t_tetris_board;

// typedef enum	e_option
// {
// 	PUT,
// 	DELETE
// }				t_option;



#endif