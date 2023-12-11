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
#include "cmd-api.h"
#include <string>
#include <cassert>


void test_longopt_basic()
{
  CommandLine cmd;
  char* arr[] = {"exe", "-opt1", "val1", "-opt2", "val2"};
  char* w;
  
	while ((w = cmd.mygetoptW(5, arr, "opt1:|opt2:|")) != NULL) {
		if (strcmp(w, "opt1") == 0) {
			assert(strcmp(cmd.myoptarg, "val1") == 0);
			continue;
		}
		if (strcmp(w, "opt2") == 0) {
			assert(strcmp(cmd.myoptarg, "val2") == 0);
			continue;
		}
	}
}

int main()
{
  test_longopt_basic();
  return 0;
}