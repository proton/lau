#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "cstdlib"
#include "iostream"
#include "QTextCodec"
#include "QSettings"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setModel();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setModel()
{
    if(QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
        db = QSqlDatabase::database();
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("d:\\db.db3");
    }
    if (db.open())
    {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT title FROM databases");

    ui->listView->setModel(model);
    }else{
        qDebug()<<QObject::trUtf8("Ошибка");
    }
}

void MainWindow::LaunchProgs(const char* str,
                             const char* app,
                             const char* dbname,
                             const char* dbsource)
{
    QSettings settings("HKEY_CURRENT_USER\\Software\\MedComTech",
                        QSettings::NativeFormat);
    settings.setValue("ADMSTAT/DATABASE", "Polmct06004");
}

void MainWindow::on_pbAdmin_clicked()
{
    LaunchProgs("Администратор",NULL,NULL,NULL);

}

void MainWindow::on_pbTalon_clicked()
{
    LaunchProgs("Талон",NULL,NULL,NULL);
}

void MainWindow::on_pbLgota_clicked()
{

    LaunchProgs("Льгота",NULL,NULL,NULL);
}

void MainWindow::on_pbLAdmin_clicked()
{

    LaunchProgs("Админ льгота",NULL,NULL,NULL);
}

void MainWindow::on_pbPrPokoy_clicked()
{

    LaunchProgs("Приемный покой",NULL,NULL,NULL);
}

void MainWindow::on_pbMedStat_clicked()
{

    LaunchProgs("Медицинский статистик",NULL,NULL,NULL);
}

void MainWindow::on_pbEcon_clicked()
{

    LaunchProgs("Экономист",NULL,NULL,NULL);
}

void MainWindow::on_pbStMed_clicked()
{

    LaunchProgs("Старшая медсестра",NULL,NULL,NULL);
}

void MainWindow::on_pbSettings_clicked()
{
    Settings s;
    s.exec();
}
