/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:46:15 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/06 17:20:08 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>

//GET_NEXT_LINE_UTILS
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strlen_n(char *str);
//GET_NEXT_LINE
char	*ft_get_next_line(int fd);
//CHECK
char	*ft_strnstr(const char *b, const char *l, size_t len);
int		ft_number_columns(int fd);
int		ft_number_rows(int fd);
void	ft_check_walls(char **content, int rows, int columns);
char	**ft_create_content(int fd, int rows);
int		ft_control_char(char **content, int rows, int columns);
//DISPLAY
void	ft_create_map(char **content, int rows, int columns, mlx_t *mlx);

#endif