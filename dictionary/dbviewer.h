#ifndef DBVIEWER_H
#define DBVIEWER_H

#include <QWidget>

namespace Ui {
class DBViewer;
}

class DBViewer : public QWidget
{
    Q_OBJECT

public:
    explicit DBViewer(QWidget *parent = 0);
    ~DBViewer();

private:
    Ui::DBViewer *ui;
};

#endif // DBVIEWER_H
