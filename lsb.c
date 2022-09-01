/* lsb.c
 * 
 * see lsb.h for more details
 *
 * Author: Ronik 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lsb.h"

/*
 * hide_message - hides message in least significant bits of ppm
 *
 * ppm - pointer to struct representing ppm
 * 
 * msg - message to be hidden in ppm
 * 
 * Returns: 0 for success, error code otherwise
 */
int hide_message(ppm_t *ppm, char* msg)
{
    /* I am a trained professional. This is very dangerous. Kids, don't try this at home */
    size_t msg_len = strlen(msg);

    int i, j, width = ppm->width, height = ppm->height;
    int img_len = width * height;
    int bit_arr_len = msg_len * 8 + 8;

    if (bit_arr_len > img_len * 3)
    {
        fprintf(stderr, "hide_message: msg is too long\n");
        return -1;
    }

    uint8_t bit_arr[bit_arr_len];

    for (i = 0; i < msg_len; ++i)
    {
        /* read bits from largest place value to smallest (left to right) */
        for (j = 0; j < 8; ++j)
            bit_arr[i * 8 + j] = msg[i] >> (7 - j) & 0x1;
    }

    for (j = 0; j < 8; ++j)
        bit_arr[msg_len * 8 + j] = 0;

    uint8_t zero_mask = ~0x1;

    j = -1;
    for (i = 0; i < img_len; ++i)
    {
        if (++j >= bit_arr_len)
            break;
        
        ppm->colors[i].r = bit_arr[j] ? ppm->colors[i].r | 0x1 : ppm->colors[i].r & zero_mask;

        if (++j >= bit_arr_len)
            break;
        
        ppm->colors[i].g = bit_arr[j] ? ppm->colors[i].g | 0x1 : ppm->colors[i].g & zero_mask;

        if (++j >= bit_arr_len)
            break;
        
        ppm->colors[i].b = bit_arr[j] ? ppm->colors[i].b | 0x1 : ppm->colors[i].b & zero_mask;
    }

    return 0;
}

/*
 * read_message - reads message in least significant bits of ppm, prints to stdout
 *
 * ppm - pointer to struct representing ppm
 * 
 * Returns: 0 for success, error code otherwise
 */
int read_message(ppm_t *ppm)
{
    int j, i = 0, width = ppm->width, height = ppm->height;
    char current_char = 0;
    uint16_t col;
    color_t *colors = ppm->colors;

    for (j = 0; j < width * height * NUM_COLOR_CHANNELS; ++j)
    {
        switch (j % 3)
        {
            /* integer divison */
            case 0:
                col = colors[j / 3].r; 
                break;
            case 1:
                col = colors[j / 3].g; 
                break;
            case 2:
                col = colors[j / 3].b; 
                break;
        }

        switch (col & 0x1)
        {
            case 1:
                current_char = current_char | (1 << (7 - i++));
                break;
            case 0:
                current_char = current_char | (0 << (7 - i++));
                break;
        }

        if (i == 8)
        {
            if (current_char == 0)
                break;
            
            printf("%c", current_char);
            i = 0;
            current_char = 0;
        }
    }
    return 0;
}
