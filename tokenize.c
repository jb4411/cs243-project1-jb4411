/// file: tokenize.c 
//ze.c/ description: 
/// @author Jesse Burdick-Pless jb4411

#include <stdio.h>
#include "classes.h"
#include "matrix.h"
#include "scanner.h"

#define MAX_STATES 75

int main(int argc, char *argv[]) {
	if( argc < 2 ) {
		printf("usage: ./tokenize tmfile\n");
		return 1;
	}
	
	t_matrix tm[MAX_STATES][NUM_CLASSES];	
	int matrix_info[2] = {0};
	build_tm_file(argv[1], matrix_info, tm);
	
	int finished = 0;
	while( !finished ) {
		finished = scanner( matrix_info[0], matrix_info[1], tm );
	}
	return 0;
}	
