/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:53:12 by bhumeau           #+#    #+#             */
/*   Updated: 2024/11/29 14:39:13 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
	float AB = a.cross_calc(b, p);
	float BC = b.cross_calc(c, p);
	float CA = c.cross_calc(a, p);
	return ((AB > 0 && BC > 0 && CA > 0 ) || (AB < 0 && BC < 0 && CA < 0));
}
