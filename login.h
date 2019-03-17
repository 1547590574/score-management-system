#ifndef LOGIN_H
#define LOGIN_H
#pragma execution_character_set("utf-8")
#include <QDialog>

namespace Ui {
class Login;
}


class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();
signals:
    void showmain();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
