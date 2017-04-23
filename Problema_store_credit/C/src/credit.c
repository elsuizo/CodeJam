/* -------------------------------------------------------------------------
@file credit.c

@date 04/23/17 16:07:39
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
/* includes */
#include "../inc/credit.h"


void credit_initialize(struct Credit* ptr_Credit) {
   ptr_Credit->credit_amount = 0;
   ptr_Credit->number_items = 0;
   ptr_Credit->list = NULL;
}

extern void
credit_initialize_pool(struct Credit** ptr_vCredit, uint32_t pool_size) {
   uint32_t i;
   for (i = 0; i < pool_size; i++) {
      ptr_vCredit[i] = NULL;
   }

}

/**
 * @brief Allocate memory for a Credit struct only when new one is required
 *
 * @param ptr_vCredit
 * @param pool_size
 *
 * @return Pointer to a new instance of Credit struct
 */
extern struct Credit*
credit_get_Credit_from_pool(struct Credit** ptr_vCredit, uint32_t pool_size) {
   uint32_t i;
   /* iterate over the pool memory */
   for (i = 0; i < pool_size; i++) {
      if (ptr_vCredit[i] != NULL) {
         struct Credit* ptr_Credit = ptr_vCredit[i];
         ptr_vCredit[i] = NULL;
         return ptr_Credit;
      }
   }
   struct Credit* ptr_Credit2 = malloc(sizeof(struct Credit));
   return ptr_Credit2;
}

/**
 * @brief
 *
 * @param ptr_vCredit
 * @param ptr_Credit
 * @param pool_size
 *
 * @return
 */
extern struct Credit*
credit_return_Credit_to_pool(struct Credit** ptr_vCredit, struct Credit* ptr_Credit, uint32_t pool_size) {
   uint32_t i;
   for (i = 0; i < pool_size; i++) {
      if (ptr_vCredit[i] == NULL) {
         ptr_vCredit[i] = ptr_Credit;
         return ptr_Credit;
      }
   }
   credit_deallocate_Credit(ptr_Credit);
   free(ptr_Credit);
   return NULL;
}


extern void
credit_deallocate_Credit(struct Credit* ptr_Credit) {
   free(ptr_Credit->list);
}
