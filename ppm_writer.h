/*
 * ppm_writer.h
 * 
 * This file will allow for the easy writing of ppm files.
 * To prevent circular dependencies, this file will include ppm_reader and use the associated struct.
 * 
 * The writer will write the ppm to stdout.
 *
 * Author: Ronik
 */

#ifndef _PPM_WRITER_H
#define _PPM_WRITER_H

#include "ppm_reader.h"

/*
 * write_ppm - writes ppm data to stdout
 *
 * ppm - pointer to struct representing ppm
 * 
 * Returns: 0 for success, error code otherwise
 */
int write_ppm(ppm_t *ppm);

#endif /* _PPM_WRITER_H */
