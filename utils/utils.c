/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:49:39 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/06 14:53:51 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	n_len(int num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*init_str(int n)
{
	char	*str;
	int		len;

	len = n_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[len] = '\0';
		return (str);
	}
	else
	{
		str[len] = 0;
		return (str);
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = n_len(n);
	str = init_str(n);
	if (!str)
		return (NULL);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
