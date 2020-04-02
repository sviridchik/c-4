#ifndef MY_STACK_H
#define MY_STACK_H
#include <mainwindow.h>

class my_stack
{
public:
    my_stack(MainWindow *parent = nullptr);
    int push(QChar s);
    QChar pop();
    QChar top();
    my_stack *next = nullptr;


private:
    QChar _elem;
    MainWindow *parent;
};

#endif // MY_STACK_H
