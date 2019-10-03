#include "note.h"
#include <QtWidgets/QApplication>
#include "mwin.h"



int main(int argc, char *argv[])
{

	QApplication a(argc, argv);

	//MWin *win = new MWin();
	//win->show();



	Note w;
	w.show();
	return a.exec();
}
