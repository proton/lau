#include "settings.h"
#include "ui_settings.h"
#include "adddialog.h"
#include "QDebug"
#include "QtSql"
#include "dao.h"
Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{

    ui->setupUi(this);
    setModel();
}

Settings::~Settings()
{
    delete ui;
}
void Settings::setModel()
{
    if(QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
        db = QSqlDatabase::database();
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("d:\\db.db3");
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setHeaderData(0, Qt::Horizontal, QObject::trUtf8("Заголовок"));
    model->setHeaderData(1, Qt::Horizontal, QObject::trUtf8("Источник"));
    model->setHeaderData(2, Qt::Horizontal, QObject::trUtf8("База"));
    model->setQuery("SELECT title,dbsource,dbname FROM databases");
    ui->tableView->setModel(model);
}

void Settings::on_pushButton_clicked()
{
    AddDialog add;
    if (add.exec()== QDialog::Accepted)
    {
    dao.AddToBase(add.title(),add.dbsource(),add.dbname());
    setModel();
    }
}

void Settings::on_pushButton_2_clicked()
{

}
