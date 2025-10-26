/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsavet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 04:55:43 by melsavet          #+#    #+#             */
/*   Updated: 2025/10/26 17:24:59 by melsavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib/mini_lib.h"

void	print_number_recursive(unsigned long n, t_dict *dict, int size);

void	less_100(long n, t_dict *dict, int size)
{
	int		tens;
	int		ones;
	char	*tens_str;
	char	*ones_str;

	tens = (n / 10) * 10;
	ones = n % 10;
	tens_str = ft_itoa(tens);
	ones_str = ft_itoa(ones);
	ft_putstr(find_value(dict, size, tens_str));
	if (ones)
	{
		ft_putchar(' ');
		ft_putstr(find_value(dict, size, ones_str));
	}
	free(tens_str);
	free(ones_str);
}

void	less_1000(long n, t_dict *dict, int size)
{
	char	*n_str;
	int		hundreds;

	hundreds = n / 100;
	n_str = ft_itoa(hundreds);
	ft_putstr(find_value(dict, size, n_str));
	ft_putchar(' ');
	ft_putstr(find_value(dict, size, "100"));
	if (n % 100)
	{
		ft_putchar(' ');
		print_number_recursive(n % 100, dict, size);
	}
	free(n_str);
}

void	ft_init(unsigned long divisors[], char *names[])
{
	divisors[0] = 1000000000000000000LL;
	names[0] = "1000000000000000000";
	divisors[1] = 1000000000000000LL;
	names[1] = "1000000000000000";
	divisors[2] = 1000000000000LL;
	names[2] = "1000000000000";
	divisors[3] = 1000000000LL;
	names[3] = "1000000000";
	divisors[4] = 1000000LL;
	names[4] = "1000000";
	divisors[5] = 1000LL;
	names[5] = "1000";
}

void	bigger(unsigned long n, t_dict *dict, int size)
{
	unsigned long	divisors[6];
	char			*names[6];
	int				i;

	ft_init(divisors, names);
	i = -1;
	while (++i < 6)
	{
		if (n >= divisors[i])
		{
			print_number_recursive((n / divisors[i]), dict, size);
			ft_putchar(' ');
			ft_putstr(find_value((dict), size, names[i]));
			if ((n % divisors[i]))
			{
				ft_putchar(' ');
				print_number_recursive((n % divisors[i]), dict, size);
			}
			return ;
		}
	}
	less_1000(n, dict, size);
}

void	print_number_recursive(unsigned long n, t_dict *dict, int size)
{
	char	*n_str;

	if (n < 20)
	{
		n_str = ft_itoa(n);
		ft_putstr(find_value(dict, size, n_str));
		free(n_str);
	}
	else if (n < 100)
		less_100(n, dict, size);
	else if (n < 1000)
		less_1000(n, dict, size);
	else
		bigger(n, dict, size);
}
