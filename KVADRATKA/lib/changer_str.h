#ifndef CHANGER_STR
#define CHANGER_STR

#define BLACK   "30" 
#define RED     "31"
#define GREEN   "32"
#define YELLOW  "33"
#define BLUE    "34"
#define MAGENTA "35"
#define CYAN    "36"
#define WHITE   "37"

#define CHANGE_STR_COLOR(STR, COLOR) "\x1b[" COLOR "m" STR "\x1b[0m"

#endif