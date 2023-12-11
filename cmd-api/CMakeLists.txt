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

IF(WIN32)
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
ENDIF()

set( INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" )
set( SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src" )

set( HEADER_FILES ${INCLUDE_DIR}/cmd-api.h)
set( SRC_FILES ${SRC_DIR}/cmd-api.cpp)

if (SHARED)
    add_library(${PROJECT_NAME} SHARED ${SRC_FILES} ${HEADER_FILES})
ELSE()
    add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${HEADER_FILES})
ENDIF()
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${HEADER_FILES} DESTINATION include)
