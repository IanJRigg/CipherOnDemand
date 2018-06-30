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
#include <QComboBox>

#include "algorithms/algorithm-controller.h"

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      algorithmController()
{
    setFixedSize(1200L, 675L);
    setMinimumSize(1200L, 675L);

    initializeActions();
    initializeMenus();

    // Window
    centerWidget = new QWidget(this);
    layout = new QHBoxLayout(centerWidget);

    // Algorithm Tab
    algorithmTabs = new QTabWidget(centerWidget);

    // caeser Tab
    caeserTab = new QWidget(algorithmTabs);
    caeserTabLayout = new QHBoxLayout(caeserTab);
    caeserLabel = new QLabel("Rotation Factor: ", caeserTab);
    caeserComboBox = new QComboBox(caeserTab);
    caeserComboBox->addItems({ "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                               "11", "12", "13", "14", "15", "16", "17", "18",
                               "19", "20", "21", "22", "23", "24", "25", "26"});

    caeserTabLayout->addWidget(caeserLabel);
    caeserTabLayout->addWidget(caeserComboBox);

    caeserTab->setLayout(caeserTabLayout);


    // Caeser Tab
    caeserTab = new QWidget(algorithmTabs);
    vigenereTab = new QWidget(algorithmTabs);

    // Add tabs
    algorithmTabs->addTab(caeserTab, "Caeser");
    algorithmTabs->addTab(vigenereTab, "Vigenère");




    // Input/Output Tab
    inputWidget = new QWidget(centerWidget);
    inputLayout = new QVBoxLayout(inputWidget);
    inputLabel = new QLabel("ASCII Plain Text", inputWidget);
    inputTextEdit = new QPlainTextEdit(inputWidget);
    outputLabel = new QLabel("Ciphertext", inputWidget);

    outputTextEdit = new QPlainTextEdit(inputWidget);
    outputTextEdit->setReadOnly(true);

    buttonWidget = new QWidget(inputWidget);
    buttonLayout = new QHBoxLayout(buttonWidget);
    decryptButton = new QPushButton("Decrypt Input", buttonWidget);
    encryptButton = new QPushButton("Encrypt Input", buttonWidget);

    buttonLayout->addWidget(decryptButton);
    buttonLayout->addWidget(encryptButton);

    buttonWidget->setLayout(buttonLayout);




    // Add to the vertical layout of the I/O Tab
    inputLayout->addWidget(inputLabel);
    inputLayout->addWidget(inputTextEdit);
    inputLayout->addWidget(outputLabel);
    inputLayout->addWidget(outputTextEdit);
    inputLayout->addWidget(buttonWidget);

    inputWidget->setLayout(inputLayout);

    // Add the two top level widgets to the main layout
    layout->addWidget(algorithmTabs);
    layout->addWidget(inputWidget);

    // Add the layout to the center widget
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
    QString plainText = inputTextEdit->toPlainText();
    QString cipherText = algorithmController.selectedAlgorithm().encrypt(plainText);
    outputTextEdit->setPlainText(cipherText);
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::decryptInput()
{
    QString cipherText = inputTextEdit->toPlainText();
    QString plainText = algorithmController.selectedAlgorithm().decrypt(plainText);
    outputTextEdit->setPlainText(plainText);
}
