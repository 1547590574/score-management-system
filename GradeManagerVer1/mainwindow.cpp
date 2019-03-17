#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap("F:/Docments/build-GradeManager-Desktop_Qt_5_12_1_MSVC2015_64bit_qt_qt5-Debug/background.jpg");

    QPalette palette=this->palette();

    palette.setBrush(QPalette::Background, QBrush(pixmap));

    this->setPalette(palette);

    QIcon ico("F:/Docments/build-GradeManager-Desktop_Qt_5_12_1_MSVC2015_64bit_qt_qt5-Debug/tips.png");

    this->setWindowIcon(ico);
    QRegExp regx("[1-9][0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit2 );
    ui->lineEdit2->setValidator(validator);
    ui->lineEdit1->setMaxLength(12);
    ui->lineEdit2->setMaxLength(12);
    QRegExp rx("([1-9]?\\d|100)$");
    ui->lineEdit3->setValidator(new QRegExpValidator(rx,this));
    ui->lineEdit4->setValidator(new QRegExpValidator(rx,this));
    ui->lineEdit5->setValidator(new QRegExpValidator(rx,this));
    ui->textEdit->setReadOnly(true);
    ui->pushButton_8->setFocus();


}

int MainWindow::count=0;
QString MainWindow::Stuids[100];
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receivelogin()
{
    this->show();
}
void MainWindow::on_pushButton_8_clicked()
{

    QString str1=ui->lineEdit1->text();
    QString str2=ui->lineEdit2->text();
    QString str3=ui->lineEdit3->text();
    QString str4=ui->lineEdit4->text();
    QString str5=ui->lineEdit5->text();
    QString str=str1+"\t"+str2+"\t"+str3+"\t"+str4+"\t"+str5;
    Stuids[count++]=str2;
    for (int i=0;i<count-1;i++) {
        if(Stuids[i]==str2&&Stuids[i]!=""){
             QMessageBox::about(nullptr,"提示","录入学号重复");
             return;
        }
    }
    QFile file("input.dat");
    if (file.open(QFile::Append | QFile :: Text)&&str1!="")
        {
            QTextStream out(&file);
            out << str<< endl;
        }
    file.close();
    if(str1!=nullptr&&str2!=nullptr&&str3!=nullptr&&str4!=nullptr&&str5!=nullptr)
        QMessageBox::about(nullptr,"提示","成绩录入成功");

    ui->lineEdit1->setText("");
    ui->lineEdit2->setText("");
    ui->lineEdit3->setText("");
    ui->lineEdit4->setText("");
    ui->lineEdit5->setText("");

}

void MainWindow::on_pushButton_7_clicked()
{
    this->close();
}


void MainWindow::on_pushButton_clicked()
{

    ui->textEdit->setText("");
    QString ss="姓名\t学号\t\t语文\t数学\t英语\n";
    ui->textEdit->setText(ss);
    QTextCodec *codec=QTextCodec::codecForName("GBK");
    QFile file("input.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::about(nullptr,"提示","无法打开文件!");
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str=codec->toUnicode(line);
        ui->textEdit->append(str);
    }
    file.close();

}

void MainWindow::on_pushButton_3_clicked()
{
    linkList l;
    ui->textEdit->setText("");
    QTextCodec *codec=QTextCodec::codecForName("GBK");
    QFile file("input.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
       QMessageBox::about(nullptr,"提示","无法打开文件!");
    }


    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str=codec->toUnicode(line);
        QStringList msg=str.split("\t");
        int avg=(msg.at(2).toInt()+msg.at(3).toInt()+msg.at(4).toInt())/3;
        l.add(msg.at(0),msg.at(1),msg.at(2).toInt(),msg.at(3).toInt(),msg.at(4).toInt(),avg);
    }
     QString str1=l.printlink();

    l.sortOfGrade1();
    QString str=l.printlink();
    QFile file1("input1.dat");
    if (file1.open(QFile::Append | QFile::Truncate|QFile::Text))
        {
            QTextStream out(&file1);
            out <<str<< endl;
        }
    ui->textEdit->setText("");
    QString ss="姓名\t学号\t\t语文\t数学\t英语\n";
     ui->textEdit->setText(ss);
    QTextCodec *codec2=QTextCodec::codecForName("GBK");
    QFile file2("input1.dat");
    if(!file2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::about(nullptr,"提示","无法打开文件!");
    }
    while(!file2.atEnd())
    {
        QByteArray line = file2.readLine();
        QString str=codec2->toUnicode(line);
        ui->textEdit->append(str);
    }
     file.close();
       QMessageBox::about(nullptr,"提示","打印完成,生成文件input1.dat");
}

