/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:36:50 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/11 18:03:16 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (1 + ft_strlen(s1) + (ft_strlen(s2))));
	if (!str)
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (j < (int)ft_strlen(s2))
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

void	simple_exit(t_game *game)
{
	free_map(game);
	exit(write(1, "Error\nInvalid chars", 19) * 0);
}

int	inspect_wall(t_game *game)
{
	int	i;
	int	j;

	i = game->width - 1;
	j = 0;
	while (j < i)
	{
		if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_vertical_wall(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	w = game->width;
	while (h < game->height)
	{
		if (!(game->map[h][0] == '1' && game->map[h][w - 1] == '1'))
		{
			return (0);
		}
		h++;
	}
	return (1);
}
