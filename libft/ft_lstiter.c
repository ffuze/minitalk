/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:08:12 by adegl-in          #+#    #+#             */
/*   Updated: 2024/12/04 16:55:38 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* void	f(void *content)
{
	printf("%s\n", (char *)content);
} */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* int main()
{
	t_list *head = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("Nodo 1"));
	t_list *node2 = ft_lstnew(ft_strdup("Nodo 2"));
	t_list *node3 = ft_lstnew(ft_strdup("Nodo 3"));
    
	head = node1;

	node1->next = node2;
	node2->next = node3;

	printf("Contenuto della lista:\n");
	ft_lstiter(head, f);
} */