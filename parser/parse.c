/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:08:20 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/11 15:58:53 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window
		(game->mlx, game->width * 60, game->height * 60, "so_long");
	game->moves = 0;
}

void	set_image(t_game *game)
{
	int	i;
	int	j;

	game->image.player = mlx_xpm_file_to_image
		(game->mlx, "textures/player.xpm", &i, &j);
	game->image.walls = mlx_xpm_file_to_image
		(game->mlx, "textures/walls.xpm", &i, &j);
	game->image.collectable = mlx_xpm_file_to_image
		(game->mlx, "textures/collectable.xpm", &i, &j);
	game->image.exit = mlx_xpm_file_to_image
		(game->mlx, "textures/exit.xpm", &i, &j);
	game->image.freespace = mlx_xpm_file_to_image
		(game->mlx, "textures/freespace.xpm", &i, &j);
}

void	parse(t_game *game)
{
	init(game);
	set_image(game);
}
