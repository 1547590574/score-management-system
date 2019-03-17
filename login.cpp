#include "login.h"
#include "ui_login.h"
#include "QLineEdit"
#include "QRegExpValidator"
#include "QTextCodec"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QPixmap pixmap("F:/Docments/build-GradeManager-Desktop_Qt_5_12_1_MSVC2015_64bit_qt_qt5-Debug/background.jpg");

    QPalette palette=this->palette();

    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);

    QIcon ico("F:/Docments/build-GradeManager-Desktop_Qt_5_12_1_MSVC2015_64bit_qt_qt5-Debug/tips.png");

    this->setWindowIcon(ico);
    QLineEdit *qle1=ui->lineEdit;
    QLineEdit *qle2=ui->lineEdit_2;
    QRegExp regx("[1-9][0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, this );
    qle1->setMaxLength(12);
    qle1->setValidator(validator);
    qle2->setMaxLength(12);
    qle2->setValidator(validator);
    qle2->setEchoMode(QLineEdit::Password);
    ui->radioButton->setChecked(true);
    ui->pushButton->setFocus();
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
        this->hide();
        emit showmain();

}
