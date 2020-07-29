#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main () {

    MatrixXd X = MatrixXd::Zero(5,5);
    cout << ( MatrixXd(2,2) << 1,2,3,4 ).finished() << endl;
	return 0;
}


