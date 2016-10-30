#= -------------------------------------------------------------------------
# @file solution.jl
#
# @date 12/16/15 22:43:38
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

module Credit
"""
Type for encapsulate a test cases
"""
type Cases
    c::Int
    I::Int
    L::Vector{Int}
end

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
    lines_array = Array{UTF8String, 1}()
    for line in eachline(io)
        push!(lines_array, chomp(line))
    end 
    return lines_array
end

lines(path::AbstractString) = open(lines, path)



"""
Parse the text file and create the test cases

Input: file_name(ASCIIString)
------
Ouput: cases_vec(Vector{Cases})
------

Example:
--------
`cases_vec = create_cases(file_name)`
"""
function create_cases(file_name::String)

    data = Credit.lines(file_name)
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
    return cases_vec
end

"""
Function for find the cases in that the credit is a sum of two items

Input: cases(Array{Credit.Cases, 1})
"""

function filter_cases(cases::Array{Credit.Cases, 1})
   for case in 1:length(cases)
      size = cases[case].I
      s = cases[case].c
      for i in 1:size
         for j in i:size
            if((cases[case].L[i] + cases[case].L[j] == s) && i != j)
               #println("index $i + index $j = credit $s")
               println("Case #$case: $i  $j")
            end
         end
      end
   end
end


end


