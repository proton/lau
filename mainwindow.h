#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtSql"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void LaunchProgs(const char* str, const char *app, const char *dbname, const char *dbsource);
    void setModel();
private slots:

    void on_pbAdmin_clicked();

    void on_pbTalon_clicked();

    void on_pbLgota_clicked();

    void on_pbLAdmin_clicked();

    void on_pbPrPokoy_clicked();

    void on_pbMedStat_clicked();

    void on_pbEcon_clicked();

    void on_pbStMed_clicked();

    void on_pbSettings_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
