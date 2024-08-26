#ifndef SOLVER_H
#define SOLVER_H

enum count_of_roots         // ������������ ���������� ���������� ������
{
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INFIN_ROOTS,
    ERROR_ROOTS             // ������ ��������� ���������� ������
};

const float LOWCONST = 0.001f;          // ������ �������� ��������� �����

count_of_roots GeneralSolveEquation(const float a, const  float b, const float c, float *root_1, float *root_2);  // H����� �������� ��������� � ���������� ���������� ������
count_of_roots SolveLinearEquation(const float b, const float c, float *root_1);                                  // ������ ��������� ��� a == 0 (�������� ��� ��� ���� �����. == 0)
count_of_roots SolveQuadraticEquation(const float a, const float b, const float c, float *root1, float *root2);   // ������ ���������� ��������� � ���������� ���������� ������

void PrintSolve(count_of_roots n_roots, float root_1, float root_2);                      // ������� ������� ���������
    
const char *GetCountOfRoots(count_of_roots n_roots);                                      // ���������� ��������� �� ������, � ������� �������� ���������� ������

bool IsEqualF(float num_1, float num_2);                                                  // ���������� true, ���� ����� ����� � ��������� �� LOWCONST � false, ���� �� �����
bool IsZeroF(float num);                                                                  // ���������� true, ���� ����� ����� ���� � ��������� �� LOWCONST � false, ���� �� �����

#endif
