#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main () {

    MatrixXd X = MatrixXd::Zero(5,5);
    MatrixXd Y = MatrixXd::Zero(5,5);
    // VectorXd V = X;
    cout << ( MatrixXd(2,2) << 1,2,3,4 ).finished() << endl;
    cout << MatrixXd::Constant(3,3,1.2) << endl;
    cout << MatrixXd::Constant(1,1,0.01) << endl;
    vector<double> vec = {0,1,2,3,4,10,11,12,13,14};

    auto x_it = vec.begin();
    auto y_it = x_it + X.cols();
    int i = 0;
    for_each(x_it, y_it, 
            [&X, i]( auto el ) mutable {
                X(i,i) = el; i++; });
    cout << endl;
    for_each(y_it, vec.end(), [&Y, i] (auto el) mutable { Y(i,i) = el; i++;  });
    cout << endl;
    cout << X;
    cout << endl;
    cout << Y;
    cout << endl;
    Y.setZero();
    cout << Y;
    cout << endl;
    vector<double> str {0.1,0.2,0.3};
    // cout << VectorXd(str.data()) << endl;  // Doesn't work!!
    const int size = 3;
    cout << Eigen::Matrix<double,size,1> (str.data()) << endl;
    cout << Vector3d (str.data()) << endl;
    map<double, pair< vector<double>, function<void(vector<double>)>>> m;
    m.insert(make_pair(0.1, make_pair(vector<double>{0.12,1.2,12}, [](vector<double>v){cout << "v.size(): " << v.size() << endl;})));
    m.insert(make_pair(0.2, make_pair(vector<double>{0.12,1.2,12, 21.2}, nullptr)));
    auto item = m.at(0.1);
    for(auto it: m){
        if(it.second.second)
            it.second.second(it.second.first);
        else cout << "No lambda!" << endl;
    }
	return 0;
}


