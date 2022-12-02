/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:10:45 by mthea             #+#    #+#             */
/*   Updated: 2022/12/02 19:41:55 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// 1|Functiion for read the fd and take the string into the buffer 
// 2|Function for make from sort until 'n' and take this in (char *string)
// 3|Fucntion for reset the string
char	*reading_file(int fd, char *old_string)
{
	char	*buffer;
	int		number;

	number = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (number > 0 && !ft_comp(old_string, '\n'))
	{
		number = read(fd, buffer, BUFFER_SIZE);
		if (number == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = 0;
		if (number > 0)
			old_string = ft_strjoin(old_string, buffer);
	}
	free(buffer);
	return (old_string);
}

char	*ft_strcopy_new(char *s)
{
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	new_string = (char *) malloc(sizeof(char) + (i + 2));
	if (!new_string)
		return(NULL);
	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
	{
		new_string[j] = s[i];
		i++;
		j++;
	}
	if (s[i] == '\n')
	{
		new_string[j] = s[i];
		j++;
	}
	new_string[j] = '\0';
	return (new_string);
}

char	*ft_clear_old(char *s)
{
	char	*new_string;
	int		start;
	int		end;

	start = 0;
	if (!s[0])
		return (NULL);
	while (s[start] != '\n' && s[start])
		start++;
	start++;
	end = start;
	while (s[end])
		end++;
	new_string = malloc(sizeof(char) * ((end - start) + 1));
	end = start;
	start = 0;
	while (s[end])
	{
		new_string[start] = s[end];
		start++;
		end++;
	}
	new_string[start] = '\0';
	free(s);
	return (new_string);
}

char	*get_next_line(int fd)
{
	static char	*old_string = NULL;
	char		*new_string;

	if (fd < 0)
		return (NULL);
	old_string = reading_file(fd, old_string);
	if (!old_string)
		return (NULL);
	new_string = ft_strcopy_new(old_string);
	old_string = ft_clear_old(old_string);
	if (!old_string)
		return (NULL);
	return (new_string);
}

int main(void)
{
	int fd = open("test.txt",O_RDONLY);
	char *string;
	if (fd == -1)
		return (0);
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