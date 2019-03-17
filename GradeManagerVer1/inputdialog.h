#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
class inputdialog;
}

class inputdialog : public QDialog
{
    Q_OBJECT

public:
    explicit inputdialog(QWidget *parent = nullptr);
    ~inputdialog();

private:
    Ui::inputdialog *ui;
};

#endif // INPUTDIALOG_H
