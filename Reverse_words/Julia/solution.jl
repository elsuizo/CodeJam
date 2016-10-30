#= -------------------------------------------------------------------------
# @file solution.jl
#
# @date 10/28/16 23:51:31
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
module Reverse


"""
Function for returning the lines of text file
"""
function read_file(str::AbstractString) 
    file = open(str)
    lines = eachline(file)
    close(file)
    return lines
end

function lines(io::IO)
    lines_array = Array{String, 1}()
    for line in eachline(io)
        push!(lines_array, chomp(line))
    end 
    return lines_array
end

lines(path::AbstractString) = open(lines, path)

"""
Function for generate the cases
"""
function create_cases(file_name::String)

   data = lines(file_name)
   number_of_cases = parse(Int, data[1])

   S = [reverse(split(s)) for s in data[2:end]] # S Strings in reverse
   L = Array{String, 1}()
   for s in S
      l = length(s)
      if l > 1
         # concatenate with products
         aux = prod(s .* " ")
         aux = strip(aux) # strip the last whitespace introduce
         push!(L, aux)
      end
      if l == 1
         push!(L, s[1])
      end
   end
   return L, S
end

"""
Function for print the cases results

"""
function print_results(L::Array{String, 1})

   for (num, s) in enumerate(L)
      println("Case #$num: $s")
   end

end

end
