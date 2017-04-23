/* -------------------------------------------------------------------------
@file main.c

@date 04/20/17 20:23:51
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
/*-------------------------------------------------------------------------
 *                        TODO list
 *  - [X] Leer un archivo eficientemente
 *    - [ ] Leer el archivo con mmap(dicen que es mas eficiente)
 *  - [ ] Parsear los casos y crear los vectores de Credits
 -------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

const int STEPSIZE = 100;
/* number of elements in array */
#define ARRAY_SIZE(x)  (sizeof(x) / sizeof((x)[0]))
/*-------------------------------------------------------------------------
 *                        Data stuff
 -------------------------------------------------------------------------*/
struct Data {
   size_t size;
   void* buffer;
};

static struct Data* make_Data(void* buffer, size_t size) {
   /* TODO(elsuizo:2017-04-22):hacer los chequeos de memoria!!! */
   struct Data* data = (struct Data*)malloc(sizeof(struct Data));
   data->size = size;
   data->buffer = (void*)buffer;

   return data;
}

static void free_Data(struct Data* data) {
   free(data->buffer);
}

static void print_Data_char(struct Data* data) {
   uint8_t i;
   for (i = 0; i < data->size; i++) {
      printf("buffer[%d]: %c", i, ((char*)data->buffer)[i]);
   }
}

char** load_file(char* filename){
   FILE* f = fopen(filename, "r");
   // check the read file status
   if(!f){
      fprintf(stderr, "Cant open %s for reading\n", filename);
      return NULL;
   }
   int arrlen = 0;
   // prealocate a chunk of memmory for the file the first 100
   //  NOTE(elsuizo:realloc con el primer parametro=NULL es lo mismo que malloc)-->Sun 01 May 2016 04:44:29 PM ART
   char** lines = NULL;

   /* NOTE(elsuizo: 2017-04-12) esto no me cierra porque hace que el buffer tenga un largo estatico */
   char buffer[1000];
   int i = 0;
   while(fgets(buffer, 1000, f)){
      if(i == arrlen){
         arrlen += STEPSIZE;
         // the buffer is full and then reallocate the new space
         char** new_lines = realloc(lines, arrlen * sizeof(char *));
         if(!new_lines){
            fprintf(stderr, "Can't realloc men!!!\n");
            exit(1);
         }
         lines = new_lines;
      }
      /* NOTE(elsuizo: 2017-04-11) ver si no hay otra manera de hacer esto */
      /* skip the newline character like "chop" */
      buffer[strlen(buffer) - 1] = '\0';
      // get the length of buffer
      int slen = strlen(buffer);
      // allocate space for the buffer
      char* str = (char*)malloc((slen + 1) * sizeof(char));
      // copy string from buffer to string
      strcpy(str, buffer);
      // attach str to the data structure
      lines[i++] = str;
      /* i++; */
   }
   if(i == arrlen){
      char** new_arr = realloc(lines, (arrlen + 1) * sizeof(char*));
      if(!new_arr){
         fprintf(stderr, "Can't realocate the fucking chunk of memmory!!!");
         exit(1);
      }
      lines = new_arr;
   }
   /* put the fucking NULL at the end(whit this known when is finish) */
   lines[i] = NULL;
   return lines;
}
/*-------------------------------------------------------------------------
 *                        Credit stuff
 -------------------------------------------------------------------------*/
struct Credit {
   int credit_amount;
   int number_items;
   int* list;
};


static struct Data* read_Data(char* filename) {
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

static int* parse_list(char *line) {
   int num, i = 0, len;
   size_t line_length;
   line_length = strlen(line);
   int* list = NULL;
   list = (int*)malloc(sizeof(int) * line_length);
   while (sscanf( line, "%d%n", &num, &len) == 1) {
      list[i] = num;
      line += len;    // step past the number we found
      i++;            // increment our count of the number of values found
   }
   return list;
}

static struct Credit* create_cases(char** lines) {
   uint32_t i;
   uint32_t number_of_cases = atoi(lines[0]);
   number_of_cases = (int)(number_of_cases - '0');
   struct Credit* vector_credit = (struct Credit*)malloc(sizeof(struct Credit) * number_of_cases);
   for (i = 1; i < number_of_cases; i += 3) {
      vector_credit[i].credit_amount = atoi(lines[i]);
      vector_credit[i].number_items = atoi(lines[i + 1]);
      vector_credit[i].list = parse_list(lines[i + 2]);
   }
   /* printf("buffer[0]: %d\n", atoi(number_of_cases)); */
   return vector_credit;
}
/*-------------------------------------------------------------------------
 *                        main
 -------------------------------------------------------------------------*/

int main (int argc, char** argv)
{
   /* int i; */
   char* file_small_data_path = "/home/elsuizo/CodeJam/Problema_store_credit/Files/A-ssmall-practice.in";
   /* struct Data* data = read_Data(file_small_data_path); */
   /* create_cases(data); */

   char** words = load_file(file_small_data_path);
   struct Credit* vec = create_cases(words);
   /* print_Data_char(data); */

   free(vec);
}
