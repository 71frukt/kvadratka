//#include "kvadratka.h"

struct flags 
{
    char name[10];
    void (*function)(void);        //true если необх. продолжить программу,  false если необх. return
    bool do_standart_prog;
};


const int FLAGS_COUNT = 5;

const struct flags flags_funcs[FLAGS_COUNT] = 
{
    {"-h", PrintHelp, true},
    {"-t", UnitTest, false},
    {"-u"}
};