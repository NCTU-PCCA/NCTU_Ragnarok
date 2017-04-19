#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

template <typename T>
class Matrix {
public:
    Matrix()
        : wrong(false)
    {
    }
    Matrix(int _rows, int _cols)
        : wrong(false)
    {
        rows = _rows;
        cols = _cols;
        data = new T*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new T[cols];
    }
    Matrix(T** _data, int _rows, int _cols)
        : wrong(false)
    {
        rows = _rows;
        cols = _cols;
        data = new T*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new T[cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = _data[i][j];
    }
    Matrix(const Matrix& N)
    {
        wrong = N.wrong;
        rows = N.rows;
        cols = N.cols;
        data = new T*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new T[cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = N.data[i][j];
    }
    ~Matrix()
    {
        delete data;
    }
    T& at(int a, int b)
    {
        return data[a][b];
    }
    Matrix operator+(const Matrix& N)
    {
        cout << (*this) << endl
             << N << endl;
        Matrix tmp = Matrix(*this);
        if (rows != N.rows || cols != N.cols)
            tmp.wrong = true;
        else
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    tmp.data[i][j] += N.data[i][j];
        return tmp;
    }
    Matrix operator-(const Matrix& N)
    {
        Matrix tmp = Matrix(*this);
        if (rows != N.rows || cols != N.cols)
            tmp.wrong = true;
        else
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    tmp.data[i][j] -= N.data[i][j];
        return tmp;
    }
    Matrix operator*(const Matrix& N)
    {
        Matrix tmp = Matrix(rows, N.cols);
        if (cols != N.rows)
            tmp.wrong = true;
        else
            for (int i = 0; i < tmp.rows; i++)
                for (int j = 0; j < tmp.cols; j++) {
                    tmp.data[i][j] = 0;
                    for (int k = 0; k < cols; k++)
                        tmp.data[i][j] += data[i][k] * N.data[k][j];
                }
        return tmp;
    }
    Matrix operator*(int c)
    {
        Matrix tmp = Matrix(*this);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                tmp.data[i][j] *= c;
        return tmp;
    }
    Matrix operator=(const Matrix& N)
    {
        wrong = N.wrong;
        rows = N.rows;
        cols = N.cols;
        data = new T*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new T[cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = N.data[i][j];
        return (*this);
    }
    Matrix transpose(void)
    {
        Matrix tmp = Matrix(*this);
        //int fuck = tmp.rows; tmp.rows = tmp.cols;tmp.cols = fuck;
        swap(tmp.rows, tmp.cols);
        delete tmp.data;
        tmp.data = new T*[tmp.rows];
        for (int i = 0; i < tmp.rows; i++)
            tmp.data[i] = new T[tmp.cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                tmp.data[j][i] = data[i][j];
        return tmp;
    }
    void Identity()
    { // rows==cols
        for (int i = 0; i < rows; i++) {
            at(i, i) = 1;
        }
    }
    Matrix pow(int rhs) const
    {
        if (rows != cols)
            return Matrix();
        Matrix res(rows, rows), p(*this);
        res.Identity();
        while (rhs) {
            if (rhs & 1)
                res = res * p;
            p = p * p;
            rhs >>= 1;
        }
        return res;
    }
    // r:non-free number l:l[i] is true if i-th variable is non-free
    Matrix GuassElimination(int& r, vector<bool>& l, int flag = 0)
    {
        l = vector<bool>(cols);
        r = 0;
        Matrix res(*this);
        for (int i = 0; i < res.cols - flag; i++) {
            for (int j = r; j < res.rows; j++) {
                if (fabs(res.at(j, i)) > EPS) {
                    swap(res.data[r], res.data[j]);
                    break;
                }
            }
            if (fabs(res.at(r, i)) < EPS) {
                continue;
            }
            for (int j = 0; j < res.rows; j++) {
                if (j != r && fabs(res.at(j, i)) > EPS) {
                    double tmp = (double)res.at(j, i) / (double)res.at(r, i);
                    for (int k = 0; k < res.cols; k++) {
                        res.at(j, k) -= tmp * res.at(r, k);
                    }
                }
            }
            r++;
            l[i] = true;
        }
        return res;
    }
    vector<double> Solve(vector<double> a)
    {
        if (rows != cols)
            return vector<double>();
        vector<double> res(rows);
        Matrix t(rows, cols + 1);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                t.at(i, j) = at(i, j);
            t.at(i, rows) = a[i];
        }
        int r = 0;
        vector<bool> l;
        t = t.GuassElimination(r, l, 1);
        if (r != rows)
            return vector<double>();
        for (int i = 0; i < cols; i++) {
            if (l[i])
                for (int j = 0; j < rows; j++) {
                    if (fabs(t.at(j, i)) > EPS)
                        res[i] = t.at(j, cols) / t.at(j, i);
                }
        }
        return res;
    }
    Matrix Inverse()
    {
        if (rows != cols)
            return Matrix();
        Matrix t(rows, rows * 2);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                t.at(i, j) = at(i, j);
            t.at(i, i + rows) = 1;
        }
        int r = 0;
        vector<bool> l;
        t = t.GuassElimination(r, l, rows);
        if (r != rows)
            return Matrix();
        for (int i = 0; i < cols; i++) {
            if (l[i])
                for (int j = 0; j < rows; j++) {
                    if (fabs(t.at(j, i)) > EPS) {
                        for (int k = 0; k < cols; k++)
                            t.at(j, cols + k) /= t.at(j, i);
                    }
                }
        }
        Matrix res(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res.at(i, j) = t.at(i, j + cols);
        return res;
    }

    T** data;
    int rows, cols;
    bool wrong;
};

template <typename T>
ostream& operator<<(ostream& o, const Matrix<T>& N)
{
    if (N.wrong) {
        o << "Error: Wrong Matrix Dimension" << endl;
        return o;
    }
    for (int i = 0; i < N.rows; i++)
        for (int j = 0; j < N.cols; j++) {
            if (j == 0) {
                if (i == 0)
                    o << '[';
                else
                    o << ' ';
            }
            o << N.data[i][j];
            if (j == N.cols - 1) {
                if (i == N.rows - 1)
                    o << ']';
                else
                    o << ';' << endl;
            } else
                o << ' ';
        }
    return o;
}

template <typename T>
T det(Matrix<T> N)
{
    if (N.cols == 2)
        return N.data[0][0] * N.data[1][1] - N.data[0][1] * N.data[1][0];
    T sum = 0;
    for (int i = 0; i < N.cols; i++) {
        Matrix<T> tmp(N.cols - 1, N.cols - 1);
        for (int j = 0; j < N.cols - 1; j++)
            for (int k = 0; k < N.cols - 1; k++) {
                int r = j + 1, c;
                if (k < i)
                    c = k;
                else
                    c = k + 1;
                tmp.data[j][k] = N.data[r][c];
            }
        int Ans;
        if (i % 2)
            Ans = -1;
        else
            Ans = 1;
        sum += Ans * N.data[0][i] * det(tmp);
    }
    return sum;
}
