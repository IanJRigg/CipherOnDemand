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
#include <QLineEdit>

#include "algorithms/algorithm-controller.h"
#include "window/window-common.h"

#include <QDebug>

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

    // Caeser Tab
    caesarTab = new QWidget(algorithmTabs);
    caesarTabLayout = new QHBoxLayout(caesarTab);
    caesarLabel = new QLabel(CAESER_LABLE_TEXT, caesarTab);
    caesarComboBox = new QComboBox(caesarTab);
    caesarComboBox->addItems(CAESAR_SHIFTS);
    caesarComboBox->setCurrentIndex(0L);
    setCaesarRotation(0L);

    caesarTabLayout->addWidget(caesarLabel);
    caesarTabLayout->addWidget(caesarComboBox);

    caesarTab->setLayout(caesarTabLayout);

    // Vigenere Tab
    vigenereTab = new QWidget(algorithmTabs);
    vigenereTabLayout = new QHBoxLayout(vigenereTab);
    vigenereLabel = new QLabel("ASCII Key: ", vigenereTab);
    vigenereLineEdit = new QLineEdit(vigenereTab);
    vigenereLineEdit->setValidator(new QRegExpValidator(ASCII_ALPHA_LOWER_REGEX, vigenereTab));

    vigenereTabLayout->addWidget(vigenereLabel);
    vigenereTabLayout->addWidget(vigenereLineEdit);


    // Add tabs
    algorithmTabs->addTab(caesarTab, "Caeser");
    algorithmTabs->addTab(vigenereTab, "Vigenère");

    // Input/Output Tab
    inputWidget = new QWidget(centerWidget);
    inputLayout = new QVBoxLayout(inputWidget);
    inputLabel = new QLabel("ASCII Input", inputWidget);
    inputTextEdit = new QPlainTextEdit(inputWidget);
    outputLabel = new QLabel("Output", inputWidget);

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

    connect(inputTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::validateInput);
    connect(vigenereLineEdit, &QLineEdit::textChanged, this, &MainWindow::validateVigenereKey);
    connect(caesarComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setCaesarRotation(int)));

    connect(algorithmTabs, SIGNAL(currentChanged(int)), this, SLOT(changeAlgorithm(int)));
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
    QString plainText = algorithmController.selectedAlgorithm().decrypt(cipherText);
    outputTextEdit->setPlainText(plainText);
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::validateInput()
{
    if (ASCII_ALPHA_WHITE_SPACE_REGEX.exactMatch(inputTextEdit->toPlainText()))
    {
        decryptButton->setEnabled(true);
        encryptButton->setEnabled(true);
    }
    else
    {
        decryptButton->setDisabled(true);
        encryptButton->setDisabled(true);
    }
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::validateVigenereKey()
{
    if (ASCII_ALPHA_LOWER_REGEX.exactMatch(vigenereLineEdit->text()))
    {
        decryptButton->setEnabled(true);
        encryptButton->setEnabled(true);

        algorithmController.vigenere().setKey(vigenereLineEdit->text());
    }
    else
    {
        decryptButton->setDisabled(true);
        encryptButton->setDisabled(true);
    }
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::setCaesarRotation(int index)
{
    // Index is zero based,
    algorithmController.caesar().setRotation(index + 1);
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::changeAlgorithm(int index)
{
    if (index == 0L)
    {
        algorithmController.setSelectedToCaesar();
    }
    else if (index == 1L)
    {
        algorithmController.setSelectedToVigenere();
    }

    resetCaesarTab();
    resetVigenereTab();

    inputTextEdit->clear();
    outputTextEdit->clear();
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::resetCaesarTab()
{
    caesarComboBox->setCurrentIndex(0L);
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::resetVigenereTab()
{
    vigenereLineEdit->setText("");

    validateVigenereKey();
}

/*-----------------------------------------------------------------------------
Return Value :
Description  :
-----------------------------------------------------------------------------*/
void MainWindow::initializeActions()
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
