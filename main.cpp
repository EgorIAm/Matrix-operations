#include "matrix.h"
#include "unit_test.h"

int main() {
	test();
	//Matrix A{ {{1,2,3},{4,5,6},{7,8,0},{1,2,3}} };
	//A.triangulate().show();
	//Matrix B{ {{1,2,3},{4,5,6},{7,8,0},{1,2,5,4} }};

	//add(A, B).show();

	Matrix reqValMatr1({ { 1,2,3,4 }, { 2,4,6,8 }, { 5,6,7,9 } });
	reqValMatr1.triangulate().show();

}
