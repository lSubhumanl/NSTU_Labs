#include "Matrix.h"


//����������� �������
double** Matrix::copyMatrix(int rows, int cols, double** matrix)
{
    //������� ����� �� �� ������� �������
    double** copy = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        copy[i] = new double[cols];

        //�������� �� ����������
        for (int j = 0; j < cols; j++)
            copy[i][j] = matrix[i][j];
    }

    //���������� �����
    return copy;
}



//����������� �� ���������
Matrix::Matrix()
{
    int rows = 1;
    int cols = 1;
    double** matrix = new double*[rows];
    matrix[0] = new double;
    matrix[0][0] = 0;

    _matrix = nullptr;
    setMatrix(1, 1, matrix);

    delete[] matrix[0];
    delete[] matrix;
}

//����������� � �����������
Matrix::Matrix(int rows, int cols, double** matrix)
{
    _matrix = nullptr;
    setMatrix(rows, cols, matrix);
}

//����������� �����������
Matrix::Matrix(const Matrix& matrix) : Matrix(matrix._rows, matrix._cols, matrix._matrix)
{}

//����������
Matrix::~Matrix()
{
    for (int i = 0; i < _rows; i++)
        delete[] _matrix[i];
    delete[] _matrix;
}



//��������� ���������� �����
int Matrix::getRows()
{
    return _rows;
}

//��������� ���������� ��������
int Matrix::getCols()
{
    return _cols;
}

//��������� ����� �������
double** Matrix::getMatrix()
{
    return copyMatrix(_rows,_cols,_matrix);
}

//��������� �������� �� �������
double& Matrix::getValue(int rowIndex, int colIndex)
{
    if ((rowIndex < 0) || (rowIndex >= _rows))
        throw exception("Bad row index!");

    if ((colIndex < 0) || (colIndex >= _cols))
        throw exception("Bad col index!");

    return _matrix[rowIndex][colIndex];
}



//��������� �������
void Matrix::setMatrix(int rows, int cols, double** matrix)
{
    if (rows <= 0)
        throw exception("Bad count of rows!");

    if (cols <= 0)
        throw exception("Bad count of cols!");

    if (!matrix)
        throw exception("Nullptr!");

    for(int i =0;i<rows;i++)
        if(!matrix[i])
            throw exception("Nullptr!");

    if (_matrix)
    {
        for (int i = 0; i < _rows; i++)
            delete[] _matrix[i];
        delete[] _matrix;
    }

    _rows = rows;
    _cols = cols;
    _matrix = copyMatrix(rows, cols, matrix);
}



//��������� ���������� ������������� �������
char* Matrix::toString()
{
    //����� �������������� ������
    int str_len = 1024;
    //����� ������, ���������� �����
    int number_len = 15;

    //������� �������������� ������
    char* str = new char[str_len];
    //� ������, ������� ����� �� ��� ���������
    int index = 0;

    //����������� �� ���� ������ �������
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            //������ ����� ����������� � ������ � ������� �������� _itoa_s
            char* number = new char[number_len];
            _itoa_s(_matrix[i][j], number, number_len, 10);

            //��������� ��������� ������������� ����� � �������������� ������
            for (int k = 0; k < strlen(number); k++)
                str[index++] = number[k];
            //����� ������� ����� ����� ���������
            str[index++] = '\t';

            delete[] number;
        }

        //� ����� ������ ������ ������� ����� ������ �������� ������
        str[index++] = '\n';
    }

    str[index] = '\0';

    return str;
}

//���������������� �������
void Matrix::transponse()
{
    int newRows = _cols;
    int newCols = _rows;
    double** newMatrix = new double* [newRows];
    for (int i = 0; i < newRows; i++)
    {
        newMatrix[i] = new double[newCols];

        for (int j = 0; j < newCols; j++)
            newMatrix[i][j] = _matrix[j][i];
    }

    setMatrix(newRows, newCols, newMatrix);
}



//�������� ������
Matrix Matrix::operator+(const Matrix& matrix)
{
    if ((_rows != matrix._rows) || (_cols != matrix._cols))
        throw exception("Bad size of matrix!");

    double** resultMatrix = copyMatrix(_rows, _cols, _matrix);
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            resultMatrix[i][j] += matrix._matrix[i][j];

    return Matrix(_rows,_cols,resultMatrix);
}

//��������� ������
Matrix Matrix::operator-(const Matrix& matrix)
{
    if ((_rows != matrix._rows) || (_cols != matrix._cols))
        throw exception("Bad size of matrix!");

    double** resultMatrix = copyMatrix(_rows, _cols, _matrix);
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            resultMatrix[i][j] -= matrix._matrix[i][j];

    return Matrix(_rows, _cols, resultMatrix);
}

//�������� ��������������
double * Matrix::operator[](int rowIndex)
{
    if ((rowIndex < 0) || (rowIndex >= _rows))
        throw exception("Bad row index!");

    double* copy = new double[_cols];
    for (int i = 0; i < _cols; i++)
        copy[i] = _matrix[rowIndex][i];

    return copy;
}

//�������� ������������
Matrix& Matrix::operator=(const Matrix& matrix)
{
    setMatrix(matrix._rows, matrix._cols, matrix._matrix);

    return *this;
}



//������ � �������� ����
void Matrix::write(fstream& file)
{
    if (!file.is_open())
        throw exception("File is closed!");

    //���������� ���������� �����, �������� � �������� �������
    file.write((char*)&_rows, sizeof(int));
    file.write((char*)&_cols, sizeof(int));
    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            file.write((char*)&_matrix[i][j], sizeof(double));
}

//������ �� ��������� �����
void Matrix::read(fstream& file)
{
    if (!file.is_open())
        throw exception("File is closed!");

    int rows;
    file.read((char*)&rows, sizeof(int));

    if (rows <= 0)
        throw exception("Bad count of rows!");

    int cols;
    file.read((char*)&cols, sizeof(int));

    if (cols <= 0)
        throw exception("Bad count of cols!");

    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new double[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            file.read((char*)&matrix[i][j], sizeof(double));

    setMatrix(rows, cols, matrix);
}

//����� � �������
void Matrix::print()
{
    cout << "CLASS: Matrix" << endl;

    cout << (*this) << endl;
}

//�������� ��������� "�����"
bool Matrix::operator==(Matrix& matrix)
{
    if (_rows != matrix._rows)
        return false;

    if (_cols != matrix._cols)
        return false;

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            if (_matrix[i][j] != matrix._matrix[i][j])
                return false;

    return true;
}

//�������� ������ � �����
ostream& operator<<(ostream& stream, const Matrix& matrix)
{
    stream << matrix._rows << endl;
    stream << matrix._cols << endl;
    
    for (int i = 0; i < matrix._rows; i++)
    {
        for (int j = 0; j < matrix._cols; j++)
            stream << matrix._matrix[i][j] << ' ';
        stream << endl;
    }

    return stream;
}

//������ �� ������ �����
istream& operator>>(istream& stream, Matrix& matrix)
{
    int rows;
    stream >> rows;

    if (rows <= 0)
        throw exception("Bad count of rows!");

    int cols;
    stream >> cols;

    if (cols <= 0)
        throw exception("Bad count of cols!");

    double** resultMatrix = new double* [rows];
    for (int i = 0; i < rows; i++)
        resultMatrix[i] = new double[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            stream >> resultMatrix[i][j];

    matrix.setMatrix(rows, cols, resultMatrix);

    return stream;
}
