//
// Created by lush on 3/9/17.
//

#include "fractol.h"

void julia()
{
    double cRe, cIm;
    double newRe, newIm, oldRe, oldIm;
    double zoom = 1, moveX = 0, moveY = 0;
    int maxIterations = 300;

    cRe = -0.70176;
    cIm = -0.3842;

    for (int x = 0; x < WIN_SIZE_X; x++)
        for (int y = 0; y < WIN_SIZE_Y; y++)
        {
            newRe = 1.5 * (x - WIN_SIZE_X / 2) / (0.5 * zoom * WIN_SIZE_X) + moveX;
            newIm = (y - WIN_SIZE_Y / 2) / (0.5 * zoom * WIN_SIZE_Y) + moveY;

            int i;
            for (i = 0; i < maxIterations; i++)
            {
                oldRe = newRe;
                oldIm = newIm;

                newRe = oldRe * oldRe - oldIm * oldIm + cRe;
                newIm = 2 * oldRe * oldIm + cIm;

                if ((newRe * newRe + newIm * newIm) > 4) break;
            }

            int color;

            color = (unsigned char)((i * 9) % 255);
            color <<= 16;
            color |= (unsigned char)((i * 9) % 255);


            draw_pixel();
        }
}