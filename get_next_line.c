/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:46:03 by haze              #+#    #+#             */
/*   Updated: 2022/12/02 11:58:05 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*get_next_line(int fd)
{
	static char	*old_string;
	

}
int main(void)
{
	int	fd;
	char *string;

	fd = open("hello.txt", O_RDONLY);
	while (1)
	{
		string = get_next_line(fd);
		if (string == NULL)
			break;
		printf("%s",(string));
		free(string);	
	}
	return (0);
}