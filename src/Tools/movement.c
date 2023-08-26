/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:26:59 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 03:01:24 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Why not
bool	isKeyDown(int key)
{
	return (mlx_is_key_down(game()->mlx, key));
}


void movePlayer()
{
    unit()->movementSpeed = 5.0;
    float deltaTime = game()->mlx->delta_time;
    float angleRad = unit()->angle * (M_PI / 180.0);
    float movementSpeed = unit()->movementSpeed * deltaTime;
    float dx = cos(angleRad);
    float dy = sin(angleRad);
        
    // Move Forward
    if (isKeyDown(MLX_KEY_W))
    {
        float newXFloat = unit()->Coord.x + dx * movementSpeed;
        float newYFloat = unit()->Coord.y + dy * movementSpeed;
        if (isvalidtile((s_coord){newXFloat, newYFloat}))
        {
            unit()->Coord.x = newXFloat;
            unit()->Coord.y = newYFloat;
        }
    }
    
    // Move Backward
    else if (isKeyDown(MLX_KEY_S))
    {
        float newXFloat = unit()->Coord.x - dx * movementSpeed;
        float newYFloat = unit()->Coord.y - dy * movementSpeed;
        if (isvalidtile((s_coord){newXFloat, newYFloat}))
        {
            unit()->Coord.x = newXFloat;
            unit()->Coord.y = newYFloat;
        }
    }
    
    // Strafe Left
    if (isKeyDown(MLX_KEY_D))
    {
        // Calculate the strafe direction by rotating 90 degrees to the left.
        float strafeAngleRad = angleRad - (M_PI / 2.0);
        float newXFloat = unit()->Coord.x + cos(strafeAngleRad) * unit()->movementSpeed * deltaTime;
        float newYFloat = unit()->Coord.y + sin(strafeAngleRad) * unit()->movementSpeed * deltaTime;
        if (isvalidtile((s_coord){newXFloat, newYFloat}))
        {
            unit()->Coord.x = newXFloat;
            unit()->Coord.y = newYFloat;
        }
    }

    // Strafe Right
    else if (isKeyDown(MLX_KEY_A))
    {
        // Calculate the strafe direction by rotating 90 degrees to the right.
        float strafeAngleRad = angleRad + (M_PI / 2.0);
        float newXFloat = unit()->Coord.x + cos(strafeAngleRad) * unit()->movementSpeed * deltaTime;
        float newYFloat = unit()->Coord.y + sin(strafeAngleRad) * unit()->movementSpeed * deltaTime;
        if (isvalidtile((s_coord){newXFloat, newYFloat}))
        {
            unit()->Coord.x = newXFloat;
            unit()->Coord.y = newYFloat;
        }
    }
	

    // Left rotation
    if (isKeyDown(MLX_KEY_RIGHT))
    {
        unit()->angle -= unit()->rotationSpeed * deltaTime;
        unit()->angle = fmodf(unit()->angle, 360.0f);
    }

    // Right rotation
    else if (isKeyDown(MLX_KEY_LEFT))
    {
        unit()->angle += unit()->rotationSpeed * deltaTime;
        unit()->angle = fmodf(unit()->angle, 360.0f);  
    }

}
