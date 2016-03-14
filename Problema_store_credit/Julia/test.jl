#= -------------------------------------------------------------------------
# @file test.jl
#
# @date 03/10/16 10:38:00
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
N = length(readlines(STDIN))
re = r"\+?\d+" # regular expresion for find numbers
for i = 2:10
    for j = 1:3
        for line in readlines(STDIN)
        #println(chomp(line))
        line = chomp(line)
        #line = filter(x-> x != ' ', line)
        @show s = [parse(Int, s) for s in matchall(re, line)] 
        end
    end
end


