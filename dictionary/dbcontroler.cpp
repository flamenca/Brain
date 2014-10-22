#include "dbcontroler.h"

QSqlDatabase DBControler::mydb;

bool DBControler::OpenDB(){
    if(mydb.isOpen()) return true;
    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("dic.db");
    if( !mydb.open() ){
        qDebug() << "Open DB Error\n";
    }
/*
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
*/
    return true;
}

bool DBControler::ExecuteSQL(QString sql){
    qDebug() << sql;
    QSqlQuery query(mydb);
    return query.exec(sql);
}


bool DBControler::CreateZITable(){
    ExecuteSQL("drop table zi");
    return ExecuteSQL("create table zi (id integer primary key autoincrement, zi varchar(8), pinyin varchar(64), bihua int, bushou varchar(8))");
}

bool DBControler::AddZItoTable(int id,QString zi,QString pinyin,QString bihua,QString bushou){
    return ExecuteSQL("insert into zi values("+ QString::number(id,10) +", '" + zi +"', '"+ pinyin +"',"+bihua+",'"+ bushou +"')");
}

bool DBControler::CloseDB(){
    mydb.close();
    return true;
}

bool DBControler::ShowTable(QString sql , QSqlTableModel *model){
    model->setTable("zi");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    return true;
}

DBControler::DBControler()
{
}
