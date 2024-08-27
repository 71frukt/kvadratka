#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

enum menu_code                                                  // ������������ ����� ���������� ������� ExitMenu
{
    MENU_ERROR = -1,
    MENU_EXIT = 0,
    MENU_CONTINUE = 1
};

menu_code ExitMenu();                                           // ��������� ���������������� ����

bool GetInput(float *a, float *b, float *c);                    // �������� ���� ������������� ����������� ��������� � ���������� ��������, ���������� �� GetValue
bool GetValue(float *a, float *b, float *c);                    // �������� �������� �� ����� � ���������� � ���������� true, ���� ���� ���������, � false � ��������� ������
                                                                // � ���������� true, ���� ������� � false � ��������� ������
bool CleanBuffer();                                             // ������� ������ ����� ������� scanf � ���������� false, ���� ����� ����� ����������� ��������� �������

#endif