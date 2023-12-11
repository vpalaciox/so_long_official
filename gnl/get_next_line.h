/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vanessajoypalacio@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:46:19 by vpalacio          #+#    #+#             */
/*   Updated: 2023/12/11 15:46:21 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <strings.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *backup);
char	*ft_write(char *backup);
char	*ft_backup(char *backup);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *backup, char *buff);
size_t	ft_strlen(const char *s);

#endif
