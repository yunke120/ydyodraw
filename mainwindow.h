#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mview.h"
#include "mscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QPushButton;
class QDebug;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void tabWidgetInit(void);
    void itemDockWidgetInit();

    QMap<QString, QString> getItemsList(const QString &filepath);

protected slots:
    void slotActNew(void);
    void slotActOpen(void);

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
