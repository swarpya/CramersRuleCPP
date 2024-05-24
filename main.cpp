#include <Eigen/Dense>
#include <iostream>
using namespace std;
using namespace Eigen;

int main()
{
    
    int rows, cols;
    cout<<"enter number of Rows for Matrix: ";
    cin>>rows;

    cout<<"enter number of Columns for Matrix: ";
    cin>>cols;

      MatrixXd A(rows,cols);

    cout << "Enter the elements of the matrix:" <<endl;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
                cin >> A(row, col);
        }
    }
    cout<<"Enter"<<rows<<" values of b"<<endl;
    VectorXd b(rows);
   for (int i = 0; i < rows; ++i) {
        cin >> b(i);
    }

    double detA = A.determinant();

    cout <<endl<< "det(A) = " << detA << endl;
    if(detA == 0){
        cout<<"No unique solution."<<endl;

        return 1;
    }

    VectorXd x(rows);

    for(int i = 0; i< A.cols();++i)
    {
        MatrixXd Ai(rows,cols);
        Ai = A;
        Ai.col(i) = b;
        x(i) = Ai.determinant()/ detA;
    }

    cout<<"solution:"<<endl<<x<<endl;
return 0;
}
