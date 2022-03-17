#include "uwulib.h"

#include <stdlib.h>
#include <string.h>

// internal
void _uwulib_replace(char* str, const char* original, const char* uwufied) {
	char* pch = strstr(str, original);
	if (pch != NULL) {
		int slen = strlen(uwufied);
		for (int i = 0; i < slen; i++)
			pch[i] = uwufied[i];
	}
}

// internal
char* UwuPackageName(char* str) {
	_uwulib_replace(str, "brew", "bwew");
	return str;
}

// public
void _uwulib_jumpnbsp(char** ptr, char** out) {
	if (
		(*ptr)[0] == '&' && (*ptr)[1] == 'n' && (*ptr)[2] == 'b' && (*ptr)[3] == 's' && (*ptr)[4] == 'p' && (*ptr)[5] == ';') {
		**out = ' ';
		*out += 1;
		*ptr += 6;
	} else {
		**out = '&';
		*out += 1;
		*ptr += 1;
	}
}

// public
char* replacenbsp(char* str) {
	int slen = strlen(str);

	char* curr	 = str;
	char* result = malloc(sizeof(result) * slen);
	char* resptr = result;

	while (*curr != '\0') {
		if (*curr != '&') {
			*resptr++ = *curr;
			curr++;
			continue;
		}

		_uwulib_jumpnbsp(&curr, &resptr);
	}

	return result;
}
