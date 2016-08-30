#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	mSearchEdit = new QLineEdit;
	mSearchEditAction = new QWidgetAction(this);
	mSearchEditAction->setDefaultWidget(mSearchEdit);
	buildMenu();
}

void MainWindow::buildMenu()
{
	mMenu = new QMenu(ui->menu);

	QAction *subact = new QAction(mMenu);
	subact->setText("subact");
	QMenu *submenu = new QMenu(mMenu);
	subact->setMenu(submenu);
	mMenu->addAction(subact);

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
