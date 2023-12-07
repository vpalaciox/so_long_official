/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:15:31 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/07 18:51:57 by vpalacio         ###   ########.fr       */
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
	printf("dopo walls\n");
}

int	valid_char(char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1' || c == '0')
		return (1);
	printf(">");
	return (0);
}

// The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
void	check_count(t_game *game)
{
	if (game->tot_carrots < 1 || game->tot_exit != 1 || game->tot_player != 1)
		exit(write(1, "Error\nInvalid chars", 19) * 0);
}

// deve essere presente esattamente 1 collectable, 1 player e 1 exit
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
			{
				free_map(game);
				exit(write(1, "Error\nInvalid charsssssss", 19) * 0);
			}
			if (game->map[h][w] == 'P')
			{
				game->tot_player++;
				game->px = w;
				game->py = h;
			}
			if (game->map[h][w] == 'E' )
				game->tot_exit++;
			else if (game->map[h][w] == 'C' )
				game->tot_carrots++;
		}
	}
	check_count(game);
   // printf("CHECK CPE pos| x: %d, y: %d\n", game->px, game->py);
}
