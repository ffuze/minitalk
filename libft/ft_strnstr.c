/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:59:04 by adegl-in          #+#    #+#             */
/*   Updated: 2024/11/20 09:59:05 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	l = 0;
	while (little[l] != '\0')
		l++;
	if (l == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] != '\0' && big[i + j] == little[j])
			j++;
		if (j == l)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*int main()
{
	printf("Sottostringa: %s\n", ft_strnstr("gioco a valorant", "valorant", 16));
}*/
