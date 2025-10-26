/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsavet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 00:41:52 by melsavet          #+#    #+#             */
/*   Updated: 2025/10/26 17:15:47 by melsavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib/mini_lib.h"

char	**ft_split_lines(char *str);
int		ft_is_numeric(char *str);
char	*read_file_simple(char *filename);
void	print_number_recursive(unsigned long n, t_dict *dict, int size);

void	fill_all(char *file, char ***lines, t_dict **dict, unsigned long num)
{
	int	size;

	size = ft_count_lines(file);
	*lines = ft_split_lines(file);
	*dict = create_arr(*lines, size);
	print_number_recursive(num, *dict, size);
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	t_dict			*dict;
	char			*file;
	char			**lines;

	lines = NULL;
	file = NULL;
	dict = NULL;
	if ((argc != 2 && argc != 3) || !ft_is_numeric(argv[1]))
		return (1);
	if (argc == 3)
	{
		file = read_file_simple(ft_strcat("dicts/", argv[2]));
		if (!file)
			return (1);
	}
	else
		file = read_file_simple("dicts/en");
	if (argv[1][0] == '-' && argv[1][1])
	{
		ft_putstr("minus ");
		argv[1][0] = '0';
	}
	fill_all(file, &lines, &dict, ft_atoi(argv[1]));
	free_all(file, lines, dict);
	return (0);
}
