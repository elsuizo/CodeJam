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
#include "../inc/data.h"

/*-------------------------------------------------------------------------
 *                        main
 -------------------------------------------------------------------------*/
int main (int argc, char** argv)
{
   /* create a pool memory */
   struct Credit** ptr_vCredit;
   const uint32_t pool_size = 100;
   ptr_vCredit = malloc(sizeof(struct Credit*) * pool_size);
   credit_initialize_pool(ptr_vCredit, pool_size);
   /* test for add a Credit in the pool */
   struct Credit* ptr_Credit;
   ptr_Credit = credit_get_Credit_from_pool(ptr_vCredit, pool_size);
   credit_initialize(ptr_Credit);
   credit_return_Credit_to_pool(ptr_vCredit, ptr_Credit, pool_size);
   /*-------------------------------------------------------------------------
    *                        load the data buffer
    -------------------------------------------------------------------------*/
   char* path_small_data = "/home/elsuizo/CodeJam/Problema_store_credit/Files/A-ssmall-practice.in";
   struct Data* data = {0};
   data = read_Data(path_small_data);
   print_Data_char(data);
   /* free the data buffer */
   free_Data(data);

   return 0;
}
