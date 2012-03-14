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
        qDebug()<<QObject::trUtf8("������");
    }
    QSqlQuery query;

    if (query.exec("SELECT * FROM settings WHERE Setting = 'path';"))
    {
         QSqlRecord rec = query.record();
        while (query.next())
        {
        ui->label_path->setText(query.value(rec.indexOf("VALUE")).toString());
        }
    }else{
        ui->label_path->setText(QObject::tr("���������� ��������� ���� � ������"));
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
    LaunchProgs("�������������",NULL,NULL,NULL);

}

void MainWindow::on_pbTalon_clicked()
{
    LaunchProgs("�����",NULL,NULL,NULL);
}

void MainWindow::on_pbLgota_clicked()
{

    LaunchProgs("������",NULL,NULL,NULL);
}

void MainWindow::on_pbLAdmin_clicked()
{

    LaunchProgs("����� ������",NULL,NULL,NULL);
}

void MainWindow::on_pbPrPokoy_clicked()
{

    LaunchProgs("�������� �����",NULL,NULL,NULL);
}

void MainWindow::on_pbMedStat_clicked()
{

    LaunchProgs("����������� ���������",NULL,NULL,NULL);
}

void MainWindow::on_pbEcon_clicked()
{

    LaunchProgs("���������",NULL,NULL,NULL);
}

void MainWindow::on_pbStMed_clicked()
{

    LaunchProgs("������� ���������",NULL,NULL,NULL);
}

void MainWindow::on_pbSettings_clicked()
{
    Settings s;
    if (s.exec() == QDialog::Rejected)
    {
        setModel();
    }
}
