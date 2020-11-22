#include "CramersRule.h"

//конструктор по умолчанию
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

//конструктор с параметрами
CramersRule::CramersRule(int rows, int cols, double** matrix)
{
    _matrix = nullptr;
    setMatrix(rows, cols, matrix);
}

//конструктор копирования
CramersRule::CramersRule(const CramersRule& cramersMethod) : CramersRule(cramersMethod._rows,cramersMethod._cols,cramersMethod._matrix)
{}

//операторы присваивания
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


//метод изменения матрицы
void CramersRule::setMatrix(int rows, int cols, double** matrix)
{
    if (rows <= 0)
        throw exception("Bad count of rows!");

    if (cols <= 0)
        throw exception("Bad count of cols!");

    //т.к. система уравнений будет решаться по методу Крамера
    //то столбцов в матрице должно быть на 1 больше, чем строк, т.к. добавляется еще один столбец - столбец свободных членов
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

//решение системы
double* CramersRule::compute()
{
    int rank = _rows;

    //вычисляем главный определитель системы
    double det = determinant(rank, _matrix);

    if (!det)
        throw exception("Determinant in null!");

    //вычисляем дополнительные определители
    double* dets = new double[rank];
    double* results = new double[rank];
    for (int i = 0; i < rank; i++)
    {
        double** matrix = new double* [rank];
        for (int j = 0; j < rank; j++)
        {
            //получение дополнительных матриц

            matrix[j] = new double[rank];

            for (int k = 0; k < rank; k++)
                if (k != i)
                    matrix[j][k] = _matrix[j][k];
                else
                    matrix[j][k] = _matrix[j][_cols - 1];
        }

        //получаем дополнительный определитель и решение
        dets[i] = determinant(rank, matrix);
        results[i] = dets[i] / det;

        for (int i = 0; i < rank; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    delete[] dets;

    return results;
}

//транспонирование матрицы
void CramersRule::transponse()
{
    //транспонируем только матрицу системы - без свободного члена

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

//вычисление определителя матрицы
double CramersRule::determinant(int rank,double ** matrix)
{
    //определитель матрицы, состоящей из одного элемента равен этому элементу
    if (rank == 1)
        return matrix[0][0];

    double det = 0;
    //раскладываем определитель по первой строке
    for (int i = 0; i < rank; i++)
        //определить равен сумме произведений элементов строки на их миноры и на (-1)^(i+j), в нашем случае j = 0
        det += matrix[0][i] * minor(0, i, rank, matrix) * pow(-1, i);

    return det;
}

//получение минора матрицы
double CramersRule::minor(int row, int col, int rank, double** matrix)
{
    //минор - определить матрицы, составленной при вычеркивании строки row и столбца col из матрицы matrix

    //создаем такую же по размеру матрицу
    double** newMatrix = new double* [rank - 1];

    //перебираем все строки матрицы
    for (int i = 0, j = 0; i < rank; i++)
        //если встретилась строка под номером row, то пропускаем ее
        if (i == row)
            continue;
        else
        {
            //иначе - копируем содержимое строки за исключением столбца col
            newMatrix[j] = new double[rank - 1];
            for (int k = 0, l = 0; k < rank; k++)
                if (k == col)
                    continue;
                else
                    newMatrix[j][l++] = matrix[i][k];

            j++;
        }

    //т.к. мы вычеркнули одну строку и столбец из матрицы
    //то ее ранг уменьшился
    rank--;

    //если ранг матрицы равен 1, то она состоит из одного элемента (1х1)
    if (rank == 1)
    {
        //тогда определитель равен этому элементу
        double det = newMatrix[0][0];

        //очищаем память от созданной матрицы
        for (int i = 0; i < rank; i++)
            delete[] newMatrix[i];
        delete[] newMatrix;

        return det;
    }

    //иначе считаем определитель для данной матрицы как произведение элементов 
    //первой строки на их миноры и на (-1)^i
    double det = 0;
    for (int i = 0; i < rank; i++)
        det += newMatrix[0][i] * minor(0, i, rank, newMatrix) * pow(-1, i);

    //очищаем выделенную под матрицу память
    for (int i = 0; i < rank; i++)
        delete[] newMatrix[i];
    delete[] newMatrix;

    return det;
}
