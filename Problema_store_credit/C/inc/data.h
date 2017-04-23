/* -------------------------------------------------------------------------
@file data.h

@date 04/23/17 15:44:04
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief

@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
#ifndef DATA_H
#define DATA_H
/*-------------------------------------------------------------------------
 *                        includes
 -------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

/*-------------------------------------------------------------------------
 *                        datatypes
 -------------------------------------------------------------------------*/
struct Data {
   size_t size;
   void* buffer;
};

/*-------------------------------------------------------------------------
 *                        prototypes
 -------------------------------------------------------------------------*/
struct Data*
make_Data(void* buffer, size_t size);

void
free_Data(struct Data* data);

void
print_Data_char(struct Data* data);

struct Data*
read_Data(char* filename);

#endif
