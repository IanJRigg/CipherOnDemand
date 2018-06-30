#include "main-window.h"

#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPlainTextEdit>
#include <QLabel>
#include <QDebug>

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(1200L, 675L);
    setMinimumSize(1200L, 675L);

    initializeActions();
    initializeMenus();

    centerWidget = new QWidget(this);
    layout = new QHBoxLayout(centerWidget);
    algorithmTabs = new QTabWidget(centerWidget);
    inputWidget = new QWidget(centerWidget);
    inputLayout = new QVBoxLayout(inputWidget);
    inputLabel = new QLabel("Input", inputWidget);
    inputTextEdit = new QPlainTextEdit(inputWidget);
    outputLabel = new QLabel("Output", inputWidget);
    outputTextEdit = new QPlainTextEdit(inputWidget);
    buttonWidget = new QWidget(inputWidget);
    buttonLayout = new QHBoxLayout(buttonWidget);
    decryptButton = new QPushButton("Decrypt Input", buttonWidget);
    encryptButton = new QPushButton("Encrypt Input", buttonWidget);

    buttonLayout->addWidget(decryptButton);
    buttonLayout->addWidget(encryptButton);

    buttonWidget->setLayout(buttonLayout);

    rotTab = new QWidget(algorithmTabs);
    caeserTab = new QWidget(algorithmTabs);

    algorithmTabs->addTab(rotTab, "Rot");
    algorithmTabs->addTab(caeserTab, "Caeser");

    inputLayout->addWidget(inputLabel);
    inputLayout->addWidget(inputTextEdit);
    inputLayout->addWidget(outputLabel);
    inputLayout->addWidget(outputTextEdit);
    inputLayout->addWidget(buttonWidget);

    inputWidget->setLayout(inputLayout);

    layout->addWidget(algorithmTabs);
    layout->addWidget(inputWidget);

    centerWidget->setLayout(layout);

    setCentralWidget(centerWidget);

    connect(encryptButton, &QAbstractButton::released, this, &MainWindow::encryptInput);
    connect(decryptButton, &QAbstractButton::released, this, &MainWindow::decryptInput);
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
MainWindow::~MainWindow()
{

}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void  MainWindow::initializeActions()
{
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, &QAction::triggered, this, &QWidget::close);
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::initializeMenus()
{
//    fileMenu = menuBar()->addMenu(tr("&File"));
//    fileMenu->addAction(exitAction);
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::encryptInput()
{
    if ((outputTextEdit == nullptr) || (inputTextEdit == nullptr))
    {
        qDebug() << "Null pointers abound!";
        return;
    }

    outputTextEdit->setPlainText(inputTextEdit->toPlainText());
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::decryptInput()
{
    outputTextEdit->setPlainText(inputTextEdit->toPlainText());
}
