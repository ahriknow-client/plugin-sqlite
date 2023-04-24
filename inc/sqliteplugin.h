#ifndef THEMEPLUGIN_H
#define THEMEPLUGIN_H

#include <plugin/inc/ipluginmodule.h>

#include <QWidget>
#include <QJsonObject>

class SqlitePlugin : public IPluginModule
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID IPluginModule_iid FILE "sqliteplugin.json")
    Q_INTERFACES(IPluginModule)
public:
    explicit SqlitePlugin(QWidget *parent = nullptr);
    
    ActivityButton *btn;
    QString id() override;
    QString name() override;
    QString version() override;
    ActivityButton *createActivityButton(QWidget *parent, int id) override;
    SideWidget *addSideWidget(QWidget *parent, int id) override;
    bool removeWidgetFromEdit(int id) override;
    bool channelReceive(QString fromId, QJsonObject data) override;

    ~SqlitePlugin();
};

#endif // THEMEPLUGIN_H
