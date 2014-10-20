#include "dbcontroler.h"

QSqlDatabase DBControler::mydb;

bool DBControler::OpenDB(){
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("dic.db");
    if( !mydb.open() ){
        qDebug() << "Open DB Error\n";
    }

    QSqlQuery query(mydb);
    query.exec("create table person (id int primary key, "
                        "firstname varchar(20), lastname varchar(20))");
    query.exec("insert into person values(101, 'Danny', 'Young')");
    query.exec("insert into person values(102, 'Christine', 'Holand')");
    query.exec("insert into person values(103, 'Lars', 'Gordon')");
    query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
    query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");

    return true;
}

bool DBControler::CloseDB(){
    mydb.close();
}

bool DBControler::ShowTable(QString sql , QTableView *view){
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    view->setModel(model);
    view->show();
    delete model;

    return true;
}

DBControler::DBControler()
{
}
