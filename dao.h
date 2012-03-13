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
   void deleteFromDB(QString title);
private:
   QSqlDatabase db;

};

#endif // DAO_H
