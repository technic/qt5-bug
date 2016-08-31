#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	mSearchEdit = new QLineEdit;
	mSearchEditAction = new QWidgetAction(this);
	mSearchEditAction->setDefaultWidget(mSearchEdit);
	buildMenu();

	QTimer::singleShot(1000, this, &MainWindow::on_menu_clicked);
	QTimer::singleShot(2000, this, &MainWindow::on_test_clicked);
	QTimer::singleShot(3000, this, &MainWindow::on_menu_clicked);
}

void MainWindow::buildMenu()
{
	mMenu = new QMenu(ui->menu);

	// these 2 lines causes the bug
	mMenu->setStyleSheet("QMenu { background: rgba(240, 0, 0, 100%); }");
	QMenu *submenu = new QMenu(mMenu);

	mMenu->addAction(mSearchEditAction);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_menu_clicked()
{
	mMenu->popup(pos() + ui->menu->pos());
}

void MainWindow::on_test_clicked()
{
	mMenu->removeAction(mSearchEditAction);
	delete mMenu;
	buildMenu();
}
