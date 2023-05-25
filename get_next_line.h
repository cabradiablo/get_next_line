/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:22:00 by alepinto          #+#    #+#             */
/*   Updated: 2023/04/30 07:41:21 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlen_gnl(char *s);
int		ft_strchr_gnl(char *s1, char c);
char	*ft_strjoin_gnl(char*s1, char*s2);
char	*get_next_line(int fd);
#endif
