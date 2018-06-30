#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

class QMenu;
class QAction;
class QPlainTextEdit;
class QHBoxLayout;
class QVBoxLayout;
class QLabel;
class QPushButton;

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void initializeActions();
    void initializeMenus();

private slots:
    void encryptInput();
    void decryptInput();

private:
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

    QWidget* rotTab;
    QWidget* caeserTab;

};

#endif // MAIN-WINDOW_H
