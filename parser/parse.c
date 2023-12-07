/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:08:20 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/07 19:01:42 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_map(t_game *game)
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

void	init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window
		(game->mlx, game->width * 60, game->height * 60, "so_long");
	game->moves = 0;
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
		mlx_destroy_image(game->mlx,game->image.exit);
	if (game->image.freespace != NULL)
		mlx_destroy_image(game->mlx, game->image.freespace);
	if (game->mlx != NULL)
		mlx_destroy_window(game->mlx, game->mlx_window);
	free(game->mlx);
	printf("DOPO FREE IMG\n");
	if (game->map != NULL)
	{
		while (i < game->height && game->map[i] != NULL)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	printf("DOPO FREE MAP\n");
	exit(write(1, msg, ft_strlen(msg)));
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

void	set_map(t_game *game, char *file_name)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	printf("SET MAP: game->height%d\n",game->height);
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
	printf("dopo map\n");
}

void	parse(t_game *game)
{
	init(game);
	set_image(game);
}
