#include "dbviewer.h"
#include "ui_dbviewer.h"
#include "dbcontroler.h"

DBViewer::DBViewer(QWidget *parent) :
    QWidget(parent)
{
    DBControler::OpenDB();

    dbview = new QTableView(this);
    model = new QSqlTableModel;

    dbview->setGeometry(0,0,APP_WIDTH,APP_HEIGHT);
    dbview->setModel(model);

    setGeometry(0,APP_TOOLBAR_WIDTH,APP_WIDTH,APP_HEIGHT);
}

DBViewer::~DBViewer()
{
    DBControler::CloseDB();
}

void  DBViewer::OnOpen(){
    DBControler::ShowTable("", model);
    dbview->show();
}
