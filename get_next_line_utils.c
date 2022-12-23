/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:18:24 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/23 13:19:59 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		p;

	p = 0;
	str = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (*str));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	while (s1[p])
	{
		str[p] = s1[p];
		p++;
	}
	while (*s2)
	{
		str[p] = *s2;
		p++;
		s2++;
	}
	str[p] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	p;

	p = 0;
	str = malloc ((len + 1) * sizeof (*str));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	while (s[start + p] && p < len)
	{
		str[p] = s[start + p];
		p++;
	}
	str[p] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	letter;

	letter = (char) c;
	while (*s != letter)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *) s);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strlen_n(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}
