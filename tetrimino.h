/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:43:38 by malberte          #+#    #+#             */
/*   Updated: 2018/04/19 16:45:18 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_H
# define TETRIMINO_H

#include "tetrimino_pattern.h"

typedef struct 	s_tetrimino
{
	t_tetrimino_pattern *pattern;
	int 				pos[2];
}				t_tetrimino;

t_tetrimino_pattern **ft_read_patterns(const char *file);

# endif