/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsavet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:30:40 by melsavet          #+#    #+#             */
/*   Updated: 2025/10/26 17:14:31 by melsavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib/mini_lib.h"

char	**create_sections(char *str)
{
	int		k;
	int		i;
	int		old_i;
	int		lines;
	char	**arr;

	lines = ft_count_lines(str);
	arr = malloc(sizeof(char *) * (lines + 1));
	if (!arr)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		old_i = i;
		while (str[i] != '\n' && str[i])
			i++;
		arr[k] = (char *)malloc(sizeof(char) * (i - old_i + 1));
		if (!arr[k])
			return (NULL);
		k++;
		if (str[i] == '\n')
			i++;
	}
	return (arr);
}

char	**ft_split_lines(char *str)
{
	int		i;
	char	**arr;
	int		count;
	int		k;
	int		j;

	arr = create_sections(str);
	if (!arr)
		return (NULL);
	count = ft_count_lines(str);
	k = 0;
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i] && str[i] != '\n')
			arr[k][j++] = str[i++];
		arr[k][j] = '\0';
		k++;
	}
	arr[count] = NULL;
	return (arr);
}
