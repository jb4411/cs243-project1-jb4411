/// file: scanner.c
/// description:
/// @author Jesse Burdick-Pless jb4411

#include "scanner.h"

#define MAX_TOKEN_SIZE 79

int classify( int chr ) {
	if( chr == ' ' || chr == '\t' || chr == '\n' ) {
		return CC_WS;
	} else if( (chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || chr == '_' ) {
		return CC_ALPHA;
	} else if( chr == '0' ) {
		return CC_ZERO;
	} else if( chr >= '1' && chr <= '7' ) {
		return CC_OCTAL;
	} else if( chr == '8' || chr == '9' ) {
		return CC_DECIMAL;
	} else if( chr == '/' ) {
		return CC_SLASH;
	} else if( chr == '*' )	{
		return CC_STAR;
	} else if( chr == '+' || chr == '-' || chr == '%' ) {
		return CC_ARITH;
	} else if( __isascii(chr) ) {
		return CC_OTHER;
	} else if( chr == EOF ) {
		return CC_EOF;
	} else {
		return CC_ERROR;
	}

}

int scanner( int start, int accept, t_matrix tm[][NUM_CLASSES] ) {
	char buf[MAX_TOKEN_SIZE];
	int buf_idx = 0;
	int current_state = start;
	int chr = ' ';
	t_matrix transition; 

	printf("%d ", current_state);
	while( current_state != accept ) {
		chr = getchar();
		transition = tm[current_state][classify(chr)];
		current_state = transition.next;
		printf("%d ", current_state);
		if( current_state == 99 ) {
			while( classify(chr) != CC_WS ) {
				chr = getchar();	
			}
			printf("rejected\n");
			return 0;
		} else if( chr == EOF ) {
			printf("EOF\n");
			return 1;
		} else if( transition.action == 's' ) {
			buf[buf_idx] = (char) chr;
			buf_idx++;
		}
	}

	buf[buf_idx] = '\0';
	printf("recognized '%s'\n", buf);
	return 0;
}

