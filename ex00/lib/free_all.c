/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsavet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:51:34 by melsavet          #+#    #+#             */
/*   Updated: 2025/10/26 17:31:09 by melsavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_lib.h"

void	free_all(char *file, char **lines, t_dict *dict)
{
	int	i;
	int	size;

	i = -1;
	size = ft_count_lines(file);
	if (file)
		free(file);
	if (lines)
	{
		while (lines[++i])
			free(lines[i]);
		free(lines);
	}
	i = -1;
	if (dict)
	{
		while (++i < size)
		{
			if (dict[i].key)
				free(dict[i].key);
			if (dict[i].value)
				free(dict[i].value);
		}
		free(dict);
	}
}
