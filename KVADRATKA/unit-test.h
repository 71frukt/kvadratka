struct test_values
{
    float a, b, c;
    
    float x1_exp, x2_exp;
    count_of_roots n_roots_exp;
};

const struct test_values tests[] =
{ //  a,    b,   c,    x1_exp,  x2_exp, n_roots_exp 
    { 0.0,  0.0, 0.0,  NAN,     NAN,    INFIN_ROOTS },    // a == b == c == 0
    { 0.0,  0.0, 1.0,  NAN,     NAN,    NO_ROOTS },       // a == b == 0, c != 0
    { 0.0,  1.0, 1.0, -1.0,     NAN,    ONE_ROOT },       // a == 0, b != 0, c != 0
  
    { 1.0,  1.0, 1.0,  NAN,     NAN,    NO_ROOTS },       // discr < 0
    { 1.0, -4.0, 4.0,  2.0,     NAN,    ONE_ROOT },       // discr == 0
    { 1.0, -1.0,-2.0, -1.0,    2.0,     TWO_ROOTS }       // discr > 0
};