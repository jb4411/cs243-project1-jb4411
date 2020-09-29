/// file: scanner.c
/// description:
/// @author Jesse Burdick-Pless jb4411

#include "scanner.h"

#define MAX_TOKEN_SIZE 79

int classify( char chr ) {
	if( chr == ' ' || chr == '\t' || chr == '\n' ) {
		return CC_WS;
	} else if( (chr >= 'A' && chr <= 'Z') || (chr >= 'a' && <= 'z') || chr == '_' ) {
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
	} else if( chr >= 0 && <= 127 ) {
		return CC_OTHER;
	} else if( chr == EOF ) {
		return CC_EOF;
	} else {
		return CC_ERROR;
	}

}

char* scanner( int states, int start, int accept ) {
	char buf[MAX_TOKEN_SIZE];
	int buf_idx = 0;
	int current_state = start;
	char chr = ' ';
	t_matrix transition; 

	printf("%d ", current_state);
	while( current_state != accept ) {
		chr = getchar();
		transition = tm[current_state][classify(chr)];
		current_state = transition.next;
		printf("%d ", current_state);
		if( current_state == 99 ) {
			buf = NULL;
			while( classify(chr) != CC_WS ) {
				chr = getchar();	
			}
			break;
		} else if( chr == EOF ) {
			printf("EOF\n");
			break;
		} else if( transition.action == 's' ) {
			buf[buf_idx] = chr;
			buf_idx++;
		}
	}

	// put in tokenize?
	if( buf == NULL ) {
		printf("rejected\n")
	} else {
		buf[buf_idx] = '\0';
		printf("recognized %s\n", buf);
	}
}

