#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "my_stack.h"
#include <QStack>

QString ss;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,600);
    this->setFixedSize(600,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int get_prioritet(QChar ch){
    if (ch == '/' || ch == '*'){
        return 3;
    }else if (ch == '+' || ch == '-'){
        return 2;
    }else if(ch == '('){
        return 1;
    }
}

void MainWindow::on_transform_clicked()
{
    QString s = ui->infix_input->text();
    QStack<QChar> st;
//    my_stack *st = new my_stack(this);

    int i =0;
    while (i<s.length()) {

       if(s[i]>='a' && s[i]<='s'){
        ss+=s[i];}
       if(s[i]<'a'||s[i]>'z'){
            if(st.empty() ){
                st.push(s[i]);
            }else{
                if(s[i]=='('){
                //3
                st.push(s[i]);
                }else if(s[i] == ')'){
                    while ((!st.empty()) && st.top()!='(') {
                            ss+=st.pop();
                    }
                     st.pop();
                }else {
                    int pr = get_prioritet(s[i]);
                    if( (get_prioritet(st.top()) < pr)){
                                    st.push(s[i]);
                    } else{
                        while ((!st.empty())&&(get_prioritet(st.top() )>= pr)) {
                            ss+=st.pop();
                        }
                          st.push(s[i]);
                        }
                    }

                    }
       }
       i++;
    }
     QStack<double> res;
    while(!st.empty()){
    ss+=st.pop();
      }
  // ui->post_out->clear();
    ui->post_out->setText(ss);


    double a1 = ui->a->text().toDouble();
    double b1 = ui->b->text().toDouble();
    double c1 = ui->c->text().toDouble();
    double d1 = ui->d->text().toDouble();
    double e1 = ui->e->text().toDouble();

    i = 0;
    while (i<ss.length()) {

        if(ss[i]>='a' && ss[i]<='z'){
            if(ss[i] == 'a'){
                res.push(a1);
            }else if(ss[i] == 'b'){
                res.push(b1);
            }else if(ss[i] == 'c'){
                res.push(c1);
            }else if(ss[i] == 'd'){
                res.push(d1);
            }else{
                res.push(e1);
            }
        }else{
            if(ss[i] == '+'){
                double answer=0;
                answer = res.pop();
                answer += res.pop();
                res.push(answer);
            }else if(ss[i] == '-'){
                double answer=0;
                answer = res.pop()*(-1);
                answer += res.pop();
                res.push(answer);
            }else if(ss[i] == '/'){
                double answer = 1, answer2 = 1;
                answer2 = res.pop();
                answer =res.pop()/answer2;
                res.push(answer);
            }else if(ss[i] == '*'){
                double answer;
                answer = res.pop();
                answer *= res.pop();
                res.push(answer);
        }


    }
        i++;
}
ui->result->clear();
ss = "";
ui->result->setText(QString::number(res.pop()));
}
