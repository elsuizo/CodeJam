/* -------------------------------------------------------------------------
@file credit.c

@date 06/14/17 21:47:48
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
#include "../inc/credit.h"


char** credit_load_file(char* filename){
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
   char buffer[10000];
   int i = 0;
   while(fgets(buffer, 10000, f)){
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

int* credit_parse_elements(char* numbers_string, int size) {
   int* result = malloc(sizeof(int) * size);
   char* record;
   record = strtok(numbers_string, " ");
   int i = 0;
   while (record != NULL) {
      result[i++]= atoi(record);
      record = strtok(NULL, " ");
   }

   return(result);
}
struct Credits* credit_create_cases(char** lines) {
   int i, j;
   int number_of_cases = atoi(lines[0]);
   struct Credits* result = malloc(sizeof(struct Credits) * number_of_cases);
   for(j = 3, i = 0; lines[j] != NULL && i < number_of_cases; j += 3, i++){
      result[i].credit = atoi(lines[j - 2]);
      result[i].number_of_items = atoi(lines[j - 1]);
      result[i].elements = credit_parse_elements(lines[j], result[i].number_of_items);
   }
   return(result);
}

void credit_show_credits(struct Credits* c, int size) {
   int i;
   int j;
   for (i = 0; i < size; i++) {
      printf("Credit[%d] ---> credits: %d\n", i, c[i].credit);
      printf("Credit[%d] ---> number_of_items: %d\n", i, c[i].number_of_items);
      for (j = 0; j < c[i].number_of_items; j++) {
         printf("Credits[%d] ---> elements[%d]: %d\n", i, j, c[i].elements[j]);
      }
   }

}

void credit_filter_cases(struct Credits* c, int size) {
   int i;
   int j;
   int k;
   for (i = 0; i < size; i++) {
      for (j = 0; j < c[i].number_of_items; j++) {
         for (k = j; k < c[i].number_of_items; k++) {
            if ((c[i].elements[j] + c[i].elements[k] == c[i].credit) && k != j) {
               printf("Case#:%d %d %d\n", i, j, k);
            }
         }
      }
   }
}
