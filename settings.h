#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "dao.h"
#include "QtSql"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    void setModel();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Settings *ui;
    DAO dao;
    QSqlDatabase db;

};

#endif // SETTINGS_H
