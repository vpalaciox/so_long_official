/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:13:59 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/11 18:14:02 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_p(t_game *game, int h, int w, char c)
{
	if (game->map[h][w - 1] == c || game->map[h - 1][w] == c ||
	game->map[h][w + 1] == c || game->map[h + 1][w] == c)
		return (1);
	return (0);
}

void	switchar(t_game *game, int h, int w)
{
	if (game->map[h][w] == '0')
		game->map[h][w] = '2';
	else if (game->map[h][w] == '2')
		game->map[h][w] = '0';
	if (game->map[h][w] == 'E')
		game->map[h][w] = 'e';
	else if (game->map[h][w] == 'e')
		game->map[h][w] = 'E';
	if (game->map[h][w] == 'C')
		game->map[h][w] = 'c';
	else if (game->map[h][w] == 'c')
		game->map[h][w] = 'C';
	return ;
}

int	ft_control_path(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{
			if ((game->map[h][w] == '0' || game->map[h][w] == 'E' ||
				game->map[h][w] == 'C') && (ft_check_p(game, h, w, 'P') ||
			ft_check_p(game, h, w, '2') || ft_check_p(game, h, w, 'c') ||
			ft_check_p(game, h, w, 'e')))
			{
				switchar(game, h, w);
				return (ft_control_path(game));
			}
		}
	}
	return (0);
}

int	ft_scan(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{
			if (game->map[h][w] == 'C' || game->map[h][w] == 'E' ||
				game->map[h][w] == '0')
				return (0);
		}
	}
	return (1);
}

void	check_path(t_game *game)
{
	int	h;
	int	w;

	ft_control_path(game);
	if (ft_scan(game))
	{
		h = -1;
		while (++h < game->height)
		{
			w = -1;
			while (++w < game->width)
			{
				if (game->map[h][w] == '2' || game->map[h][w] == 'e' ||
				game->map[h][w] == 'c')
					switchar(game, h, w);
			}
		}
		return ;
	}
	free_map(game);
	exit(write(1, "Error\nInvalid path", 19) * 0);
}
