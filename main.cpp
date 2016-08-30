#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setStyleSheet("QMenu { background: rgba(240, 0, 0, 100%); }");

	MainWindow w;
	w.show();

	return a.exec();
}
