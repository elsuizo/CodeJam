   /* -------------------------------------------------------------------------
   @file data.h

   @date 04/28/17 12:34:24
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
#ifndef _DATA_H
#define _DATA_H
   /*-------------------------------------------------------------------------
    *                        includes
    -------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

   /*-------------------------------------------------------------------------
    *                        datatypes
    -------------------------------------------------------------------------*/
   struct Data {
      void* buffer;
      size_t size;
   };

   /*-------------------------------------------------------------------------
    *                        prototypes
    -------------------------------------------------------------------------*/
   struct Data
   read_Data(const char* file_path);

void
print_Data(const struct Data* data);
#endif


