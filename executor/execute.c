/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:50:35 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/07 17:37:19 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_move(t_game *game)
{
	char	*str;
	char	*str1;

	str1 = ft_itoa(game->moves + 1);
	str = ft_strjoin1("Number of moves: ", str1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
	free(str1);
	game->moves++;
}

void	move_player(t_game *game, int new_y, int new_x)
{
	game->map[new_y][new_x] = 'P';
	game->map[game->py][game->px] = '0';
	game->py = new_y;
	game->px = new_x;
	draw_map(game);
	print_move(game);
}

void	check_move(t_game *game, int y, int x)
{
	int	new_x;
	int	new_y;

	new_x = game->px + x;
	new_y = game->py + y;
	//printf("new_x: %d, new_y: %d\n", new_x, new_y);
	if (game->map[new_y][new_x] == '0')
		move_player(game, new_y, new_x);
	if (game->map[new_y][new_x] == 'C')
	{
		move_player(game, new_y, new_x);
		game->tot_carrots--;
	}
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E')
	{
	//	printf("%d\n", game->tot_carrots);
		if (game->tot_carrots == 0)
			clean_exit(game, "YOU WIN!!!\n");
			// exit_player();
	}
}

int	move(int keycode, t_game *game)
{
	//printf("PRE MOVE| x: %d, y: %d\n", game->px, game->py);
	if (keycode == S || keycode == DOWN)
		check_move(game, 1, 0);
	if (keycode == D || keycode == RIGHT)
		check_move(game, 0, 1);
	if (keycode == W || keycode == UP)
		check_move(game, -1, 0);
	if (keycode == A || keycode == LEFT)
		check_move(game, 0, -1);
	else if (keycode == ESC)
		exit(write(1, "Player left the game!", 21) * 0);
	//printf("AFTER MOVE | x: %d, y: %d\n", ciao->px, ciao->py);
	//print_move(game);
	return (0);
}

// int	move(int keycode, t_game *game)
// {
// 	printf("PRE MOVE| x: %d, y: %d\n", game->px, game->py);
// 	if (keycode == S || keycode == DOWN)
// 	{
// 		game->py +=60;
// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->image.player, game->px, game->py);
// 	}
// 	if (keycode == D || keycode == RIGHT)
// 	{
// 		game->px +=60;
// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->image.player, game->px, game->py);
// 	}
// 	if (keycode == W || keycode == UP)
// 	{
// 		game->py -=60;
// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->image.player, game->px, game->py);
// 	}
// 	if (keycode == A || keycode == LEFT) 
// 	{
// 		game->px -=60;
// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->image.player, game->px, game->py);
// 	}
// 	else if (keycode == ESC)
// 		exit(write(1, "Player left the game!", 21) * 0);
// 	//printf("AFTER MOVE | x: %d, y: %d\n", ciao->px, ciao->py);
// 	print_move(game);
// 	return (0);
// }



void	execute(t_game *game)
{
	//printf("START pos| x: %d, y: %d\n", game->px, game->py);
	// game->px = 30;
	// game->py = 30;
	draw_map(game);
//	print_move(game); // stampa il n mosse
//	printf(">>>>%s\n", game->map[1]);
//	printf("h:%d w:%d \n", game->height, game->width);
	mlx_key_hook(game->mlx_window, move, game);
	mlx_hook(game->mlx_window, 17, 0, exit_x, game);
	mlx_loop(game->mlx);
}
