/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:06:25 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/11 18:14:14 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_linux/mlx.h"
# include "./gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define W 119
# define A 97
# define ESC 65307
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_image
{
	void	*player;
	void	*collectable;
	void	*freespace;
	void	*walls;
	void	*exit;
}			t_image;

typedef struct s_game
{
	t_image			image;
	void			*mlx;
	void			*mlx_window;
	int				width;
	int				height;	
	int				px;
	int				py;
	int				tot_carrots;
	int				tot_player;
	int				tot_exit;
	char			**map;
	int				moves;
}			t_game;

void	check(t_game *game, int argc, char **argv);
size_t	ft_strlen(const char *str);
void	parse(t_game *game);
void	execute(t_game *game);
int		move(int keycode, t_game *game);
int		exit_x(void);
void	draw_map(t_game *game);
void	set_map(t_game *game, char *file_name);
void	ft_background(t_game *game, void *image, int w, int h);
int		inspect_wall(t_game *game);
int		check_vertical_wall(t_game *game);
char	*ft_strjoin1(char const *s1, char const *s2);
char	*ft_itoa(int n);
void	check_walls(t_game *game);
void	check_cpe(t_game *game);
void	init(t_game *game);
void	free_map(t_game *game);
void	simple_exit(t_game *game);
void	clean_exit(t_game *game, char *msg);
void	check_path(t_game *game);

#endif