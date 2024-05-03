/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:51:31 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/04/07 21:24:22 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	find_nl(const char *str)
{
	int	i;

	if (!str)
		return (-11);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	_strjoin(char **remain, char *buffer)
{
	char	*join;
	size_t	tlen;
	int		i;
	int		j;

	if (!buffer)
		return ;
	tlen = ft_strlen(*remain) + ft_strlen(buffer);
	join = malloc((tlen + 1) * sizeof(char));
	if (!join)
		return ;
	i = 0;
	j = 0;
	if (*remain)
	{
		while ((*remain)[i])
			join[i++] = (*remain)[j++];
		free(*remain);
	}
	j = 0;
	while (buffer[j])
		join[i++] = buffer[j++];
	join[i] = '\0';
	*remain = join;
}

void	ft_clean(char **str)
{
	free(*str);
	*str = NULL;
}
