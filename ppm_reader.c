/* ppm_reader.c
 * 
 * see ppm_reader.h for more details
 *
 * Author: Ronik 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ppm_reader.h"

/*
 * read_ppm - stores data from ppm file into malloc'd struct
 * 
 * path - string path to ppm file
 * 
 * Returns: pointer to ppm_t struct
 */
ppm_t *read_ppm(char* path)
{
    if (!path)
    {
        fprintf(stderr, "read_ppm: NULL file path pointer\n");
        exit(0);
    }

    FILE *fp;
    char buff[256];
    int ret;

    fp = fopen(path, "r");
    if (!fp)
    {
        fprintf(stderr, "read_ppm: NULL file pointer\n");
        exit(0);
    }

    fscanf(fp, "%s", buff);
    char type[3];
    strncpy(type, buff, 2);

    ret = fscanf(fp, "%s", buff);
    int width = atoi(buff);

    ret = fscanf(fp, "%s", buff);
    int height = atoi(buff);

    ret = fscanf(fp, "%s", buff);
    int color_scale = atoi(buff);

    if (width <= 0 
    || height <= 0 
    || color_scale != 255 
    || type[0] != 'P' 
    || type[1] != '3') 
    {
        fprintf(stderr, "read_ppm: invalid file format");
        exit(0);
    }

    color_t *colors = (color_t*)malloc(width * height * sizeof(color_t));
    ppm_t *ppm = (ppm_t*)malloc(sizeof(ppm_t));
    if (!colors || !ppm)
    {
        fprintf(stderr, "read_ppm: unable to allocate ppm or colors");
        exit(0);
    }

    int i, index, len = width * height * NUM_COLOR_CHANNELS;
    uint8_t val;
    for (i = 0; i < len; ++i)
    {
        if ((ret = fscanf(fp, "%s", buff)) == -1)
            break;
        
        index = i / NUM_COLOR_CHANNELS;
        val = atoi(buff);
        switch (i % 3)
        {
            case 0: 
                colors[index].r = val;
                break;
            case 1:
                colors[index].g = val;
                break;
            case 2:
                colors[index].b = val;
                break;
        }
    }

    ppm->width = width;
    ppm->height = height;
    ppm->colors = colors;

    return ppm;
}

/*
 * ppm_free - frees ppm pointer and internal pointers
 *
 * Returns: 0 or error code
 */
int ppm_free(ppm_t* ppm)
{
    if (!ppm)
    {
        fprintf(stderr, "ppm_free: NULL ppm pointer\n");
        return -1;
    }

    if (!ppm->colors)
        fprintf(stderr, "ppm_free: NULL ppm->colors pointer\n");
    else
        free(ppm->colors);

    free(ppm);

    return 0;
}