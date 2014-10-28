#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "prelearnwords.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydbview = new DBViewer(this);

    setGeometry(100,100,APP_WIDTH,APP_HEIGHT+APP_TOOLBAR_WIDTH);

    QAction * openAction = new QAction(tr("&Open..."), this);
    connect( openAction,SIGNAL( triggered()),mydbview,SLOT(OnOpen()) );
    ui->mainToolBar ->addAction(openAction);

    QAction * listziAction = new QAction(tr("&Ci..."), this);
    connect( listziAction,SIGNAL( triggered()),this,SLOT(OnInitCi()) );
    ui->mainToolBar ->addAction(listziAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::OnInitZi(){
    PreLearnWords::InitZi();
}

void  MainWindow::OnInitCi(){
    PreLearnWords::InitCi();
}

