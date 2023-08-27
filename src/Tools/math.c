/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:03:33 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 22:53:18 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Euclidean distance
float	get_distance(t_coord a, t_coord b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

// Convert Degree to Radians
double	degreetoradians(double degrees)
{
	return (degrees * M_PI / 180.0);
}
