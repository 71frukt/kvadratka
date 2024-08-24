#ifndef FLAGS_WORK_H
#define FLAGS_WORK_H

#include <math.h>
#include "unitest.h"
#include "help.h"
#include "draw_shreck.h"

struct flags 
{
    char name[10];
    void (*function)(void);        //true если необх. продолжить программу,  false если необх. return
    bool do_standart_prog;
};


const int FLAGS_COUNT = 5;

const struct flags flags_funcs[FLAGS_COUNT] = 
{
    {"--shreck", DrawShreck, true},
    {"-h", PrintHelp, true},
    {"-t", UnitTest, false}
};

bool GetCmdFlags(int arg_c, char *arg_v[], bool flag_includes[], int flags_count);
void HandleFlags(bool flag_includes[], int flags_count, bool *todo_stand_prog);

#endif

