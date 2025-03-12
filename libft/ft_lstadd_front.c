/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:36:51 by adegl-in          #+#    #+#             */
/*   Updated: 2024/11/25 14:08:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*int main(void)
{
    t_list *head = NULL;

    t_list *node1 = ft_lstnew("Nodo 1");
    head = node1;

    printf("Prima aggiunta:\n");
    printf("Content head: %s\n", (char *)head->content);

    t_list *node2 = ft_lstnew("Nodo 2");

    ft_lstadd_front(&head, node2);

    printf("Dopo aggiunta:\n");
    printf("Content head: %s\n", (char *)head->content);
    printf("Next content: %s\n", (char *)head->next->content);

    return 0;
}*/
