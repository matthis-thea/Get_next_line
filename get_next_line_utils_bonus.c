/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:29:28 by mthea             #+#    #+#             */
/*   Updated: 2022/12/03 16:29:44 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	ft_comp(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	if (!s1)
	{
		s1 = calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	if (!s1 && !s2)
		return (NULL);
	s = calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	free(s1);
	s[j] = '\0';
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	char			*chaine;

	chaine = s;
	i = 0;
	while (i < n)
	{
		chaine[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointeur;

	pointeur = (void *) malloc(count * size);
	if (!pointeur)
		return (NULL);
	ft_bzero(pointeur, (count * size));
	return (pointeur);
}