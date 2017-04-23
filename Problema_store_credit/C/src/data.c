/* -------------------------------------------------------------------------
@file data.c

@date 04/23/17 15:59:13
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

struct Data*
make_Data(void* buffer, size_t size) {
   /* TODO(elsuizo:2017-04-22):hacer los chequeos de memoria!!! */
   struct Data* data = (struct Data*)malloc(sizeof(struct Data));
   data->size = size;
   data->buffer = (void*)buffer;

   return data;
}

void
free_Data(struct Data* data) {
   free(data->buffer);
}

void
print_Data_char(struct Data* data) {
   uint8_t i;
   for (i = 0; i < data->size; i++) {
      printf("buffer[%d]: %c", i, ((char*)data->buffer)[i]);
   }
}


struct Data*
read_Data(char* filename) {
   struct Data* data = NULL;
   char* buffer = NULL;
   size_t file_size, read_size;
   FILE* f = fopen(filename, "r");
   if (f == NULL) {
      fprintf(stderr, "error the file dont exist\n");
      exit(1);
   }
   if (f) {
      /* Seek the last byte of the file */
      fseek(f, 0, SEEK_END);
      /* Offset from the first to the last byte, or in other words, filesize */
      file_size = ftell(f);
      /* go back to the start of the file */
      rewind(f);
      /* Allocate a string that can hold it all */
      buffer = (char*)malloc(sizeof(char) * (file_size + 1) );
      /* Read it all in one operation */
      read_size = fread(buffer, sizeof(char), file_size, f);
      /* fread doesn't set it so put a \0 in the last position */
      /* and buffer is now officially a string */
      buffer[file_size] = '\0';
      if (file_size != read_size) {
         /* Something went wrong, throw away the memory and set */
         /* the buffer to NULL */
         fprintf(stderr, "error\n");
         free(buffer);
         buffer = NULL;
      }
      /* Always remember to close the file */
      fclose(f);
   }
   data = make_Data(buffer, file_size);
   return data;
}

