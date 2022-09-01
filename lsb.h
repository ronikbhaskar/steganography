/*
 * lsb.h
 * 
 * Least Significant Bit Steganography involves changing the least significant bit of a color channel in an image.
 * This is usually done with byte maps, but for my purposes, I'll be using ppm files.
 * 
 * This method will encode the single least significant bit to encode an ASCII message.
 * 
 * The message will either terminate with the end of the file or a null terminator.
 *
 * Author: Ronik
 */

#ifndef _LSB_H
#define _LSB_H

#include "ppm_writer.h"

/*
 * hide_message - hides message in least significant bits of ppm
 *
 * ppm - pointer to struct representing ppm
 * 
 * msg - message to be hidden in ppm
 * 
 * Returns: 0 for success, error code otherwise
 */
int hide_message(ppm_t *ppm, char* msg);

/*
 * read_message - reads message in least significant bits of ppm, prints to stdout
 *
 * ppm - pointer to struct representing ppm
 * 
 * Returns: 0 for success, error code otherwise
 */
int read_message(ppm_t *ppm);

#endif /* _LSB_H */