/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:06:40 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/11 18:15:03 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_args(int argc)
{
	if (argc != 2)
		exit(write(1, "Error\nargc != 2", 15) - 14);
}

void	check_ber(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (!(file[i - 1] == 'r' && file[i - 2] == 'e'
			&& file[i - 3] == 'b' && file[i - 4] == '.'))
		exit(write(1, "Error\nFormat file is invalid", 28) - 27);
}

void	set_height(t_game *game, char *file_name)
{
	int		fd;
	char	*str;

	game->height = 0;
	fd = open(file_name, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		return ;
	game->height++;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if (!str)
			break ;
		game->height++;
	}
	close(fd);
	free(str);
}

void	check_rectangular(t_game *game)
{
	int	i;
	int	len;

	if (game->map[0] == NULL)
		clean_exit(game, "Error\nEmpty map!\n");
	i = 0;
	game->width = (int)ft_strlen(game->map[0]) - 1;
	while (i < game->height && game->map[i])
	{
		len = (int)ft_strlen(game->map[i]) - 1;
		if ((len != game->width && i != game->height - 1)
			|| (i == game->height - 1 && len != game->width - 1))
		{
			free_map(game);
			exit(write(1, "Error\nNon-rectangular map!\n", 28));
		}
		i++;
	}
}

void	check(t_game *game, int argc, char **argv)
{
	check_args(argc);
	check_ber(argv[1]);
	set_height(game, argv[1]);
	set_map(game, argv[1]);
	check_rectangular(game);
	check_walls(game);
	check_cpe(game);
	check_path(game);
}
