/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_board.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:14:46 by malberte          #+#    #+#             */
/*   Updated: 2018/04/19 14:30:23 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_BOARD_H
# define TETRIS_BOARD_H

#include <stdlib.h>

#include "libft/libft.h"

typedef struct 	s_tetris_board
{
	char	**board;
	size_t 	height;
	size_t	width;
	t_list	*solution;
}				t_tetris_board;

#endif