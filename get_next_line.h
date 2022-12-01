/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 08:45:58 by haze              #+#    #+#             */
/*   Updated: 2022/12/01 13:11:53 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#	define BUFFER_SIZE (42)
# endif 
char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *old_string);
char	*ft_strdup_newstring(char *old_string);
char	*ft_get_end(char *old_string);
int		ft_strlen(char *str);
int		ft_strchr(char *string, char searchedChar);
char	*ft_strdup(const char *source, int nombre);
#endif