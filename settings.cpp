#include "settings.h"
#include "ui_settings.h"
#include "adddialog.h"
#include "QDebug"
#include "QtSql"
#include "dao.h"
#include "QFileDialog"
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
    dao = DAO();
    QSqlTableModel model = new QSqlTableModel();
    ui->tableView->setModel(&model);
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
//    model->removeRow(ui->tableView->selectionModel()->currentIndex().row());
    setModel();
}

void Settings::on_pushButton_3_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
        "C:\\",QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
        db = QSqlDatabase::database();
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("d:\\db.db3");
    }
    QSqlQuery query;
    qDebug()<<dir;
    bool result = query.exec(QString("UPDATE settings SET VALUE = '%1' WHERE setting = 'path';").arg(dir));
    if (result)
    {
        qDebug()<<query.lastQuery();
    }else{
        qDebug()<<query.lastError();
    }
}
