#include "HelloQt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HelloQt w;
	w.show();
	return a.exec();
}
