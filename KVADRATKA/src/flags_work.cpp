#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "flags_work.h"

bool GetCmdFlags(int arg_c, const char *arg_v[], bool flag_includes[], int flags_count)
{
    assert(arg_v);

    for (int i = 1; i < arg_c; i++)
    {
        bool curr_valid = false;

        for (int j = 0; j < flags_count; j++)
        {
            if (strcmp(arg_v[i], flags_funcs[j].name) == 0) {
                flag_includes[j] = true;
                curr_valid = true;
            }
        }

        if (!curr_valid)
            return false;
    }

    return true;
}

void HandleFlags(bool flag_includes[], int flags_count, bool *todo_stand_prog)
{
    for (int i = 0; i < flags_count; i++) {
        if (flag_includes[i]) {
            flags_funcs[i].function();

            if(flags_funcs[i].do_standart_prog == false)
                *todo_stand_prog = false;
        }
    } 
}