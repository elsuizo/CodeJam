/* -------------------------------------------------------------------------
@file credit.h

@date 06/14/17 21:43:59
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
#ifndef _CREDIT_H
#define _CREDIT_H
/*-------------------------------------------------------------------------
 *                        includes
 -------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*-------------------------------------------------------------------------
 *                        defines
 -------------------------------------------------------------------------*/
#define STEPSIZE 100

/*-------------------------------------------------------------------------
 *                        datatypes
 -------------------------------------------------------------------------*/
struct Credits {
   int credit;
   int number_of_items;
   int* elements;
};

char** credit_load_file(char* filename);

struct Credits* credit_create_cases(char** lines);

void credit_show_credits(struct Credits* c, int size);

void credit_filter_cases(struct Credits* c, int size);
#endif
