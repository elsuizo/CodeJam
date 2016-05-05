#= -------------------------------------------------------------------------
# @file test_soulution.jl
#
# @date 03/11/16 20:06:13
# @author Martin Noblia
# @email martin.noblia@openmailbox.org
#
# @brief
#
# @detail
#
  Licence:
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at
# your option) any later version.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
# 
# You should have received a copy of the GNU General Public License

---------------------------------------------------------------------------=#
include("./solution.jl")
#file_small = "../Files/A-ssmall-practice.in" Porque no anda los paths relativos
file_medium = "/home/elsuizo/CodeJam/Problema_store_credit/Files/A-small-practice.in"
file_small = "/home/elsuizo/CodeJam/Problema_store_credit/Files/A-ssmall-practice.in"
file_large = "/home/elsuizo/CodeJam/Problema_store_credit/Files/A-large-practice.in"

cases_vec = Credit.create_cases(file_large) 

Credit.filter_cases(cases_vec)
