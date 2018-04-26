/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 08:50:00 by malberte          #+#    #+#             */
/*   Updated: 2018/04/26 09:25:46 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFE_EXIT_H
# define SAFE_EXIT_H

void	ft_on_error(void *data, void (*fdel)(void **data));

#endif