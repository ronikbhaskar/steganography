/* ppm_writer.c
 * 
 * see ppm_writer.h for more details
 *
 * Author: Ronik 
 */

#include <stdio.h>
#include <stdlib.h>
#include "ppm_writer.h"

/*
 * write_ppm - writes ppm data to stdout
 *
 * ppm - pointer to struct representing ppm
 * 
 * Returns: 0 for success, error code otherwise
 */
int write_ppm(ppm_t *ppm)
{
    if (!ppm)
    {
        fprintf(stderr, "write_ppm: given NULL ppm\n");
        return -1;
    }

    int i, len = ppm->width * ppm->height;
    color_t *colors = ppm->colors;

    printf("P3\n");
    printf("%d %d\n", ppm->width, ppm->height);
    printf("255\n");

    for (i = 0; i < len; ++i)
        printf("%u %u %u\n", colors[i].r, colors[i].g, colors[i].b);

    return 0;

}