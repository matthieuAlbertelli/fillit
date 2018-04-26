/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:50:18 by malberte          #+#    #+#             */
/*   Updated: 2018/04/26 09:20:23 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "safe_exit.h"
#include "tetris_board.h"

#define ERR_MSG "error\n"

int ft_free_pattern(t_tetrimino_pattern ***p_patterns)
{
	int i;

	while ((*p_patterns)[i])
	{
		ft_memdel((void **)&((*p_patterns)[i]));
		i++;
	}
	return (i);
}

/*
void ft_safe_free_pattern(t_tetrimino_pattern ***p_patterns, int size)
{
	size = ft_free_pattern(p_patterns);
}
*/

void ft_free_tetris_board(t_tetris_board *tetris)
{
	int i;

	ft_free_tetri(tetris->tetriminos, &(tetris->nb_tetrimino));
	i = 0;
	while (i < tetris->size)
	{
		ft_memdel((void**)&tetris->board[i]);
		++i;
	}
	ft_memdel((void**)&(tetris->board));
}

void ft_free_tetri(t_tetrimino **tetri)
{
	int i;

	i = 0;
	while (i < MAX_TETRIMINOS)
	{
		ft_memdel((void **)&(tetri[i]));
		i++;
	}
}


void *ft_safe_malloc(size_t mem_size, void (*fdel)(void **data, int size))
{
	void *data;
	// if (!(patterns = (void **)ft_memalloc(sizeof(data_size) * size + 1)))
	data = (void *)ft_memalloc(mem_size);
	if (data == NULL)
		ft_on_error();
	g_safe_memory.safe_memory[g_safe_memory.nb_malloc].data = data;
	g_safe_memory.safe_memory[g_safe_memory.nb_malloc].fdel = &fdel;
	g_safe_memory.nb_malloc++;
	return (data);
}

/*
**	void	ft_init_data();
**	t_safe_memory data;
**	data = g_safe_memory;
*/

void ft_on_error()
{
	ft_putstr(ERR_MSG);
	--g_safe_memory.nb_malloc++;
	while (g_safe_memory.nb_malloc >= 0)
	{
		g_safe_memory.safe_memory[g_safe_memory.nb_malloc].fdel(g_safe_memory.safe_memory[g_safe_memory.nb_malloc].data)
		g_safe_memory.nb_malloc--;
	}
	exit(0);
}
