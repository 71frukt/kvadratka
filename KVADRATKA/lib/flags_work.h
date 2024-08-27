#ifndef FLAGS_WORK_H
#define FLAGS_WORK_H

#include <math.h>
#include "unitest.h"
#include "help.h"
#include "draw_shrek.h"

/** 
    \defgroup flags_work_h ������ � ������� 
    @{   
*/

const int FLAG_NAME_LEN = 10;       // ����������� ����� ����� �����

struct flag                         // ���������, ����������� ����
{
    char name[FLAG_NAME_LEN];       // ��� �����
    void (*function)(void);         // ��������� �� �������, ������� ��������� ������ ���� 
    bool do_standart_prog;          // true ���� �����. ���������� ���������,  false ���� �����. ��������� ����� ���������� ������� ������
};


const int FLAGS_COUNT = 5;                          // ���������� ������

const struct flag flags_funcs[FLAGS_COUNT] =        // ������ ��������, ���������� �����
{
    {"--shrek", DrawShrek,  true},
    {"-h",      PrintHelp,  true},
    {"-t",      UnitTest,   false}
};
/**
 * @param arg_c ���������� ����������� ���������� ��������� ������
 * @param arg_v ������ ����������
 */
bool GetCmdFlags(int arg_c, const char *arg_v[], bool flag_includes[], int flags_count);          // �������� ����� �� ���������� ��������� ������ � ����������,
                                                                                            // ��������� ���� ��� ��� � ������ flag_includes[]
void HandleFlags(bool flag_includes[], int flags_count, bool *todo_stand_prog);             // ��������� ������� ���������� ������ � ����������, ��������� ����������� ���������
                                                                                            // ��� ��� � bool todo_stand_prog

/** 
    @}
*/                                                                                            
#endif

