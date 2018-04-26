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

void	ft_on_error(void *data, void (*fdel)(void **data))
{
	ft_putstr(ERR_MSG);
	if (!(data == NULL || fdel == NULL))
		(*fdel)(&data);
	exit(0);
}
