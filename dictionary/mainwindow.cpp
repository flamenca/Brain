#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

