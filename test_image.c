/*
 * short file to generate ppm images for testing
 */

#include <stdio.h>
#include "ppm_writer.h"

int main(int argc, char **argv)
{
    ppm_t ppm;

    ppm.width = 255;
    ppm.height = 255;

    ppm.colors = (color_t*)malloc(sizeof(color_t) * 255 * 255);
    int x, y, index = 0;

    for (y = 0; y < 255; ++y) 
    {
        for (x = 0; x < 255; ++x) 
        {
            ppm.colors[index].r = x;
            ppm.colors[index].g = 255 - y;
            ppm.colors[index].b = 255;
            index += 1;
        }
    }
    
    write_ppm(&ppm);
    free(ppm.colors);
    return 0;
}