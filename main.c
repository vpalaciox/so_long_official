/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:15:52 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/06 16:23:52 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	//game.height = 0;
	// game.width = 7;
	check(&game, argc, argv);
	parse(&game);
	execute(&game);
	mlx_loop(game.mlx);
}
