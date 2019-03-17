#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<fstream>
#include<iostream>
#include <iomanip>
#include"QFile"
#include "QTextStream"
#include "QMessageBox"
#include "QRegExpValidator"
#include "QIntValidator"
#include "QTextCodec"
#include "QString"
#include "QTextEdit"
#include "QInputDialog"
#pragma execution_character_set("utf-8")

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void receivelogin();
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_textEdit_textChanged();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

signals:
    void getQTextEdit(QTextEdit* textedit);

private:
    Ui::MainWindow *ui;
    QString data;
    int key;
private :
    static int count;
    static QString Stuids[100];


};
class StuNode
{
public:
    StuNode *next;
    QString StuName;
    QString StuId;
    int Grade1=0;
    int Grade2=0;
    int Grade3=0;
    int avgGrades=0;
};

class linkList
{
private:
    StuNode *head;
    int length=0;
public:
    linkList()
    {
        head=new StuNode();
        head->StuName="";
        head->StuId="";
        head->Grade1=0;
        head->Grade2=0;
        head->Grade3=0;
        head->next=nullptr;
    }
    void add(QString StuName,QString StuId,int grade1,int grade2,int grade3,int avg)
    {
        StuNode *newnode=new StuNode();
        newnode->StuName=StuName;
        newnode->StuId=StuId;
        newnode->Grade1=grade1;
        newnode->Grade2=grade2;
        newnode->Grade3=grade3;
        newnode->avgGrades=avg;
        newnode->next=nullptr;
        StuNode *p=head;
        if(head==nullptr)
        {
            head=newnode;
            length=0;
        }else {
            while (p->next!=nullptr) {
                p=p->next;
            }
            p->next=newnode;
            length++;
        }
    }
    int getlength()
    {
        return length;
    }
    void sortOfGrade1()
    {
        StuNode *p;
        StuNode *r;
     if(head==nullptr){
        return ;
     }
     int i,j;
      for(i=0 ,p=head->next;i<length;++i,p=p->next){
        for(j=i+1,r=p->next; j<length;++j,r=r->next){
            if(p->Grade1>r->Grade1){
                swap(p,r);
            }
        }
      }


    }
    void sortOfGrade2()
    {
        StuNode *p;
        StuNode *r;
     if(head==nullptr){
        return ;
     }
     int i,j;
      for(i=0 ,p=head->next;i<length;++i,p=p->next){
        for(j=i+1,r=p->next; j<length;++j,r=r->next){
            if(p->Grade2>r->Grade2){
                swap(p,r);
            }
        }
      }
    }
    void sortOfAvg()
    {
        StuNode *p;
        StuNode *r;
     if(head==nullptr){
        return ;
     }
     int i,j;
      for(i=0 ,p=head->next;i<length;++i,p=p->next){
        for(j=i+1,r=p->next; j<length;++j,r=r->next){
            if(p->avgGrades>r->avgGrades){
                swap(p,r);
            }
        }
      }
    }
    void sortOfGrade3()
    {
        StuNode *p;
        StuNode *r;
     if(head==nullptr){
        return ;
     }
     int i,j;
      for(i=0 ,p=head->next;i<length;++i,p=p->next){
        for(j=i+1,r=p->next; j<length;++j,r=r->next){
            if(p->Grade3>r->Grade3){
                swap(p,r);
            }
        }
      }
    }

    void swap(StuNode *p,StuNode *r)
    {
        QString string[6];
        string[0]=p->StuName;
        string[1]=p->StuId;
        string[2]=QString::number(p->Grade1,10);
        string[3]=QString::number(p->Grade2,10);
        string[4]=QString::number(p->Grade3,10);
        string[5]=QString::number(p->avgGrades,10);
        p->StuName=r->StuName;
        p->StuId=r->StuId;
        p->Grade1=r->Grade1;
        p->Grade2=r->Grade2;
        p->Grade3=r->Grade3;
        p->avgGrades=r->avgGrades;
        r->StuName=string[0];
        r->StuId=string[1];
        r->Grade1=string[2].toInt();
        r->Grade2=string[3].toInt();
        r->Grade3=string[4].toInt();
        r->avgGrades=string[5].toInt();
    }

