/*
 * ppm_reader.h
 * 
 * This file will allow for easy reading of ppm files.
 * To prevent circular dependencies, this file will not include any files.
 * 
 * The associated struct will encode the width, height, and an array of RGB values.
 *
 * Author: Ronik
 */

#ifndef _PPM_READER_H
#define _PPM_READER_H

#define NUM_COLOR_CHANNELS 3

/* uint8_t - shorter syntax for unsigned char */
typedef unsigned char uint8_t;

/* color_t - represents the color channels for a single pixel, 255 scale */
typedef struct color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} color_t;

/* ppm_t - struct for encoding a ppm image */ 
typedef struct ppm 
{
    int width; // width as dictated by ppm file
    int height; // height as dictated by ppm file
    color_t *colors; // array of color values for each pixel
} ppm_t;

/*
 * read_ppm - stores data from ppm file into malloc'd struct
 * 
 * path - string path to ppm file
 * 
 * Returns: pointer to ppm_t struct
 */
ppm_t *read_ppm(char* path);


/*
 * ppm_free - frees ppm pointer and internal pointers
 *
 * Returns: 0 or error code
 */
int ppm_free(ppm_t* ppm);

#endif /*_PPM_READER_H */
