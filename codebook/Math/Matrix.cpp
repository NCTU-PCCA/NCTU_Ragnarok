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
        data.resize(_rows);
        for (int i = 0; i < _rows; i++)
            data[i].resize(_cols);
    }
    Matrix(T** _data, int _rows, int _cols)
        : wrong(false)
    {
        rows = _rows;
        cols = _cols;
        data.resize(_rows);
        for (int i = 0; i < _rows; i++)
            data[i].resize(_cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = _data[i][j];
    }
    Matrix(const Matrix& N)
    {
        wrong = N.wrong;
        rows = N.rows;
        cols = N.cols;
        data.resize(rows);
        for (int i = 0; i < rows; i++)
            data[i].resize(cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = N.data[i][j];
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
    T det()
    {
        int ans = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = i + 1; j < rows; j++) {
                int a = i, b = j;
                while (at(b, i)) {
                    int q = at(a, i) / at(b, i);
                    for (int k = 0; k < rows; k++) {
                        at(a, k) = at(a, k) - at(b, k) * q;
                    }
                    swap(a, b);
                }
                if (a != i) {
                    swap(data[i], data[j]);
                    ans = -ans;
                }
            }
            if (fabs(at(i, i)) < EPS)
                return 0;
            else
                ans *= at(i, i);
        }
        return ans;
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

    vector<vector<T> > data;
    int rows, cols;
    bool wrong;
};
