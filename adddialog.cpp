#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}
QString AddDialog::title() const
{
    return ui->leTitle->text();
}

QString AddDialog::dbname() const
{
    return ui->leBase->text();
}

QString AddDialog::dbsource() const
{
    return ui->leServer->text();
}

AddDialog::~AddDialog()
{
    delete ui;
}
