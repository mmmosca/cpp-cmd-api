/*
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
*/
#ifndef CMD_H_
#define CMD_H_

#ifdef DEBUG
#define PRINT_DATA()	printf("CURRENT ---- OPTIND: %d ---- ARGVIND: %d ---- OPTION: %c ---- OPTARG: %s\n", optind, argvind, argv[optind][1], myoptarg);
#define PRINT_DATAW()	printf("CURRENT ---- OPTIND: %d ---- ARGVIND: %d ---- OPTION: %s ---- OPTARG: %s\n", optind, argvind, argv[optind], myoptarg);
#else
#define PRINT_DATA()	{};
#define PRINT_DATAW()	{};
#endif

#include <stdio.h>
#include <string.h>
#include <Windows.h>


struct CommandLine {
private:
	/*option index in the array of line commands*/
	/*argument index in the array of line commands*/
	int optind, argvind, start, formatind, argformatind;
	/*pointer to the argument*/
	char *curr_option;

	int isCharInString(char c, char* str);
	int AreStringsEqualFrom(const char* s1, const char* s2, int from);
	int isSubstring(char* sub, char* str);
	char* strsep(char** elem_pointer, char* pattern);
	void reset_values();
public:
	char* myoptarg;

	CommandLine() : start{ 1 }, formatind{ -1 }, argformatind{ 0 } {
		reset_values();
	};

	char* mygetoptW(int argc, char** argv, char* format);
};
#endif /* CMD_H_ */