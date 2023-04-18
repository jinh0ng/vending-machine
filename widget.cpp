#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"
#include "QString"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int price)
{
    money +=price;
    ui->lcdNumber->display(money);

    if(money  >= 100)
        ui->pushButton_5->setEnabled(true);
    else
        ui->pushButton_5->setEnabled(false);

    if(money>=150)
        ui->pushButton_6->setEnabled(true);
    else
        ui->pushButton_6->setEnabled(false);

    if(money>=200)
        ui->pushButton_7->setEnabled(true);
    else
        ui->pushButton_7->setEnabled(false);
}

void Widget::on_pushButton_clicked()
{
    changeMoney(10);
}


void Widget::on_pushButton_2_clicked()
{
    changeMoney(50);
}


void Widget::on_pushButton_3_clicked()
{
    changeMoney(100);
}


void Widget::on_pushButton_4_clicked()
{
    changeMoney(500);
}


void Widget::on_pushButton_5_clicked()
{
    changeMoney(-100);
}


void Widget::on_pushButton_6_clicked()
{
    changeMoney(-150);
}


void Widget::on_pushButton_7_clicked()
{
    changeMoney(-200);
}


void Widget::on_pushButton_8_clicked()
{
    QMessageBox msg;
    int balance = money;

    int coin_500 = balance/500;
    balance %= 500;
    int coin_100 = balance/100;
    balance %= 100;
    int coin_50 = balance/50;
    balance %= 50;
    int coin_10 = balance/10;
    //balance %= 10;

    ui->lcdNumber->display(money);

    QString str = "500:  "+ QString::number(coin_500) +", 100: "+QString::number(coin_100)+", 50: "+QString::number(coin_50)+", 10: "+QString::number(coin_10);

    msg.information(nullptr, "Reset", str);
}