    QString getAvg()
    {

        if(head==nullptr||head->next==nullptr) return nullptr;
        StuNode *p=head->next;
        QString str;
        while (p!=nullptr) {
            str.append(p->StuName+"\t"+p->StuId+"\t"+QString::number(p->avgGrades,10)+"\n");
            p=p->next;
        }

        return str;


    }
    QString getDetail1()
    {

        int maxAvg=-1,minAvg=101,under60=0,under70=0,under80=0,under90=0,under100=0;
            if(head->next==nullptr) return nullptr;
           StuNode *p=head->next;
            while (p!=nullptr) {
                if(p->Grade1>maxAvg)  maxAvg=p->Grade1;
                if(p->Grade1<minAvg) minAvg=p->Grade1;
                if(p->Grade1<60){under60++;}
                else if(p->Grade1<70){under70++;}
                else if (p->Grade1<80) {under80++; }
                else if (p->Grade1<90) {under90++;}
                else {under100++;}
                p=p->next;
            }

            return "语文最高分:"+QString::number(maxAvg,10)+"\t"+"语文最低分:"+QString::number(minAvg,10)+"\n"
                    +"低于60分人数 "+QString::number(under60,10)+"\t"+"60~70分人数 "+QString::number(under70,10)+"\n"
                    +"70~80分人数 "+QString::number(under80,10)+"\t"+"80~90分人数 "+QString::number(under90,10)+"\n"
                    +"90~100分人数 "+QString::number(under100,10);

        }
    QString getDetail2()
    {
        int maxAvg=-1,minAvg=101,under60=0,under70=0,under80=0,under90=0,under100=0;
         StuNode *p;
            if(head->next==nullptr||head==nullptr) return nullptr;
            p=head->next;
            while (p!=nullptr) {
                if(p->Grade2>maxAvg)  maxAvg=p->Grade2;
                if(p->Grade2<minAvg) minAvg=p->Grade2;
                if(p->Grade2<60){under60++;}
                else if(p->Grade2<70){under70++;}
                else if (p->Grade2<80) {under80++; }
                else if (p->Grade2<90) {under90++;}
                else {under100++;}
                p=p->next;
            }
            return "数学最高分:"+QString::number(maxAvg,10)+"\t"+"语文最低分:"+QString::number(minAvg,10)+"\n"
                    +"低于60分人数:"+QString::number(under60,10)+"\t"+"60~70分人数:"+QString::number(under70,10)+"\n"
                    +"70~80分人数:"+QString::number(under80,10)+"\t"+"80~90分人数:"+QString::number(under90,10)+"\n"
                    +"90~100分人数:"+QString::number(under100,10);
    }
    QString getDetail3()
    {
        int maxAvg=-1,minAvg=101,under60=0,under70=0,under80=0,under90=0,under100=0;
         StuNode *p;
            if(head->next==nullptr||head==nullptr) return nullptr;
            p=head->next;
            while (p!=nullptr) {
                if(p->Grade3>maxAvg)  maxAvg=p->Grade3;
                if(p->Grade3<minAvg) minAvg=p->Grade3;
                if(p->Grade3<60){under60++;}
                else if(p->Grade3<70){under70++;}
                else if (p->Grade3<80) {under80++; }
                else if (p->Grade3<90) {under90++;}
                else {under100++;}
                p=p->next;
            }
            return "英语最高分:"+QString::number(maxAvg,10)+"\t"+"语文最低分:"+QString::number(minAvg,10)+"\n"
                    +"低于60分人数:"+QString::number(under60,10)+"\t"+"60~70分人数:"+QString::number(under70,10)+"\n"
                    +"70~80分人数:"+QString::number(under80,10)+"\t"+"80~90分人数:"+QString::number(under90,10)+"\n"
                    +"90~100分人数:"+QString::number(under100,10);
    }

    QString searchofname(QString name)
    {
        std::cout<<"222222222"<<std::endl;
        QString str;
        if(head==nullptr) return nullptr;
        StuNode *p=head->next;
        while (p!=nullptr) {
            if(p->StuName==name)
                str.append(p->StuName+"\t"+p->StuId+"\t"+QString::number(p->Grade1,10)+"\t"+QString::number(p->Grade2,10)+"\t"+QString::number(p->Grade3,10)+"\n");
            p=p->next;
        }

        return str;
    }
    QString searchofid(QString id)
    {

        QString str;
        if(head==nullptr) return nullptr;
        StuNode *p=head->next;
        while (p!=nullptr) {
            if(p->StuId==id)
                str.append(p->StuName+"\t"+p->StuId+"\t"+QString::number(p->Grade1,10)+"\t"+QString::number(p->Grade2,10)+"\t"+QString::number(p->Grade3,10)+"\n");
            p=p->next;


        }

        return str;
    }

    QString printlink()
    {

        StuNode *p=head->next;
        QString str="";

        if(head==nullptr||head->next==nullptr)
        {

            return nullptr;

        }
        while (p!=nullptr) {

                str.append(p->StuName+"\t"+p->StuId+"\t"+QString::number(p->Grade1,10)+"\t"+QString::number(p->Grade2,10)+"\t"+QString::number(p->Grade3,10)+"\n");
                p=p->next;

        }


        return str;
    }
    void sortOfAvger()
    {
        StuNode *p;
        StuNode *r;
     if(head==nullptr){
        return ;
     }
     int i,j;
      for(i=0 ,p=head->next;i<length;++i,p=p->next){
        for(j=i+1,r=p->next; j<length;++j,r=r->next){
            if(p->avgGrades>r->avgGrades){
                swap(p,r);
            }
        }
      }
    }
};

#endif // MAINWINDOW_H
