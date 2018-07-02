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
class QLineEdit;

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void encryptInput();
    void decryptInput();
    void validateInput();
    void validateVigenereKey();
    void setCaesarRotation(int index);
    void changeAlgorithm(int index);

private:
    void initializeActions();
    void initializeMenus();

    void resetCaesarTab();
    void resetVigenereTab();

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

    QWidget* caesarTab;
    QHBoxLayout* caesarTabLayout;
    QLabel* caesarLabel;
    QComboBox* caesarComboBox;

    QWidget* vigenereTab;
    QHBoxLayout* vigenereTabLayout;
    QLabel* vigenereLabel;
    QLineEdit* vigenereLineEdit;
};

#endif // MAIN-WINDOW_H
