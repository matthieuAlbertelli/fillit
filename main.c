/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:10:38 by malberte          #+#    #+#             */
/*   Updated: 2018/04/25 02:31:34 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "tetris_board.h"

t_tetrimino_pattern **g_patterns;

int main(int argc, char **argv)
{
	t_tetris_board board;

	int i;
	// int i;
	(void)argc;
	(void)argv;
	
	g_patterns = ft_read_patterns("tetriminos");
	
	if (!ft_read_tetriminos(board.tetriminos, &(board.nb_tetrimino), "snoopdog.txt"))
	{
		printf("error\n");
		return (0);
	}
	board.size = 8;
	board.board = (char**)ft_memalloc(sizeof(char*) * MAX_TETRIMINOS * NB_BLOCKS);
	i = 0;
	while (i < MAX_TETRIMINOS * NB_BLOCKS)
	{
		board.board[i] = (char*)ft_memalloc(sizeof(char) * MAX_TETRIMINOS * NB_BLOCKS);
		ft_memset(board.board[i], 1, MAX_TETRIMINOS * NB_BLOCKS);
		++i;
	}
	if (!ft_solve_fillit(&board))
	{
		printf("error\n");
		return (0);
	}
	ft_print_solution(&board);
	// ft_memdel(board.board);
	// if (t == NULL)
	// {
	// 	printf("error\n");
	// 	return (0);
	// }
	// while (*t)
	// {
	// 	printf("name=\"%s\"\n", (*t)->pattern->name);
	// 	++t;
	// }
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