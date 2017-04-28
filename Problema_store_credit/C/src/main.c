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
/* #include "../inc/credit.h" */
#include "../inc/data.h"

/*-------------------------------------------------------------------------
 *                        main
 -------------------------------------------------------------------------*/
int main(void)
{
   char* file_ssmall_path = "/home/elsuizo/CodeJam/Problema_store_credit/Files/A-ssmall-practice.in";
   struct Data data = read_Data(file_ssmall_path);
   /* print_Data(&data); */
   char* cursor = data.buffer;
   /* int number_of_cases = atoi(*cursor); */
   /* printf("the number of cases is: %d", number_of_cases); */
   while (*cursor++) {
      printf("%c", *(cursor + 1));
   }

}
