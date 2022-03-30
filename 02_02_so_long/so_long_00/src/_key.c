/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _key.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:06:36 by jrim              #+#    #+#             */
/*   Updated: 2022/03/30 17:22:15 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     key_press(int key, t_game *game);
void    _up(t_game *game);
void    _down(t_game *game);
void    _left(t_game *game);
void    _right(t_game *game);


int     key_press(int key, t_game *game)
{
    if (key == KEY_EXIT)
		exit(0);
    else if (key == KEY_A || key == KEY_LF)
        _left(game);
    else if (key == KEY_S || key == KEY_DW)
        _down(game);
    else if (key == KEY_D || key == KEY_RT)
        _right(game);
    else if (key == KEY_W || key == KEY_UP)
        _up(game);
	return (0);
}

void    _up(t_game *game)
{
    if (game)
        printf("up\n");
}

void    _down(t_game *game)
{
    if (game)
        printf("down\n");
}

void    _left(t_game *game)
{
    if (game)
        printf("left\n");
}

void    _right(t_game *game)
{
    if (game)
        printf("right\n");
}