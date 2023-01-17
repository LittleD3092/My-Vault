Tag: #cpp 
Previous: 
Link: [[Matrix]], [[Vector]], [[Eigenvalue]], [[Eigenvector]]

---

[TOC]

---

A c++ library for matrix and vector operations. Like [[numpy]] in python.

Some examples are listed.

# Basic

Contains some basic `Eigen` matrix and vector manipulation.

- Vector and matrix declaration
- Multiplication
- [[Eigenvalue]] and [[Eigenvector]]
- [[Determinant]]
- [[Matrix Transposition]]
- Solve [[Augmented Matrix]]
	- Compare running time using [[Inverse of Matrix]] or QR composition.

```cpp
#include <iostream>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

#include <Eigen/Core>
#include <Eigen/Dense>

#define MATRIX_SIZE 50

int main()
{
    Eigen::Matrix<float, 2, 3> matrix_23; // a 2x3 matrix
    Eigen::Vector3d v_3d; // a 3-element vector
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero(); // a 3x3 matrix with zeros

    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic; // a dynamic matrix
    Eigen::MatrixXd matrix_x;

    matrix_23 << 1, 2, 3, 4, 5, 6;
    // 1 2 3
    // 4 5 6

    cout << matrix_23 << endl;

    for(int i = 0; i < 1; i++)
        for(int j = 0; j < 2; j++)
            cout << matrix_23(i, j) << " ";
    cout << endl;

    // ---

    v_3d << 3, 2, 1;

    Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    cout << matrix_23 << endl;
    cout << "times" << endl;
    cout << v_3d << endl;
    cout << "is" << endl;
    cout << result << endl;

    // ---

    matrix_33 = Eigen::Matrix3d::Random();
    cout << matrix_33 << endl << endl;
    cout << matrix_33.transpose() << endl;
    cout << matrix_33.sum() << endl;
    cout << matrix_33.trace() << endl;
    cout << 10 * matrix_33 << endl;
    cout << matrix_33.inverse() << endl;
    cout << matrix_33.determinant() << endl;

    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
    cout << "Eigen values = " << eigen_solver.eigenvalues() << endl;
    cout << "Eigen vectors = " << eigen_solver.eigenvectors() << endl;

    Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN;
    matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    Eigen::Matrix<double, MATRIX_SIZE, 1> v_Nd;
    v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);

    clock_t time_stt = clock();
    Eigen::Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse() * v_Nd;
    cout << "time use in normal inverse is " << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;

    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout << "time use in Qr composition is " << 1000 * (clock() - time_stt) / (double) CLOCKS_PER_SEC << "ms" << endl;

    return 0;
}
```

---

參考資料:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.