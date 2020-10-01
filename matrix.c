/// file: matrix.c
/// description: matrix.c is the implementation for the function that builds a
/// transition matrix.
/// @author Jesse Burdick-Pless jb4411

#include "matrix.h"

/// build the transition matrix

void build_tm_file( char *filename, int matrix_info[2], t_matrix tm[][NUM_CLASSES] ) {
	FILE *fp;

	// open the TM file
	fp = fopen( filename, "r" );

	// check to be sure the open succeeded
	if( fp == NULL ) {
		// something went wrong - report it, and exit
		perror( filename );
		exit( EXIT_FAILURE );
	}

	char *ptr, buf[BUFLENGTH];

	char *token;
	const char dilm[4] = " \t\n";
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
		token = strtok(buf, dilm);
		while( token != NULL ) {
			n = sscanf( token, "%d/%d%c", &class, &next, &action );
			if( n == 1 ) {
				switch( i ) {
					case 0:
						states = class;
						// fill in transitions with 99d
						int row, col;
						for(row = 0; row < states; row++) {
							for(col = 0; col < NUM_CLASSES; col++) {
								tm[row][col].next = 99;
								tm[row][col].action = 'd';
							}
						}
						break;
					case 1:
						start = class;
						break;
					case 2:
						accept = class;
						break;
					default:
						current_state = class;
				}
				i++;
			} else if( n > 1 ) {
				tm[current_state][class].next = next;
				tm[current_state][class].action = action;
			}

			token = strtok(NULL, dilm);
		}
	}

	// when done, close the input stream
	fclose( fp );

	// print the matrix
	printf("Scanning using the following matrix:\n ");
	for(i = 0; i < NUM_CLASSES; ++i) {
		printf("    %d", i);
	}	
	printf("\n");

	i = start;
	while( i < states ) {
		printf( " %d  ", i );
		for(int j = 0; j < NUM_CLASSES; ++j) {
			if( tm[i][j].next < 10 ) { 
				printf(" ");
			}
			printf("%d%c  ", tm[i][j].next, tm[i][j].action);
		}
		printf("\n");
		i++;
	}

	matrix_info[0] = start;
	matrix_info[1] = accept;
}

