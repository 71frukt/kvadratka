#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

enum menu_code                                                  // Перечисление кодов завершения функции ExitMenu
{
    MENU_ERROR = -1,
    MENU_EXIT = 0,
    MENU_CONTINUE = 1
};
menu_code ExitMenu();                                           // Запускает пользовательское меню

bool GetInput(float *a, float *b, float *c);                    // Начинает ввод коеффициентов квадратного уравнения и возвращает значение, полученное из GetValue
bool GetValue(float *a, float *b, float *c);                    // Получает значения из ввода с клавиатуры и возвращает true, если ввод корректен, и false в противном случае
                                                                // и возвращает true, если успешно и false в противном случае
bool CleanBuffer();                                             // Очищает буффер после функции scanf и возвращает false, если после ввода встретились сторонние символы

#endif