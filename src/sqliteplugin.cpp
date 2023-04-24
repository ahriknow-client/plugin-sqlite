#include "sqliteplugin.h"

SqlitePlugin::SqlitePlugin(QWidget *parent) : IPluginModule(parent)
{
}

QString SqlitePlugin::id()
{
    return "SqlitePlugin";
}

QString SqlitePlugin::name()
{
    return "SqlitePlugin";
}

QString SqlitePlugin::version()
{
    return "1.0.0";
}

ActivityButton *SqlitePlugin::createActivityButton(QWidget *parent, int id)
{
    this->btn = new ActivityButton(parent, ":/icons/close-default.png", ":/icons/close-active.png", id);
    return this->btn;
}

SideWidget *SqlitePlugin::addSideWidget(QWidget *parent, int id)
{
    for (int i=0; i<2; i++)
    {
        EditWidget *w0 = new EditWidget(parent, "Sqlite Plugin" + QString::number(i), i);
        emit this->addWidgetToEdit(w0);
    }
    QJsonObject data;
    data.insert("id", id);
    emit this->channelSend(this->id(), data);
    SideWidget *widget = new SideWidget(parent, id);
    return widget;
}

bool SqlitePlugin::removeWidgetFromEdit(int id)
{
    qDebug() << "removeWidgetFromEdit" << id;
    return true;
}

bool SqlitePlugin::channelReceive(QString fromId, QJsonObject data)
{
    qDebug() << "channelReceive" << fromId << data;
    return true;
}

SqlitePlugin::~SqlitePlugin()
{
}
