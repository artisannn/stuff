#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main () {

    MatrixXd X = MatrixXd::Zero(5,5);
    // VectorXd V = X;
    cout << ( MatrixXd(2,2) << 1,2,3,4 ).finished() << endl;
    cout << MatrixXd::Constant(3,3,1.2) << endl;
    cout << MatrixXd::Constant(1,1,0.01) << endl;
	return 0;
}


