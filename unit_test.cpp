#include <cassert>
#include "matrix.h"

void test() {
	Matrix voidMatr;
	assert(voidMatr.isValid() == 0);
	assert(voidMatr.isSquare() == 0);
	assert(voidMatr.getDet() == 0);
	assert(voidMatr.getRank() == 0);
	voidMatr.triangulate().show();
	voidMatr.transpose().show();

	Matrix voidMatr2{};
	assert(voidMatr2.isValid() == 0);
	assert(voidMatr2.isSquare() == 0);
	assert(voidMatr2.getDet() == 0);
	assert(voidMatr2.getRank() == 0);
	voidMatr2.triangulate().show();
	voidMatr2.transpose().show();

	Matrix voidMatr3{ {{}} };
	assert(voidMatr3.isValid() == 0);
	assert(voidMatr3.isSquare() == 0);
	assert(voidMatr3.getDet() == 0);
	assert(voidMatr3.getRank() == 0);
	voidMatr3.triangulate().show();
	voidMatr3.transpose().show();

	Matrix voidMatr4{ {{}, {}} };
	assert(voidMatr4.isValid() == 0);
	assert(voidMatr4.isSquare() == 0);
	assert(voidMatr4.getDet() == 0);
	assert(voidMatr4.getRank() == 0);
	voidMatr4.triangulate().show();
	voidMatr4.transpose().show();

	std::cout << "singleMatr\n";
	Matrix singleMatr{ {{1}} };
	assert(singleMatr.isValid() == 1);
	assert(singleMatr.isSquare() == 1);
	assert(singleMatr.getDet() == 1);
	assert(singleMatr.getRank() == 1);
	singleMatr.triangulate().show();
	singleMatr.transpose().show();

	std::cout << "reqInvMatr\n";
	Matrix reqInvMatr({ {1,2,3,4}, {1,1}, {2,2,3} });
	assert(reqInvMatr.isValid() == 0);
	assert(reqInvMatr.isSquare() == 0);
	assert(reqInvMatr.getDet() == 0);
	assert(reqInvMatr.getRank() == 0);
	reqInvMatr.triangulate().show();
	reqInvMatr.transpose().show();

	std::cout << "sqInvMatr1\n";
	Matrix sqInvMatr1({ {1,2,3}, {1,1}, {2,2,3} });
	assert(sqInvMatr1.isValid() == 0);
	assert(sqInvMatr1.isSquare() == 0);
	assert(sqInvMatr1.getDet() == 0);
	assert(sqInvMatr1.getRank() == 0);
	sqInvMatr1.triangulate().show();
	sqInvMatr1.transpose().show();

	std::cout << "reqInvMatr2\n";
	Matrix sqInvMatr2({ {1,2,3}, {}, {2,2,3} });
	assert(sqInvMatr2.isValid() == 0);
	assert(sqInvMatr2.isSquare() == 0);
	assert(sqInvMatr2.getDet() == 0);
	assert(sqInvMatr2.getRank() == 0);
	sqInvMatr2.triangulate().show();
	sqInvMatr2.transpose().show();

	std::cout << "sqValMatr:\n";
	Matrix sqValMatr({ {1,2,3}, {1,1,2}, {2,2,3} });
	assert(sqValMatr.isValid() == 1);
	assert(sqValMatr.isSquare() == 1);
	assert(sqValMatr.getDet() == 1);
	assert(sqValMatr.getRank() == 3);
	sqValMatr.show("\n");
	sqValMatr.triangulate().show("\n");
	sqValMatr.transpose().show();

	std::cout << "reqValMatr1:\n";
	Matrix reqValMatr1({ { 1,2,3,4 }, { 3,4,5,6 }, { 7,8,9,10 } });
	assert(reqValMatr1.isValid() == 1);
	assert(reqValMatr1.isSquare() == 0);
	assert(reqValMatr1.getDet() == 0);
	assert(reqValMatr1.getRank() == 2);
	reqValMatr1.show("\n");
	reqValMatr1.triangulate().show("\n");
	reqValMatr1.transpose().show();

	std::cout << "reqValMatr3:\n";
	Matrix reqValMatr3({ { 1,2,3,4 } });
	assert(reqValMatr3.isValid() == 1);
	assert(reqValMatr3.isSquare() == 0);
	assert(reqValMatr3.getDet() == 0);
	assert(reqValMatr3.getRank() == 1);
	reqValMatr3.show("\n");
	reqValMatr3.triangulate().show("\n");
	reqValMatr3.transpose().show();

	std::cout << "reqValMatr4:\n";
	Matrix reqValMatr4({ { 1},{2},{3},{4} });
	assert(reqValMatr4.isValid() == 1);
	assert(reqValMatr4.isSquare() == 0);
	assert(reqValMatr4.getDet() == 0);
	assert(reqValMatr4.getRank() == 1);
	reqValMatr4.show("\n");
	reqValMatr4.triangulate().show("\n");
	reqValMatr4.transpose().show();

	std::cout << "reqValMatr1:\n";
	Matrix reqValMatr2({ { 1,2,3}, {4, 3, 4},{5, 6, 7},{8, 9, 10} });
	assert(reqValMatr2.isValid() == 1);
	assert(reqValMatr2.isSquare() == 0);
	assert(reqValMatr2.getDet() == 0);
	assert(reqValMatr2.getRank() == 3);
	reqValMatr2.show("\n");
	reqValMatr2.triangulate().show("\n");
	reqValMatr2.transpose().show();

	std::cout << "sqValMatr2:\n";
	Matrix sqValMatr2({ { 1,1,1}, {1, 1, 1},{1, 1, 1} });
	assert(sqValMatr2.isValid() == 1);
	assert(sqValMatr2.isSquare() == 1);
	assert(sqValMatr2.getDet() == 0);
	assert(sqValMatr2.getRank() == 1);
	sqValMatr2.show("\n");
	sqValMatr2.triangulate().show("\n");
	sqValMatr2.transpose().show();

	std::cout << "sqValMatrLinearComb:\n";
	Matrix sqValMatrLinearComb({ { 2,3,4}, {2, 3, 4},{2, 3, 4} });
	assert(sqValMatrLinearComb.isValid() == 1);
	assert(sqValMatrLinearComb.isSquare() == 1);
	assert(sqValMatrLinearComb.getDet() == 0);
	assert(sqValMatrLinearComb.getRank() == 1);
	sqValMatrLinearComb.show("\n");
	sqValMatrLinearComb.triangulate().show("\n");
	sqValMatrLinearComb.transpose().show();

	std::cout << "sqValMatrNull:\n";
	Matrix sqValMatrNull({ { 0,0,0}, {0, 0, 0},{0, 0, 0} });
	assert(sqValMatrNull.isValid() == 1);
	assert(sqValMatrNull.isSquare() == 1);
	assert(sqValMatrNull.getDet() == 0);
	assert(sqValMatrNull.getRank() == 0);
	sqValMatrNull.show("\n");
	sqValMatrNull.triangulate().show("\n");
	sqValMatrNull.transpose().show();

	assert(areEqual(sqValMatr, sqValMatr2) == 0);
	assert(areEqual(sqValMatr, sqValMatr) == 1);
	assert(areEqual(reqValMatr3, reqValMatr4) == 0);

	sqValMatr.show("\n");
	multiply(sqValMatr, 2).show("\n");
	sqValMatr2.show("\n");
	multiply(sqValMatr2, 1.5).show("\n");
	reqValMatr1.show("\n");
	
	Matrix oneToNine{ {{1,2,3,4,5,6,7,8,9}} };
	Matrix oneToNine2{ oneToNine.values };
	oneToNine2.transpose();
	multiply(oneToNine2, oneToNine).show();

}