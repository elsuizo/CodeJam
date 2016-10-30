#= -------------------------------------------------------------------------
# @file test_solution.jl
#
# @date 10/28/16 23:55:33
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
include("solution.jl")

# TODO(elsuizo): Parece que los paths relativos no andan
path_small = "/home/elsuizo/CodeJam/Reverse_words/Files/B-small-practice.in"
path_large = "/home/elsuizo/CodeJam/Reverse_words/Files/B-large-practice.in"

#L, S = Reverse.create_cases(path_small);
L, S = Reverse.create_cases(path_large);

Reverse.print_results(L)

