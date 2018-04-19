/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:10:38 by malberte          #+#    #+#             */
/*   Updated: 2018/04/19 18:16:21 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tetrimino.h"
#include "tetrimino_pattern.h"

int main(void)
{
	//t_tetrimino_pattern **t;
	t_tetrimino_pattern **t;
	int i;
	t = ft_read_patterns("tetriminos");
	if (!t)
		return (0);
	while (*t)
	{
		printf("name= %s\ndimH= %d\ndimW= %d\n", (*t)->name, (*t)->dim[HEIGHT], (*t)->dim[WIDTH]);
		i = 0;
		while (i < 4)
		{
			printf("(%d ; %d) ", (*t)->blocks_pos[i][HEIGHT], (*t)->blocks_pos[i][WIDTH]);
			++i;
		}
		printf("\n");
		++t;
	}
	return (0);
}