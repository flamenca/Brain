#include "dbviewer.h"
#include "ui_dbviewer.h"
#include "dbcontroler.h"

DBViewer::DBViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBViewer)
{
    ui->setupUi(this);
    DBControler::OpenDB();
    DBControler::ShowTable("", ui->tableView );
}

DBViewer::~DBViewer()
{
    DBControler::CloseDB();
    delete ui;
}
