/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:50:00 by malberte          #+#    #+#             */
/*   Updated: 2018/04/26 08:53:11 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFE_EXIT_H
# define SAFE_EXIT_H

#define NB_MALLOC 3
#define FREE_G_PATTERN 0
#define FREE_T_TETRIMINOS 1
#define FREE_T_TETRIS_BOARD 2

typedef struct	s_free_data
{
	void		*data;
	void		(*fdel)(void **data, int *nb);
}				t_free_data;

typedef struct	s_safe_memory
{
	t_free_data safe_memory[NB_MALLOC];
	int			nb_malloc;
}				t_safe_memory;

/*
**	g_pattern **g_patterns;
**	t_tetrimino **tetri;
**	t_tetris_board *board;
*/

extern t_safe_memory g_safe_memory;

void	ft_on_error(void *data, void (*fdel)(void **data, int size));
void	*ft_safe_malloc(void** data);

#endif