/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:27:42 by bhumeau           #+#    #+#             */
/*   Updated: 2023/11/15 13:44:37 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d", ft_isdigit(argv[1][0]));
	else
		printf("1 seul chiffre !");
	return (0);
}*/
