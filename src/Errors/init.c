/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:29:35 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 02:54:22 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Check if user gave us a map file
bool	argc_isbad(int argv)
{
	if (argv != 2) {
		printf("[-] Error\n[-] No Map = No Game\n");
		return (true);
	}
	return (false);
}
