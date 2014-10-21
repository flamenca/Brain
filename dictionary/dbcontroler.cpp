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
    query.exec("insert into person values(106, 'Danny', 'Young')");
    query.exec("insert into person values(107, 'Christine', 'Holand')");
    query.exec("insert into person values(108, 'Lars', 'Gordon')");
    query.exec("insert into person values(109, 'Roberto', 'Robitaille')");
    query.exec("insert into person values(110, 'Maria', 'Papadopoulos')");
    query.exec("insert into person values(111, 'Danny', 'Young')");
    query.exec("insert into person values(112, 'Christine', 'Holand')");
    query.exec("insert into person values(113, 'Lars', 'Gordon')");
    query.exec("insert into person values(114, 'Roberto', 'Robitaille')");
    query.exec("insert into person values(115, 'Maria', 'Papadopoulos')");
    query.exec("insert into person values(116, 'Danny', 'Young')");
    query.exec("insert into person values(117, 'Christine', 'Holand')");
    query.exec("insert into person values(118, 'Lars', 'Gordon')");
    query.exec("insert into person values(119, 'Roberto', 'Robitaille')");
    query.exec("insert into person values(120, 'Maria', 'Papadopoulos')");

    return true;
}

bool DBControler::CloseDB(){
    mydb.close();
}

bool DBControler::ShowTable(QString sql , QSqlTableModel *model){
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    return true;
}

DBControler::DBControler()
{
}
