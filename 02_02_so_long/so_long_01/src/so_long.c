/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:28:27 by jrim              #+#    #+#             */
/*   Updated: 2022/05/01 17:20:39 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		key_press(int key, t_game *game);
int		main_loop(t_game *game);
int		game_end(t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		msg_err("[usage]: ./so_long [FILENAME.ber]");
	map_read(&game, argv[1]);
	map_check(&game, game.maps.coord);
	game_init(&game);
	mlx_hook(game.win, X_EVENT_KEYPRESS, 0, &key_press, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_EXIT)
		exit(0);
	else if (key == KEY_A || key == KEY_LF)
		move(game, &game->player, DIR_LF);
	else if (key == KEY_S || key == KEY_DW)
		move(game, &game->player, DIR_DW);
	else if (key == KEY_D || key == KEY_RT)
		move(game, &game->player, DIR_RT);
	else if (key == KEY_W || key == KEY_UP)
		move(game, &game->player, DIR_UP);
	return (0);
}

int	main_loop(t_game *game)
{
	map_gen(game);
	if (game->end == 1)
		game_end(game);
	return (0);
}

int	game_end(t_game *game)
{
	ft_putstr_fd("\033[0;32mcongrats!\n\033[0;37m", 1);
	msg_dfl("total step : ", game->player.step, 0);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}