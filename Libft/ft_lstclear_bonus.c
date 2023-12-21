/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:30:29 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/18 18:02:35 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temporary;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		temporary = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temporary;
	}
}
