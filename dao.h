#ifndef DAO_H
#define DAO_H
#include "QString"
#include "QtSql"
class DAO
{
public:
    DAO();
    ~DAO();
   void AddToBase(QString title, QString source, QString base);
   QSqlTableModel* getModel();
private:
   QSqlDatabase db;
   QSqlTableModel *model;

};

#endif // DAO_H
