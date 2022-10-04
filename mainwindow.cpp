#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMetaObject>
#include <QDebug>

#include "itemlabel.h"
#include "reflect.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tabWidgetInit();
    itemDockWidgetInit();

    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::slotActNew);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::slotActOpen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tabWidgetInit()
{
    ui->tabWidget->setTabsClosable(true);

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, [=](int index)
    {
        Q_UNUSED(index);
    });

    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, [=](int index){
        QMessageBox msgBox;
        msgBox.setText("The document has changed. Whether to save the changes?");

        QPushButton *save = msgBox.addButton("Save", QMessageBox::ActionRole);
        QPushButton *unsave = msgBox.addButton("Unsave", QMessageBox::ActionRole);
        QPushButton *cancel = msgBox.addButton("Cancel", QMessageBox::ActionRole);
        Q_UNUSED(cancel);

        msgBox.exec();

        if(msgBox.clickedButton() == save)
        {
            ui->tabWidget->removeTab(index);
        }
        else if (msgBox.clickedButton() == unsave) {
            ui->tabWidget->removeTab(index);
        }
    });
}

/*
 * 初始化图元的选项栏
 */
void MainWindow::itemDockWidgetInit()
{
    QVBoxLayout *vlayout = new QVBoxLayout(ui->dockWidgetContents);
    ui->dockWidgetContents->setLayout(vlayout);

    QStringList itemList = getItemsList("./items.txt");

    int size = itemList.size();
    for (int i = 0; i < size; i++) {
        QString name = itemList.at(i);
        ItemLabel *itemLabel = new ItemLabel(name, getItemPixmap(name), ui->dockWidgetContents);
        vlayout->addWidget(itemLabel);
    }
}

/*
    从配置文件items.txt中读出所有的图元列表
*/
QStringList MainWindow::getItemsList(const QString &filepath) const
{
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);

    QStringList list;

    while (!stream.atEnd()) {
        QString item;
        stream >> item;
        list << item;
    }
    return list;
}

/*
 * 通过图元的名字获取其图片的路径
*/
QString MainWindow::getItemPixmap(const QString &name) const
{
    static QString pixmap_path = "./images/";
    static QString pixmap_suffix = ".png";
    return pixmap_path+name+pixmap_suffix;
}

/*
 * 创建新页面
*/
void MainWindow::slotActNew()
{
    static int count = 0;
    QString text = "untitled_" + QString::number(count);
    count ++;
    qDebug() << text;
    MScene *pScene = new MScene(this);
    pScene->setSceneRect(-297*3/2, -210*3/2, 297*3, 210*3);
    MView *view = new MView(pScene);
    ui->tabWidget->addTab(view, text);
    ui->tabWidget->setCurrentWidget(view);
}

void MainWindow::slotActOpen()
{
    QString str("");
    qDebug() << str;
}

