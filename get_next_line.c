/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:46:03 by haze              #+#    #+#             */
/*   Updated: 2022/12/01 13:16:47 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *old_string)
{
	int		nombre;
	char	*buffer;

	nombre = 1;
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (nombre > 0 && (ft_strchr(buffer, '\n') == 1))
	{
		nombre = (int) read(fd, buffer, BUFFER_SIZE);
		if (nombre == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nombre] = '\0';
		old_string = ft_strdup(buffer, nombre);
	}
	free(buffer);
	return (old_string);
}

char	*ft_strdup_newstring(char *old_string)
{
	char	*new_string;
	int		i;

	new_string = NULL;
	i = 0;
	while (old_string[i] && old_string[i] != '\n')
		i++;
	new_string = (char *) malloc(sizeof(char) * (i + 2));
	if (new_string == NULL)
		return (0);
	i = 0;
	while (old_string[i] && old_string[i] == '\n')
	{
		new_string[i] = old_string[i];
		i++;
	}
	if (old_string[i] == '\n')
	{
		new_string[i] = old_string[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_get_end(char *old_string)
{
	int		i;
	int		j;
	char	*get_end;

	i = 0;
	j = 0;
	while (old_string[i] && old_string[i] != '\n')
		i++;
	if (old_string && old_string[i] == '\n')
		i++;
	get_end = (char *) malloc(sizeof(char) * (ft_strlen(old_string - i) + 1));
	if (!get_end)
		return	(NULL);
	while (old_string[i])
		get_end[j++] = old_string[i++];
	get_end[j] = '\0';
	free(old_string);
	return (get_end);	
	
}

char	*get_next_line(int fd)
{
	char		*new_string;
	static char	*old_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	old_string = ft_read_line(fd, old_string);
	if (!old_string)
		return (NULL);
	new_string = ft_strdup_newstring(old_string);
	old_string = ft_get_end(old_string);
	return (new_string);
}

int main(void)
{
	int fd;
	char *string;

	fd = open("hello.txt", O_RDONLY);
	while (1)
	{
		string = get_next_line(fd);
		printf("%s", string);
		if (string == NULL)
			break;
		free(string);
	}
	return (0);
}