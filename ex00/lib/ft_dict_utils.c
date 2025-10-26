/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsavet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 01:06:52 by melsavet          #+#    #+#             */
/*   Updated: 2025/10/26 17:36:28 by melsavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mini_lib.h"

t_dict	*create_arr(char **arr, int size)
{
	t_dict	*keys_values;
	int		i;
	int		sep;
	int		val_len;

	i = 0;
	keys_values = malloc(sizeof(t_dict) * size);
	while (i < size)
	{
		sep = ft_find_char(arr[i], ':');
		keys_values[i].key = ft_substr(arr[i], 0, sep);
		val_len = ft_strlen(arr[i] + sep + 1);
		keys_values[i].value = malloc(val_len + 1);
		ft_strcpy(keys_values[i].value, arr[i] + sep + 1);
		i++;
	}
	return (keys_values);
}
