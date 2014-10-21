#ifndef DBCONTROLER_H
#define DBCONTROLER_H

#include <QtSql>
#include <QtWidgets/QTableView>

class DBControler
{
public:
    DBControler();

    static bool OpenDB();
    static bool CloseDB();
    static bool ShowTable(QString sql , QSqlTableModel *model);
private:
    static QSqlDatabase mydb;

};

#endif // DBCONTROLER_H
