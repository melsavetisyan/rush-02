/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melsavet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 04:01:11 by melsavet          #+#    #+#             */
/*   Updated: 2025/10/26 17:51:57 by melsavet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_LIB_H
# define MINI_LIB_H

# include <stdlib.h>

typedef struct s_dict
{
	char		*key;
	char		*value;
}				t_dict;

char			*ft_strcat(char *s1, char *s2);
void			ft_putchar(char c);
void			ft_putstr(char *str);
char			*ft_substr(char *str, int start, int len);
int				ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
int				ft_is_numeric(char *str);
int				ft_find_char(char *str, char c);
int				ft_count_lines(char *str);
int				ft_numlen(int n);
char			*ft_itoa(int n);
char			*find_value(t_dict *dict, int size, char *key);
unsigned long	ft_atoi(const char *str);
void			free_all(char *file, char **lines, t_dict *dict);
t_dict			*create_arr(char **arr, int size);

#endif
