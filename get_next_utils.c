/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:53:39 by haze              #+#    #+#             */
/*   Updated: 2022/12/01 13:15:21 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}


int	ft_strchr(char *oldstring, char searchedChar)
{
	int	i;

	i = 0;
	while (oldstring[i] != '\0')
	{
		if (oldstring[i] == (char) searchedChar)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *source, int nombre)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	while (i < nombre)
		i++;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (i < nombre)
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
