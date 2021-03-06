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
#include "../inc/credit.h"

/*-------------------------------------------------------------------------
 *                        main
 -------------------------------------------------------------------------*/
int main(void)
{
   /* char* file_ssmall_path = "/home/elsuizo/Repos/CodeJam/Problema_store_credit/Files/A-ssmall-practice.in"; */
   /* char* file_small_path = "/home/elsuizo/Repos/CodeJam/Problema_store_credit/Files/A-small-practice.in"; */
   char* file_large = "/home/elsuizo/Repos/CodeJam/Problema_store_credit/Files/A-large-practice.in";
   char** lines = credit_load_file(file_large);
   struct Credits* credits = credit_create_cases(lines);
   int number_elements = atoi(lines[0]);
   /* printf("numero de creditos: %d", credits[0].credit); */
   /* credit_show_credits(credits, number_elements); */
   printf("Number of elements: %d\n", number_elements);
   credit_filter_cases(credits, number_elements);

   return(0);
}
