#include "dao.h"
#include "QString"
#include "QtSql"
DAO::DAO()
{
    if(QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
        db = QSqlDatabase::database();
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("d:\\db.db3");
    }

}
DAO::~DAO()
{
    db.close();
}
void DAO::AddToBase(QString title, QString source, QString base)
{
    if (db.open())
    {
        QSqlQuery a_query;
        a_query.prepare("INSERT INTO databases(title,dbname,dbsource) VALUES (:title,:dbname,:dbsource);");
        a_query.bindValue(":title",title);
        a_query.bindValue(":dbname",base);
        a_query.bindValue(":dbsource",source);
        bool b = a_query.exec();
        if (!b)
        {
            qDebug() << "Error";
        }
        else
        {
            qDebug()<<"Success";
        }

    }
    if (!db.open())
    {
        qDebug() << db.lastError().text();
    }
}
void DAO::deleteFromDB(QString title)
{
    if (db.open())
    {
    QSqlQuery a_query;
    a_query.prepare("DELETE FROM databases WHERE title=:title;");
    a_query.bindValue(":title",title);
    bool b = a_query.exec();
    if (!b)
    {
        qDebug() << "Error";
    }
    else
    {
        qDebug()<<"Success";
    }

}
    if (!db.open())
    {
       qDebug() << db.lastError().text();
    }
}

