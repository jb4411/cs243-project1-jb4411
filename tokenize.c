/// file: review_grades.c
/// description: 
/// @author Jesse Burdick-Pless jb4411

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "classes.h"

int main(int argc, char *argv[]) {
	if( argc < 2 ) {
		printf("usage: ./tokenize tmfile");
		return 1;
	}

	FILE *fp;

	// open the TM file
	fp = fopen( argv[1], "r" );

	// check to be sure the open succeeded
	if( fp == NULL ) {
		// something went wrong - report it, and exit
		perror( argv[1] );
		exit( EXIT_FAILURE );
	}

	char *ptr, buf[BUFLENGTH];

	char *token;
	const char dilm[4] = " \t\n"

		int states = 0;
	int start = 0;
	int accept = 0;
	int n = 0;
	int i = 0;
	int class = 0;
	int next = 0;
	char action = ' ';
	int current_state = 0;
	// read and process all the lines from the file
	while( (ptr = fgets(buf, BUFLENGTH, fp)) != NULL ) {
		// process this line from the file
		token = strtok(buf, " \t\n");
		while( token != NULL ) {
			n = sscanf( token, "%d/%d%c", &class, &next, &action ); 
			if( n == 1 ) {	
				switch( i ) {
					case 0:
						states = class;
						break;
					case 1:
						//initlize struct thing with struct[states][states];
						start = class
						break;
					case 2:
						accept = class
						break;
					default:
						current_state = class;
				}
				i++;
			} else {
				// struct[current_state][class]
			}
		}

		token = strtok(NULL, " \t\n");
	}

	// when done, close the input stream
	fclose( fp );
}
