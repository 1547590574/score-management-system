#include "inputdialog.h"
#include "ui_inputdialog.h"

inputdialog::inputdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputdialog)
{
    ui->setupUi(this);
}

inputdialog::~inputdialog()
{
    delete ui;
}
