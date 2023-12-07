/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:41:35 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/07 18:52:32 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_x(void)
{
	write(1, "Player exited the game!", 23);
	exit (0);
}

void	ft_background(t_game *game, void *image, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->image.freespace, w * 60, h * 60);
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		image, w * 60, h * 60);
}

void	draw_map(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{
			if (game->map[h][w] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->image.freespace, w * 60, h * 60);
			if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->image.walls, w * 60, h * 60);
			if (game->map[h][w] == 'C')
				ft_background(game, game->image.collectable, w, h);
			if (game->map[h][w] == 'E')
				ft_background(game, game->image.exit, w, h);
			if (game->map[h][w] == 'P')
				ft_background(game, game->image.player, w, h);
		}
	}
}
