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
file_small = "/home/elsuizo/CodeJam/ProblemA_store_credit/A-ssmall-practice.in"
file_medium = "/home/elsuizo/CodeJam/ProblemA_store_credit/A-small-practice.in"
data = Credit.lines(file_medium)
data_size = length(data)

re = r"\+?\d+" # regular expresion for find numbers
number_of_cases = parse(Int, data[1])
cases_vec = Vector{Credit.Cases}()
for i = 2:3:data_size - 1
    c = parse(Int, data[i]) 
    I = parse(Int, data[i+1])
    L = [parse(Int, s)  for s in matchall(re, data[i+2])] 
    push!(cases_vec, Credit.Cases(c, I, L))
end

