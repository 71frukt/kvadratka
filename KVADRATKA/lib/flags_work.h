#ifndef FLAGS_WORK_H
#define FLAGS_WORK_H

#include <math.h>
#include "unitest.h"
#include "help.h"
#include "draw_shrek.h"

const int FLAG_NAME_LEN = 10;       // Максимальня длина имени флага

struct flag                         // Структура, объявляющая флаг
{
    char name[FLAG_NAME_LEN];       // Имя флага
    void (*function)(void);         // Указатель на функцию, которую выполняет данный флаг 
    bool do_standart_prog;          // true если необх. продолжить программу,  false если необх. завершить после выполнения функций флагов
};


const int FLAGS_COUNT = 5;                          // Количество флагов

const struct flag flags_funcs[FLAGS_COUNT] =        // Массив структур, содержащий флаги
{
    {"--shrek", DrawShrek,  true},
    {"-h",      PrintHelp,  true},
    {"-t",      UnitTest,   false}
};

bool GetCmdFlags(int arg_c, char *arg_v[], bool flag_includes[], int flags_count);          // Получает флаги из аргументов командной строки и записывает,
                                                                                            // втретился флаг или нет в массив flag_includes[]
void HandleFlags(bool flag_includes[], int flags_count, bool *todo_stand_prog);             // Запускает функции полученных флагов и записывает, выполнять стандартную программу
                                                                                            // или нет в bool todo_stand_prog
#endif