void MainWindow::on_pushButton_4_clicked()
{
    linkList l;
    ui->textEdit->setText("");
    QTextCodec *codec=QTextCodec::codecForName("GBK");
    QFile file("input.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::about(nullptr,"提示","无法打开文件!");
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str=codec->toUnicode(line);
        QStringList msg=str.split("\t");
        int avg=(msg.at(2).toInt()+msg.at(3).toInt()+msg.at(4).toInt())/3;
        l.add(msg.at(0),msg.at(1),msg.at(2).toInt(),msg.at(3).toInt(),msg.at(4).toInt(),avg);


    }
     QString str1=l.printlink();
     l.sortOfGrade2();
     QString str=l.printlink();
    QFile file1("input2.dat");
    if (file1.open(QFile::Append | QFile::Truncate|QFile::Text))
        {
            QTextStream out(&file1);
            out <<str<< endl;
        }
    ui->textEdit->setText("");
    QString ss="姓名\t学号\t\t语文\t数学\t英语\n";
    ui->textEdit->setText(ss);
    QTextCodec *codec2=QTextCodec::codecForName("GBK");
    QFile file2("input2.dat");
    if(!file2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::about(nullptr,"提示","无法打开文件!");
    }
    while(!file2.atEnd())
    {
        QByteArray line = file2.readLine();
        QString str=codec2->toUnicode(line);
        ui->textEdit->append(str);
    }
     file.close();
       QMessageBox::about(nullptr,"提示","打印完成,生成文件input2.dat");
}

void MainWindow::on_pushButton_5_clicked()
{
    linkList l;
    ui->textEdit->setText("");
    QTextCodec *codec=QTextCodec::codecForName("GBK");
    QFile file("input.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::about(nullptr,"提示","无法打开文件!");
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str=codec->toUnicode(line);
        QStringList msg=str.split("\t");

        int avg=(msg.at(2).toInt()+msg.at(3).toInt()+msg.at(4).toInt())/3;
        l.add(msg.at(0),msg.at(1),msg.at(2).toInt(),msg.at(3).toInt(),msg.at(4).toInt(),avg);

    }

     l.sortOfGrade3();
     QString str=l.printlink();
    QFile file1("input3.dat");
    if (file1.open(QFile::Append | QFile::Truncate|QFile::Text))
        {
            QTextStream out(&file1);
            out <<str<< endl;
        }
    ui->textEdit->setText("");
    QString ss="姓名\t学号\t\t语文\t数学\t英语\n";
    ui->textEdit->setText(ss);
    QTextCodec *codec2=QTextCodec::codecForName("GBK");
    QFile file2("input3.dat");
    if(!file2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         QMessageBox::about(nullptr,"提示","无法打开文件!");
    }
    while(!file2.atEnd())
    {
        QByteArray line = file2.readLine();
        QString str=codec2->toUnicode(line);
        ui->textEdit->append(str);
    }
     file.close();
        QMessageBox::about(nullptr,"提示","打印完成,生成文件input2.dat");
}


void MainWindow::on_pushButton_2_clicked()
{
    linkList l;
    QTextCodec *codec=QTextCodec::codecForName("GBK");
    QFile file("input.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         QMessageBox::about(nullptr,"提示","无法打开文件!");
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str=codec->toUnicode(line);
        QStringList msg=str.split("\t");
        int avg=(msg.at(2).toInt()+msg.at(3).toInt()+msg.at(4).toInt())/3;
        l.add(msg.at(0),msg.at(1),msg.at(2).toInt(),msg.at(3).toInt(),msg.at(4).toInt(),avg);
    }
     file.close();
    QString ss="姓名\t学号\t\t平均分\n";
    ui->textEdit->setText(ss);
    l.sortOfAvger();
    ui->textEdit->append(l.getAvg()+"\n\n"+l.getDetail1()+"\n\n"+l.getDetail2()+"\n\n"+l.getDetail3());

}

void MainWindow::on_textEdit_textChanged()
{
    ui->textEdit->moveCursor(QTextCursor::End);
}

void MainWindow::on_pushButton_6_clicked()
{
    linkList l;
    QTextCodec *codec=QTextCodec::codecForName("GBK");
    QFile file("input.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         QMessageBox::about(nullptr,"提示","无法打开文件!");
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str=codec->toUnicode(line);
        QStringList msg=str.split("\t");
        int avg=(msg.at(2).toInt()+msg.at(3).toInt()+msg.at(4).toInt())/3;
        l.add(msg.at(0),msg.at(1),msg.at(2).toInt(),msg.at(3).toInt(),msg.at(4).toInt(),avg);
    }
     file.close();
    bool isOK;
    QString text = QInputDialog::getText(nullptr, "输入框", "请输入学号", QLineEdit::Normal, nullptr, &isOK);
    if(isOK) {
        ui->textEdit->setText("");
        QString ss="姓名\t学号\t\t语文\t数学\t英语\n";
        ui->textEdit->setText(ss);
        ui->textEdit->append(l.searchofid(text));
    }
}



void MainWindow::on_pushButton_9_clicked()
{
    linkList l;
    QTextCodec *codec=QTextCodec::codecForName("GBK");
    QFile file("input.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         QMessageBox::about(nullptr,"提示","无法打开文件!");
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str=codec->toUnicode(line);
        QStringList msg=str.split("\t");
        int avg=(msg.at(2).toInt()+msg.at(3).toInt()+msg.at(4).toInt())/3;
        l.add(msg.at(0),msg.at(1),msg.at(2).toInt(),msg.at(3).toInt(),msg.at(4).toInt(),avg);
    }
     file.close();
    bool isOK;
    QString text = QInputDialog::getText(nullptr, "输入框", "请输入姓名", QLineEdit::Normal, nullptr, &isOK);
    if(isOK) {
        ui->textEdit->setText("");
        QString ss="姓名\t学号\t\t语文\t数学\t英语\n";
        ui->textEdit->setText(ss);
        ui->textEdit->append(l.searchofname(text));
}
}
