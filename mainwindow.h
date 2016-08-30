#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QWidgetAction>
#include <QLineEdit>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_menu_clicked();

	void on_test_clicked();

private:
	Ui::MainWindow *ui;
	QMenu *mMenu;
	QLineEdit *mSearchEdit;
	QWidgetAction *mSearchEditAction;
	void buildMenu();
};

#endif // MAINWINDOW_H
