/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:47:30 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/11 15:59:21 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height && game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	clean_exit(t_game *game, char *msg)
{
	int	i;

	i = 0;
	if (game->image.player != NULL)
		mlx_destroy_image(game->mlx, game->image.player);
	if (game->image.walls != NULL)
		mlx_destroy_image(game->mlx, game->image.walls);
	if (game->image.collectable != NULL)
		mlx_destroy_image(game->mlx, game->image.collectable);
	if (game->image.exit != NULL)
		mlx_destroy_image(game->mlx, game->image.exit);
	if (game->image.freespace != NULL)
		mlx_destroy_image(game->mlx, game->image.freespace);
	if (game->mlx != NULL)
		mlx_destroy_window(game->mlx, game->mlx_window);
	free(game->mlx);
	if (game->map != NULL)
	{
		while (i < game->height && game->map[i] != NULL)
		{
			free(game->map[i++]);
		}
		free(game->map);
	}
	exit(write(1, msg, ft_strlen(msg)));
}

void	set_map(t_game *game, char *file_name)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->height));
	if (game->map == NULL)
		exit(write(1, "Error\n404 (game fail initialization)", 37) * 0);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(write(1, "Error\n404 (game fail initialization)", 37) * 0);
	str = get_next_line(fd);
	while (str)
	{
		game->map[i++] = str;
		str = get_next_line(fd);
	}
	close(fd);
}
