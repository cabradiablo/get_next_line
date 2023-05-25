/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:21:20 by alepinto          #+#    #+#             */
/*   Updated: 2023/04/30 07:44:05 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_all(int fd, char *temp)
{
	char	*buff;
	int		i;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (!(ft_strchr_gnl(temp, '\n')) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(temp);
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		temp = ft_strjoin_gnl(temp, buff);
	}
	free(buff);
	return (temp);
}

char	*get_line(char *temp)
{
	char	*line;
	int		len;
	int		j;

	len = 0;
	j = 0;
	if (temp[0] == '\0')
		return (NULL);
	while (temp[len] != '\n' && temp[len] != '\0')
		len++;
	if (temp[len] == '\n')
		len++;
	line = (char *)malloc(len + 1);
	if (!line)
		return (0);
	while (j < len)
	{
		line[j] = temp[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*new_temp(char *temp)
{
	char	*newtemp;
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (temp[k] != '\n' && temp[k] != '\0')
		k++;
	if (!temp[k])
	{
		free(temp);
		return (NULL);
	}
	newtemp = (char *)malloc(ft_strlen_gnl(temp) - k + 1);
	if (!newtemp)
		return (0);
	while (temp[k++])
		newtemp[i++] = temp[k];
	newtemp[i] = '\0';
	free(temp);
	return (newtemp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = read_all(fd, temp);
	if (!temp)
		return (NULL);
	line = get_line(temp);
	temp = new_temp(temp);
	return (line);
}
/*void leaks()
{
	system("leaks -q a.out");
}
int main()
{
	atexit(leaks);
	int fd = open("hola.txt", O_RDONLY); 
	while(get_next_line(fd))
	{
		sleep(5); 
	}
}*/