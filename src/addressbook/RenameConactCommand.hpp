#pragma once

#include <QVariant>
#include <QVariantMap>

#include "DataBase.hpp"


namespace Xeth{


class RenameConactCommand
{
    public:
        RenameConactCommand(DataBase &database);

        QVariant operator()(const QVariantMap &);

    private:
        DataBase &_database;

};


}
