#ifndef DBVIEWER_H
#define DBVIEWER_H

#include <QWidget>
#include <QtWidgets/QTableView>
#include <QtSql>

#define APP_WIDTH   640
#define APP_HEIGHT  800
#define APP_TOOLBAR_WIDTH   24
namespace Ui {
class DBViewer;
}

class DBViewer : public QWidget
{
    Q_OBJECT

public:
    explicit DBViewer(QWidget *parent = 0);
    ~DBViewer();

public slots:
    void  OnOpen();

private:
    QTableView *dbview;
    QSqlTableModel *model;
};

#endif // DBVIEWER_H
