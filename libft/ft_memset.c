/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:47:35 by adegl-in          #+#    #+#             */
/*   Updated: 2024/11/26 12:46:46 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)(s);
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (ptr);
}

/*int main()
{
	char s[50] = "GeeksForGeeks is for programming geeks.";
	printf("Before memset(): %s\n", s);

	// Fill 8 characters starting from s[13] with '.'
	ft_memset(s + 13, '.', 8*sizeof(char));

	printf("After memset():  %s", s);
	return 0;
}*/
