#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextCodec>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("[1] 우리나라");
    qDebug() << "[1] : " << ui->label->text();

    ui->label_2->setText("[2] " + QString::fromUtf8("우리나라"));
    qDebug() << "[2] : " << ui->label_2->text();

    ui->label_3->setText("[3] " + QString(QString::fromLocal8Bit("우리나라").constData()));
    qDebug() << "[3] : " << ui->label_3->text();

    ui->label_4->setText("[4] " + QString::fromLatin1("우리나라"));
    qDebug() << "[4] : " << ui->label_4->text();

    QTextCodec* codec5 = QTextCodec::codecForName("EUC-KR");
    ui->label_5->setText("[5] " + codec5->toUnicode("우리나라"));
    qDebug() << "[5] : " << ui->label_5->text();

    QTextCodec* codec6 = QTextCodec::codecForName("UTF-8");
    ui->label_6->setText("[6] " + codec6->toUnicode("우리나라"));
    qDebug() << "[6] : " << ui->label_6->text();

    ui->label_7->setText("[7] " + codec6->toUnicode(qPrintable(QString::fromUtf8("우리나라"))));
    qDebug() << "[7] : " << ui->label_7->text();

    fprintf(stderr, "[10] : %s\n", QString::fromUtf8("우리나라").toLocal8Bit().constData());

    fprintf(stderr, "[11] : %s\n", qPrintable(QString::fromUtf8("우리나라")));
}
