#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPushButton>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
//        curView = dynamic_cast<CircuitBaseView *>(ui->tabWidget->currentWidget());
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
//            slotActSave();
            ui->tabWidget->removeTab(index);
        }
        else if (msgBox.clickedButton() == unsave) {
            ui->tabWidget->removeTab(index);
        }
    });
}


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
//    curView = view;
}

void MainWindow::slotActOpen()
{
    qDebug() << "text";
}

