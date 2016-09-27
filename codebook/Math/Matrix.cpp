template <typename T>
class Matrix {
public:
	Matrix():wrong(false){}
	Matrix( int _rows, int _cols) :wrong(false){
		rows = _rows;
		cols = _cols;
		data = new T*[rows]; for (int i = 0; i < rows; i++)data[i] = new T[cols];
	}
	Matrix(T** _data, int _rows, int _cols):wrong(false){
		rows = _rows;
		cols = _cols;
		data = new T*[rows];for (int i = 0; i < rows; i++)data[i] = new T[cols];
		for (int i = 0; i < rows; i++)for (int j = 0; j < cols; j++)data[i][j] = _data[i][j];
	}
	Matrix(const Matrix& N){
		wrong = N.wrong;
		rows = N.rows;
		cols = N.cols;
		data = new T*[rows]; for (int i = 0; i < rows; i++)data[i] = new T[cols];
		for (int i = 0; i < rows; i++)for (int j = 0; j < cols; j++)data[i][j] = N.data[i][j];
	}
	~Matrix(){
		delete data;
	}
	Matrix operator+(const Matrix& N){
		cout << (*this) << endl << N << endl;
		Matrix tmp = Matrix(*this);
		if (rows != N.rows || cols != N.cols)tmp.wrong = true;
		else for (int i = 0; i < rows; i++)for (int j = 0; j < cols; j++)tmp.data[i][j] += N.data[i][j];
		return tmp;
	}
	Matrix operator-(const Matrix& N){
		Matrix tmp = Matrix(*this);
		if (rows != N.rows || cols != N.cols)tmp.wrong = true;
		else for (int i = 0; i < rows; i++)for (int j = 0; j < cols; j++)tmp.data[i][j] -= N.data[i][j];
		return tmp;
	}
	Matrix operator*(const Matrix& N){
		Matrix tmp = Matrix(rows,N.cols);
		if (cols != N.rows)tmp.wrong = true;
		else for (int i = 0; i < tmp.rows; i++)for (int j = 0; j < tmp.cols; j++){
			tmp.data[i][j] = 0;
			for (int k = 0; k < cols; k++)tmp.data[i][j] += data[i][k] * N.data[k][j];
		}
		return tmp;
	}
	Matrix operator*(int c){
		Matrix tmp = Matrix(*this);
		for (int i = 0; i < rows; i++)for (int j = 0; j < cols; j++)tmp.data[i][j] *= c;
		return tmp;
	}
	Matrix operator=(const Matrix& N){
		wrong = N.wrong;
		rows = N.rows;
		cols = N.cols;
		data = new T*[rows]; for (int i = 0; i < rows; i++)data[i] = new T[cols];
		for (int i = 0; i < rows; i++)for (int j = 0; j < cols; j++)data[i][j] = N.data[i][j];
		return (*this);
	}
	Matrix transpose(void) {
		Matrix tmp = Matrix(*this);
		//int fuck = tmp.rows; tmp.rows = tmp.cols;tmp.cols = fuck;
		swap(tmp.rows, tmp.cols);
		delete tmp.data;tmp.data = new T*[tmp.rows]; for (int i = 0; i < tmp.rows; i++)tmp.data[i] = new T[tmp.cols];
		for (int i = 0; i < rows; i++)for (int j = 0; j < cols; j++)tmp.data[j][i] = data[i][j];
		return tmp;
	}

	T **data;
	int rows, cols;
	bool wrong;
};

template <typename T>
ostream& operator<<(ostream& o,const Matrix<T>& N){
	if (N.wrong){ o << "Error: Wrong Matrix Dimension" << endl; return o; }
	for (int i = 0; i < N.rows; i++)for (int j = 0; j < N.cols; j++){
		if (j == 0){
			if (i == 0)o << '[';
			else o << ' ';
		}
		o << N.data[i][j];
		if (j == N.cols - 1){
			if (i == N.rows - 1)o << ']';
			else o << ';' << endl;
		}
		else o << ' ';
	}
	return o;
}

template <typename T>
T det(Matrix<T> N) {
	if (N.cols == 2)return N.data[0][0]*N.data[1][1] - N.data[0][1]*N.data[1][0];
	T sum = 0;
	for (int i = 0; i < N.cols; i++){
		Matrix<T> tmp(N.cols-1,N.cols-1);
		for (int j = 0; j < N.cols - 1; j++)for (int k = 0; k < N.cols - 1; k++){
			int r = j+1, c; if (k < i)c = k; else c = k + 1;
			tmp.data[j][k] = N.data[r][c];
		}
		int Ans; if (i % 2)Ans = -1; else Ans = 1;
		sum += Ans*N.data[0][i]*det(tmp);
	}
	return sum;
}
