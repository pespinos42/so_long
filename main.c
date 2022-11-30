/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:30:10 by pespinos          #+#    #+#             */
/*   Updated: 2022/11/30 17:15:16 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 10
// #endif
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include "MLX42/include/MLX42/MLX42.h"

// //CABECERAS---------------------------------------------------------------------
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strchr(const char *s, int c);
// size_t	ft_strlen(const char *s);
// char	*ft_get_next_line(int fd);

// //GET_NEXT_LINE_UTILS-----------------------------------------------------------
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	int		p;

// 	p = 0;
// 	str = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (*str));
// 	if (!str)
// 	{
// 		free (str);
// 		return (NULL);
// 	}
// 	while (s1[p])
// 	{
// 		str[p] = s1[p];
// 		p++;
// 	}
// 	while (*s2)
// 	{
// 		str[p] = *s2;
// 		p++;
// 		s2++;
// 	}
// 	str[p] = '\0';
// 	return (str);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*str;
// 	size_t	p;

// 	p = 0;
// 	str = malloc ((len + 1) * sizeof (*str));
// 	if (!str)
// 	{
// 		free (str);
// 		return (NULL);
// 	}
// 	while (s[start + p] && p < len)
// 	{
// 		str[p] = s[start + p];
// 		p++;
// 	}
// 	str[p] = '\0';
// 	return (str);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	char	letter;

// 	letter = (char) c;
// 	while (*s != letter)
// 	{
// 		if (*s == '\0')
// 			return (NULL);
// 		s++;
// 	}
// 	return ((char *) s);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }


// //GET_NEXT_LINE-----------------------------------------------------------------
// char	*ft_join_free(char *buffer, char *str)
// {
// 	char	*temp;

// 	temp = ft_strjoin(buffer, str);
// 	free (buffer);
// 	return (temp);
// }

// char	*ft_total_line(char *buffer, int fd)
// {
// 	int		bytes;
// 	char	*str;

// 	bytes = 1;
// 	str = malloc ((BUFFER_SIZE + 1) * sizeof (*str));
// 	if (!str)
// 	{
// 		free (str);
// 		return (NULL);
// 	}
// 	while (bytes > 0 && !ft_strchr(buffer, '\n'))
// 	{
// 		bytes = read(fd, str, BUFFER_SIZE);
// 		if (bytes < 0)
// 		{
// 			free (str);
// 			free (buffer);
// 			return (NULL);
// 		}
// 		str[bytes] = '\0';
// 		buffer = ft_join_free(buffer, str);
// 	}
// 	free (str);
// 	return (buffer);
// }

// char	*ft_to_nl(char *buffer)
// {
// 	int	nl;

// 	nl = 0;
// 	if (!*buffer)
// 		return (NULL);
// 	while (buffer[nl] && buffer[nl] != '\n')
// 		nl++;
// 	nl++;
// 	return (ft_substr(buffer, 0, nl));
// }

// char	*ft_from_nl(char *buffer)
// {
// 	int		nl;
// 	int		len;
// 	char	*str;

// 	nl = 0;
// 	len = 0;
// 	while (buffer[nl] && buffer[nl] != '\n')
// 		nl++;
// 	if (!buffer[nl])
// 	{
// 		free (buffer);
// 		return (NULL);
// 	}
// 	nl++;
// 	len = ft_strlen(&buffer[nl]);
// 	str = ft_substr(buffer, nl, len);
// 	free (buffer);
// 	return (str);
// }

// char	*ft_get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*str;

// 	if (!buffer)
// 	{
// 		buffer = malloc (1 * sizeof (*buffer));
// 		if (!buffer)
// 		{
// 			free (buffer);
// 			return (NULL);
// 		}
// 		*buffer = 0;
// 	}
// 	buffer = ft_total_line(buffer, fd);
// 	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
// 	{
// 		free (buffer);
// 		return (NULL);
// 	}
// 	str = ft_to_nl(buffer);
// 	buffer = ft_from_nl(buffer);
// 	return (str);
// }


//MAIN--------------------------------------------------------------------------
int	main(int argc, char **argv)
{
	int		fd;
	char	*str;

	fd = 0;
	str = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		str = ft_get_next_line(fd);
		while (str)
		{
			printf("%s", str);
			str = ft_get_next_line(fd);
		}
	}
	return (0);
}
