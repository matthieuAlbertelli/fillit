/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:10:38 by malberte          #+#    #+#             */
/*   Updated: 2018/04/22 18:49:25 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tetrimino.h"

t_tetrimino_pattern **g_patterns;

int main(void)
{
	t_tetrimino **t;
	int nb_tetri;
	int i;
	
	g_patterns = ft_read_patterns("tetriminos");
	t = ft_read_tetriminos(&nb_tetri, "snoopdog");
	if (t == NULL)
	{
		printf("error\n");
		return (0);
	}
	while (*t)
	{
		printf("name=\"%s\"\n", (*t)->pattern->name);
		++t;
	}
	// if (!t)
	// 	return (0);
	// while (*g_patterns)
	// {
	// 	printf("name= %s\ndimH= %d\ndimW= %d\n", (*g_patterns)->name, (*g_patterns)->dim[HEIGHT], (*g_patterns)->dim[WIDTH]);
	// 	i = 0;
	// 	while (i < 4)
	// 	{
	// 		printf("(%d ; %d) ", (*g_patterns)->blocks_pos[i][HEIGHT], (*g_patterns)->blocks_pos[i][WIDTH]);
	// 		++i;
	// 	}
	// 	printf("\n");
	// 	++g_patterns;
	// }
	// char A[26] = "ABCDEFGHIJKLMNO";
	// size_t n = 10;

	return (0);
}