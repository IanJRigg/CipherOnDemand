#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "algorithms/algorithm-controller.h"

class QMenu;
class QAction;
class QPlainTextEdit;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QPushButton;
class QComboBox;

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void encryptInput();
    void decryptInput();

private:
    void initializeActions();
    void initializeMenus();

    AlgorithmController algorithmController;

    QMenu* fileMenu;
    QAction* saveAction;
    QAction* exitAction;

    QWidget* centerWidget;
    QHBoxLayout* layout;
    QTabWidget* algorithmTabs;
    QWidget* inputWidget;
    QVBoxLayout* inputLayout;
    QLabel* inputLabel;
    QPlainTextEdit* inputTextEdit;
    QLabel* outputLabel;
    QPlainTextEdit* outputTextEdit;
    QWidget* buttonWidget;
    QHBoxLayout* buttonLayout;
    QPushButton* decryptButton;
    QPushButton* encryptButton;

    QWidget* caeserTab;
    QHBoxLayout* caeserTabLayout;
    QLabel* caeserLabel;
    QComboBox* caeserComboBox;

    QWidget* vigenereTab;

};

#endif // MAIN-WINDOW_H
