/* -------------------------------------------------------------------------
@file data.c

@date 04/28/17 12:49:20
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
#include "../inc/data.h"

/*-------------------------------------------------------------------------
 *                        functions implementations
 -------------------------------------------------------------------------*/

struct Data
read_Data(const char* filename) {
   struct Data result = {};
   char* buffer = NULL;
   size_t buffer_size = 0;
   size_t read_size = 0;
   FILE* f = fopen(filename, "r");
   if (f == NULL) {
      fprintf(stderr, "error the file dont exist\n");
      exit(1);
   }
   if (f) {
      /* Seek the last byte of the file */
      fseek(f, 0, SEEK_END);
      /* Offset from the first to the last byte, or in other words, filesize */
      buffer_size = ftell(f);
      /* go back to the start of the file */
      rewind(f);
      /* Allocate a string that can hold it all */
      buffer = (char*)malloc(sizeof(char) * (buffer_size + 1) );
      /* Read it all in one operation */
      read_size = fread(buffer, sizeof(char), buffer_size, f);
      /* fread doesn't set it so put a \0 in the last position */
      /* and buffer is now officially a string */
      buffer[buffer_size] = '\0';
      if (buffer_size != read_size) {
         /* Something went wrong, throw away the memory and set */
         /* the buffer to NULL */
         fprintf(stderr, "error\n");
         free(buffer);
         buffer = NULL;
      }
      result.buffer = buffer;
      result.size = buffer_size;
      /* Always remember to close the file */
      fclose(f);
   }
   return(result);

}

void
print_Data(const struct Data* data) {
   size_t i;
   for (i = 0; i < data->size; ++i) {
      printf("%c", ((char*)data->buffer)[i]);
   }
}
