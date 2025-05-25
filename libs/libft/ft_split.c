/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:01:35 by olcherno          #+#    #+#             */
/*   Updated: 2025/02/07 18:13:18 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_substrings(const char *s, char c)
{
	size_t	count;
	int		in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (*s == c)
			in_substring = 0;
		else if (in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static void	ft_free_substrings(char **result)
{
	size_t	i;

	if (!result)
		return ;
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	ft_allocate_substrings(const char *s, char c, size_t elements,
		char **result)
{
	size_t	count;
	size_t	index;

	index = 0;
	while (elements--)
	{
		while (*s == c)
			s++;
		count = 0;
		while (*s != c && *s != '\0')
		{
			count++;
			s++;
		}
		if (count > 0)
		{
			result[index] = malloc(sizeof(char) * (count + 1));
			if (!result[index++])
			{
				ft_free_substrings(result);
				return (0);
			}
		}
	}
	return (1);
}

static void	ft_add_substrings(const char *s, char c, char **result)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		j = 0;
		while (*s != c && *s != '\0')
		{
			result[i][j++] = *s++;
		}
		if (j > 0)
			result[i++][j] = '\0';
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	count_c;
	char	**result;

	if (!s)
		return (NULL);
	count_c = ft_count_substrings(s, c);
	result = malloc(sizeof(char *) * (count_c + 1));
	if (!result)
		return (NULL);
	result[count_c] = NULL;
	if (!ft_allocate_substrings(s, c, count_c, result))
	{
		return (NULL);
	}
	ft_add_substrings(s, c, result);
	return (result);
}
