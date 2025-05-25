/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:24:11 by olcherno          #+#    #+#             */
/*   Updated: 2024/10/06 18:24:16 by olcherno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	new = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!new)
		return (NULL);
	while (i < lens1)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < lens1 + lens2)
	{
		new[i] = s2[i - lens1];
		i++;
	}
	new[i] = '\0';
	return (new);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// int main() {
//     char *s1 = "Hello, ";
//     char *s2 = "";
//     char *result;

//     // Call the ft_strjoin function
//     result = ft_strjoin(s1, s2);

//     if (result) {
//         // Print the result to see if it worked
//         printf("Joined string: %s\n", result);

//         // Free the allocated memory after use
//         free(result);
//     } else {
//         printf("Memory allocation failed!\n");
//     }

//     return (0);
// }