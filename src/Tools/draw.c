/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:33:42 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 23:00:13 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
// Function to draw a line on the minimap connecting two points (x1, y1) and (x2, y2)
void drawLineOnMinimap(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = fmaxf(fabsf(dx), fabsf(dy));
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;
    float x = x1;
    float y = y1;

    for (int i = 0; i < steps; i++) {
        if (x >= 0 && x < SCREEN_WIDTH / 4 && y >= 0 && y < SCREEN_HEIGHT / 4) {
            mlx_put_pixel(getgamedata()->img, x, y, getcolor()->minimapplayerangleline); // Red color for the line
        }
        x += xIncrement;
        y += yIncrement;
    }
}

void drawSquare(uint16_t x, uint16_t y, uint16_t tilesize_x, uint16_t tilesize_y)
{
    uint16_t x_end = x + tilesize_x;
    uint16_t y_end = y + tilesize_y;

    // Ensure that the square is within the screen boundaries
    if (x_end > SCREEN_WIDTH || y_end > SCREEN_HEIGHT)
        return;

    // Draw the square with the given color
    for (uint16_t i = x; i < x_end; i++) {
        for (uint16_t j = y; j < y_end; j++) {
            mlx_put_pixel(getgamedata()->img, i, j, getcolor()->minimapwall);
        }
    }
}

void drawMiniMap()
{
    int map_x = getgamedata()->map_x;
    int map_y = getgamedata()->map_y;

    // Calculate the tile size for both x and y directions
    int tilesize_x = SCREEN_WIDTH / (4 * map_x);
    int tilesize_y = SCREEN_HEIGHT / (4 * map_y);

    for (int i = 0; i < (map_x * tilesize_x); i++) {
        for (int j = 0; j < (map_y * tilesize_y); j++) {
            mlx_put_pixel(getgamedata()->img, i, j, getcolor()->minimapbackground);
        }
    }

    // Draw Grid
    for (int i = 0; i < map_x; i++) {
        for (int j = 0; j < map_y; j++) {

            if (getgamedata()->map[i][j] != 1)
                continue;

            int xo = i * tilesize_x;
            int yo = j * tilesize_y;
            drawSquare(xo, yo, tilesize_x, tilesize_y);

        }
    }
}

void drawPlayer()
{
    int dx;
    int dy;
    int map_x = getgamedata()->map_x;
    int map_y = getgamedata()->map_y;

    // Calculate the scaling factors for both x and y directions using tilesize
    float scaleX = (float)(SCREEN_WIDTH) / (4 * map_x);
    float scaleY = (float)(SCREEN_HEIGHT) / (4 * map_y);

    // Get the player's coordinates
    float playerX = getplayerunit()->Coord.x;
    float playerY = getplayerunit()->Coord.y;

    // Calculate the player's position on the minimap using the tilesize-based scaling
    float xo = playerX * scaleX;
    float yo = playerY * scaleY;

    // Calculate the player's icon size on the minimap based on the tilesize
    int playerSize = 5;

    // Draw the player's position on the minimap
    for (int i = -playerSize; i <= playerSize; i++) {
        for (int j = -playerSize; j <= playerSize; j++) {
            dx = i;
            dy = j;
            if (sqrt(dx * dx + dy * dy) <= playerSize) {
                float x = xo + i;
                float y = yo + j;
                if (x >= 0 && x < SCREEN_WIDTH / 4 && y >= 0 && y < SCREEN_HEIGHT / 4) {
                    mlx_put_pixel(getgamedata()->img, x, y, getcolor()->minimapplayer);
                }
            }
        }
    }

    // Draw the direction line (assuming you have a drawLineOnMinimap function)
    float angleDeg = getplayerunit()->angle;
    float lineLength = 10.0f; // Length of the direction line in pixels (you can adjust this as needed)

    // Convert the angle to radians
    float angleRad = angleDeg * M_PI / 180.0f;

    // Calculate the endpoint of the line based on the player's angle relative to the player's position
    float endX = xo + lineLength * cos(angleRad);
    float endY = yo + lineLength * sin(angleRad);

    // Draw the line on the minimap
    drawLineOnMinimap(xo, yo, endX, endY);
}

void raycasting()
{
    int feature_aiming_mode = 0;
	
	int precision = 300;
    float angleRad = degreesToRadians(getplayerunit()->angle);
    float halfFovAngleRad = degreesToRadians(getplayerunit()->fov / 2.0f);
    float cameraPlaneDist = (SCREEN_WIDTH + feature_aiming_mode / 2.0f) / tan(halfFovAngleRad);
	// Display -
    for (int width = 0; width < SCREEN_WIDTH; width++)
    {
        float rayAngle = atan2(SCREEN_WIDTH / 2.0f - width + 0.5, cameraPlaneDist) + angleRad;
        float rayX = getplayerunit()->Coord.x;
        float rayY = getplayerunit()->Coord.y;
        float rayCos = cos(rayAngle) / precision;
        float raySin = sin(rayAngle) / precision;

        bool wall = false;
        while (!wall)
        {
            rayX += rayCos;
            rayY += raySin;
            wall = getgamedata()->map[(int)(rayX)][(int)(rayY)] == 1;
        }

        int wallHeight = (cameraPlaneDist / (get_distance(getplayerunit()->Coord, (s_coord){rayX, rayY}) * cos(rayAngle - angleRad)));
		
		bool wallIsVertical = false;
		
		// Display |
		for (int height = 0; height < SCREEN_HEIGHT; height++)
		{
			// Roof
			if (height < (SCREEN_HEIGHT - wallHeight) / 2)
				mlx_put_pixel(getgamedata()->img, width, height, getcolor()->gameroof);

			// Wall
			else if (height >= (SCREEN_HEIGHT - wallHeight) / 2 && height < (SCREEN_HEIGHT + wallHeight) / 2)
			{
				float textureX;

				if (wallIsVertical)
					textureX = (rayX - floor(rayX)) * gettexture()->test->width;
				else {
					textureX = (rayY - floor(rayY)) * gettexture()->test->width;
					rayX += rayCos;
				}
				float textureY = (height - (SCREEN_HEIGHT - wallHeight) / 2) / (float)wallHeight * gettexture()->test->height;
				mlx_put_pixel(getgamedata()->img, width, height, texture_to_pixel(gettexture()->test, textureX, textureY));
			}

			// Floor
			else
			{
				mlx_put_pixel(getgamedata()->img, width, height, getcolor()->gamefloor);
			}
		}

    }
}
