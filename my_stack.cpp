#include "my_stack.h"
#include "mainwindow.h"

my_stack::my_stack(MainWindow *Parent)
{
    parent = Parent;
}

int my_stack::push(QChar s){
    _elem = s;
    return 0;
}

QChar my_stack::top(){
    return _elem;
}

QChar my_stack::pop(){
    return _elem;
}
