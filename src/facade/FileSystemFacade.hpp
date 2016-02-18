#pragma once 

#include <QObject>

#include "command/filesystem/BrowseCommand.hpp"
#include "command/filesystem/SaveImageCommand.hpp"

#include "Notifier.hpp"
#include "Invoker.hpp"


namespace Xeth{


class FileSystemFacade : public QObject
{
    Q_OBJECT
    public:
        FileSystemFacade(Notifier &);


        Q_INVOKABLE QVariant browse(const QVariantMap &);
        Q_INVOKABLE QVariant browse();

    private:
        Invoker _invoker;
};


}