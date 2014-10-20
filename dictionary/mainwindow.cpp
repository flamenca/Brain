#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydbview = new DBViewer();

    QAction * openAction = new QAction(tr("&Open..."), this);
    connect( openAction,SIGNAL( triggered()),this,SLOT(OnOpen()) );

    ui->mainToolBar ->addAction(openAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::OnOpen(){

}
