#pragma execution_character_set("utf-8")

#include "frmimagecalendar.h"
#include "ui_frmimagecalendar.h"

frmImageCalendar::frmImageCalendar(QWidget *parent) :
QWidget(parent),
ui(new Ui::frmImageCalendar)
{
	ui->setupUi(this);
	this->initForm();
}

frmImageCalendar::~frmImageCalendar()
{
	delete ui;
}

void frmImageCalendar::initForm()
{
	ui->imageCalendar1->setCalendarStyle(ImageCalendar::CalendarStyle_Yellow);

	
	
}
