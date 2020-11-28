#include "CramersRule.h"

//����������� �� ���������
CramersRule::CramersRule()
{
    int rows = 1;
    int cols = 2;
    double* matrix = new double[2];
    matrix[0] = matrix[1] = 0;

    _matrix = nullptr;
    setMatrix(rows, cols, &matrix);

    delete[] matrix;
}

//����������� � �����������
CramersRule::CramersRule(int rows, int cols, double** matrix)
{
    _matrix = nullptr;
    setMatrix(rows, cols, matrix);
}

//����������� �����������
CramersRule::CramersRule(const CramersRule& cramersMethod) : CramersRule(cramersMethod._rows,cramersMethod._cols,cramersMethod._matrix)
{}

//��������� ������������
CramersRule& CramersRule::operator=(const CramersRule& cramersMethod)
{
    setMatrix(cramersMethod._rows, cramersMethod._cols, cramersMethod._matrix);

    return *this;
}

CramersRule& CramersRule::operator=(const Matrix& matrix)
{
    Matrix& obj = const_cast<Matrix&>(matrix);

    setMatrix(obj.getRows(), obj.getCols(), obj.getMatrix());

    return *this;
}


//����� ��������� �������
void CramersRule::setMatrix(int rows, int cols, double** matrix)
{
    if (rows <= 0)
        throw exception("Bad count of rows!");

    if (cols <= 0)
        throw exception("Bad count of cols!");

    //�.�. ������� ��������� ����� �������� �� ������ �������
    //�� �������� � ������� ������ ���� �� 1 ������, ��� �����, �.�. ����������� ��� ���� ������� - ������� ��������� ������
    if (cols - rows != 1)
        throw exception("Bad size of system matrix!");

    if (!matrix)
        throw exception("Nullptr!");

    for (int i = 0; i < rows; i++)
        if (!matrix[i])
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

//������� �������
double* CramersRule::compute()
{
    int rank = _rows;

    //��������� ������� ������������ �������
    double det = determinant(rank, _matrix);

    if (!det)
        throw exception("Determinant in null!");

    //��������� �������������� ������������
    double* dets = new double[rank];
    double* results = new double[rank];
    for (int i = 0; i < rank; i++)
    {
        double** matrix = new double* [rank];
        for (int j = 0; j < rank; j++)
        {
            //��������� �������������� ������

            matrix[j] = new double[rank];

            for (int k = 0; k < rank; k++)
                if (k != i)
                    matrix[j][k] = _matrix[j][k];
                else
                    matrix[j][k] = _matrix[j][_cols - 1];
        }

        //�������� �������������� ������������ � �������
        dets[i] = determinant(rank, matrix);
        results[i] = dets[i] / det;

        for (int i = 0; i < rank; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    delete[] dets;

    return results;
}

//���������������� �������
void CramersRule::transponse()
{
    //������������� ������ ������� ������� - ��� ���������� �����

    double** newMatrix = new double* [_rows];
    for (int i = 0; i < _rows; i++)
    {
        newMatrix[i] = new double[_cols];

        for (int j = 0; j < _cols-1; j++)
            newMatrix[i][j] = _matrix[j][i];

        newMatrix[i][_cols - 1] = _matrix[i][_cols - 1];
    }

    setMatrix(_rows, _cols, newMatrix);
}

//���������� ������������ �������
double CramersRule::determinant(int rank,double ** matrix)
{
    //������������ �������, ��������� �� ������ �������� ����� ����� ��������
    if (rank == 1)
        return matrix[0][0];

    double det = 0;
    //������������ ������������ �� ������ ������
    for (int i = 0; i < rank; i++)
        //���������� ����� ����� ������������ ��������� ������ �� �� ������ � �� (-1)^(i+j), � ����� ������ j = 0
        det += matrix[0][i] * minor(0, i, rank, matrix) * pow(-1, i);

    return det;
}

//��������� ������ �������
double CramersRule::minor(int row, int col, int rank, double** matrix)
{
    //����� - ���������� �������, ������������ ��� ������������ ������ row � ������� col �� ������� matrix

    //������� ����� �� �� ������� �������
    double** newMatrix = new double* [rank - 1];

    //���������� ��� ������ �������
    for (int i = 0, j = 0; i < rank; i++)
        //���� ����������� ������ ��� ������� row, �� ���������� ��
        if (i == row)
            continue;
        else
        {
            //����� - �������� ���������� ������ �� ����������� ������� col
            newMatrix[j] = new double[rank - 1];
            for (int k = 0, l = 0; k < rank; k++)
                if (k == col)
                    continue;
                else
                    newMatrix[j][l++] = matrix[i][k];

            j++;
        }

    //�.�. �� ���������� ���� ������ � ������� �� �������
    //�� �� ���� ����������
    rank--;

    //���� ���� ������� ����� 1, �� ��� ������� �� ������ �������� (1�1)
    if (rank == 1)
    {
        //����� ������������ ����� ����� ��������
        double det = newMatrix[0][0];

        //������� ������ �� ��������� �������
        for (int i = 0; i < rank; i++)
            delete[] newMatrix[i];
        delete[] newMatrix;

        return det;
    }

    //����� ������� ������������ ��� ������ ������� ��� ������������ ��������� 
    //������ ������ �� �� ������ � �� (-1)^i
    double det = 0;
    for (int i = 0; i < rank; i++)
        det += newMatrix[0][i] * minor(0, i, rank, newMatrix) * pow(-1, i);

    //������� ���������� ��� ������� ������
    for (int i = 0; i < rank; i++)
        delete[] newMatrix[i];
    delete[] newMatrix;

    return det;
}
