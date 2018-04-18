/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:21:50 by malberte          #+#    #+#             */
/*   Updated: 2018/04/18 21:09:45 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrimino.h"

//char g_filenames[][];

// t_tetrimino_pattern		**ft_tetrimino_new_f(const char **filenames)
// {
// 	t_tetrimino_pattern **patterns;
	
// 	while (*filenames)
// 	{
		
// 	}
// }
t_tetrimino_pattern		**ft_tetrimino_new_sstr(const char ***src)
{
	t_tetrimino_pattern **pat;
	
	size_t nb_patterns;
	int i;
	int column;
	int line;
	char c;
	
	nb_patterns = 0;
	while (*src)
	{
		nb_patterns++;
	}
	pat = (t_tetrimino_pattern**)malloc(sizeof(t_tetrimino_pattern*) * (nb_patterns + 1));
	pat[nb_patterns] = NULL;
	while (nb_patterns > 0)
	{
		--nb_patterns;
		pat[nb_patterns] = (t_tetrimino_pattern*)malloc(sizeof(t_tetrimino_pattern));
		line = 0;
		while (*src[line])
		{
			i = 0;
			column = 0;
			while ((c = *src[line][column]))
			{
				if (c == BLOCK_CHARACTER)
				{
					pat[nb_patterns]->blocks_pos[i][HEIGHT] = line;
					pat[nb_patterns]->blocks_pos[i][WIDTH] = column;
					++i;
				}
				++column;
			}
			++line;
		}
	}
	return (pat);
}