#[[
This program is free software: you can redistribute it and/or 
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see https://www.gnu.org/licenses/.
 
Author Marco M. Mosca, email: marcomichele.mosca@gmail.com
]]

project(cmd_api_test LANGUAGES CXX C)

add_executable (longopt_basic ${CMAKE_CURRENT_SOURCE_DIR}/longopt_basic.cpp)
add_executable (longopt_unknownopt_error ${CMAKE_CURRENT_SOURCE_DIR}/longopt_unknownopt_error.cpp)
add_executable (longopt_shortopt_error ${CMAKE_CURRENT_SOURCE_DIR}/longopt_shortopt_error.cpp)
add_executable (longopt_nodash_error ${CMAKE_CURRENT_SOURCE_DIR}/longopt_nodash_error.cpp)
add_executable (longopt_missedarg_error ${CMAKE_CURRENT_SOURCE_DIR}/longopt_missedarg_error.cpp)
add_executable (longopt_noargexpected_error ${CMAKE_CURRENT_SOURCE_DIR}/longopt_noargexpected_error.cpp)
add_executable (longopt_format_missedbar_error ${CMAKE_CURRENT_SOURCE_DIR}/longopt_format_missedbar_error.cpp)
add_executable (longopt_format_missedendbar_error ${CMAKE_CURRENT_SOURCE_DIR}/longopt_format_missedendbar_error.cpp)

target_link_libraries (longopt_basic PRIVATE cmd-api)
target_link_libraries (longopt_unknownopt_error PRIVATE cmd-api)
target_link_libraries (longopt_shortopt_error PRIVATE cmd-api)
target_link_libraries (longopt_nodash_error PRIVATE cmd-api)
target_link_libraries (longopt_missedarg_error PRIVATE cmd-api)
target_link_libraries (longopt_noargexpected_error PRIVATE cmd-api)
target_link_libraries (longopt_format_missedbar_error PRIVATE cmd-api)
target_link_libraries (longopt_format_missedendbar_error PRIVATE cmd-api)

add_test (NAME longopt_basic COMMAND longopt_basic)
add_test (NAME longopt_unknownopt COMMAND longopt_unknownopt_error)
add_test (NAME longopt_shortopt COMMAND longopt_shortopt_error)
add_test (NAME longopt_nodash COMMAND longopt_nodash_error)
add_test (NAME longopt_missedarg COMMAND longopt_missedarg_error)
add_test (NAME longopt_noargexpected COMMAND longopt_noargexpected_error)
add_test (NAME longopt_format_missedbar COMMAND longopt_format_missedbar_error)
add_test (NAME longopt_format_missedendbar COMMAND longopt_format_missedendbar_error)

set_tests_properties(
    longopt_unknownopt
    longopt_shortopt
    longopt_nodash
    longopt_missedarg
    longopt_noargexpected
    longopt_format_missedbar
    longopt_format_missedendbar
    PROPERTIES WILL_FAIL TRUE
)
