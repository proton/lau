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

    model = new QSqlTableModel();
    model->setTable("databases");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Заголовок"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Источник"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("База"));
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
    qDebug()<<ui->tableView->currentIndex();
    model->removeRow(ui->tableView->selectionModel()->currentIndex().row());
    setModel();
}
