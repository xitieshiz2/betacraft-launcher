#ifndef SERVERLISTWIDGET_H
#define SERVERLISTWIDGET_H

#include <QtGui>

extern "C" {
#include "../../core/Betacraft.h"
}

class QGridLayout;
class QLineEdit;
class QListWidget;
class QListWidgetItem;
class QPushButton;

class ServerListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ServerListWidget(QWidget *parent = NULL);
    void initServerList();

private slots:
    void onServerListRefresh();
    void onServerListFetchFinish();
    void onSearchButton();
    void onServerClicked(QListWidgetItem* item);
    void populateServerList();

signals:
    void signal_serverGameLaunch(const char* ip, const char* port);

protected:
    void keyPressEvent(QKeyEvent* e);

private:
    void addServerItem(bc_server server);
    QGridLayout* _layout;
    QLineEdit* _searchTextBox;
    QListWidget* _serverList;
    QPushButton* _serverListRefreshButton;
    QPushButton* _searchButton;
    QFutureWatcher<int> _serverArrayWatcher;
};

#endif
