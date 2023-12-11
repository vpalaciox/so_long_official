/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:15:31 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/11 18:05:20 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_walls(t_game *game)
{
	int	vertical;
	int	horizontal;

	vertical = check_vertical_wall(game);
	horizontal = inspect_wall(game);
	if (!vertical || !horizontal)
	{
		free_map(game);
		exit(write(1, "Error\nMissing walls", 19) * 0);
	}
}

int	valid_char(char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1' || c == '0')
		return (1);
	return (0);
}

void	check_count(t_game *game)
{
	if (game->tot_carrots < 1 || game->tot_exit != 1 || game->tot_player != 1)
		exit(write(1, "Error\nInvalid chars", 19) * 0);
}

void	set_player(t_game *game, int w, int h)
{
	game->tot_player++;
	game->px = w;
	game->py = h;
}

void	check_cpe(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	game->tot_carrots = 0;
	game->tot_player = 0;
	game->tot_exit = 0;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{
			if (valid_char(game->map[h][w]) == 0)
				simple_exit(game);
			if (game->map[h][w] == 'P')
				set_player(game, w, h);
			if (game->map[h][w] == 'E' )
				game->tot_exit++;
			else if (game->map[h][w] == 'C' )
				game->tot_carrots++;
		}
	}
	check_count(game);
}
