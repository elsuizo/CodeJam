/* -------------------------------------------------------------------------
@file credit.h

@date 04/23/17 16:01:57
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
#ifndef CREDIT_H
#define CREDIT_H
/*-------------------------------------------------------------------------
 *                        includes
 -------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

/*-------------------------------------------------------------------------
 *                        defines
 -------------------------------------------------------------------------*/
#define POOL_SIZE 10
/*-------------------------------------------------------------------------
 *                        datatypes
 -------------------------------------------------------------------------*/
struct Credit {
   int credit_amount;
   int number_items;
   int* list;
};

/*-------------------------------------------------------------------------
 *                        prototypes
 -------------------------------------------------------------------------*/
extern void
credit_initialize(struct Credit* ptr_Credit);
extern void
credit_initialize_pool(struct Credit** ptr_vCredit, uint32_t pool_size);

extern struct Credit*
credit_get_Credit_from_pool(struct Credit** ptr_vCredit, uint32_t pool_size);

extern struct Credit*
credit_return_Credit_to_pool(struct Credit** ptr_vCredit, struct Credit* ptr_Credit, uint32_t pool_size);

extern void
credit_deallocate_Credit(struct Credit* ptr_Credit);


#endif
