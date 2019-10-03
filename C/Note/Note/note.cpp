#include "note.h"
#include <QFile>
#include <QLabel>
#include <QPushButton>
#include <QDateTime>
#include <QTimer>

#include <iostream>
#include "ui_frmimagecalendar.h"
#include <QMenu>
#include <QMessageBox>

class CommonHelper
{
public:
	static void setStyle(const QString &style) {
		QFile qss(style);
		
		if (qss.open(QFile::ReadOnly))
		{
			qApp->setStyleSheet(qss.readAll());
		}
		
		qss.close();
	}
};



Note::Note(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	CommonHelper::setStyle("style.qss");

	this->setWindowIcon(QIcon(":/Resources/Myapp.ico"));

	this->setWindowIcon(QIcon(":/Note/Resources/Myapp.ico"));

	//pLabel = new QLabel(this);



	//pLabel->setText(strTimeSpan); 
	//pLabel->setGeometry(QRect(5, 5, 100, 30));
	//pLabel->setStyleSheet("color: white");
	

	//定时器
	m_pTimer = new QTimer(this);  
	connect(m_pTimer, &QTimer::timeout, this, &Note::GetSysTime);
	connect(m_pTimer, &QTimer::timeout, this, &Note::SetLedNumber);
	connect(m_pTimer, &QTimer::timeout, this, &Note::SetTogetherTime);

	m_pTimer->start(100);

	//设置日历背景
	ui.imageCalendar->setCalendarStyle(ImageCalendar::CalendarStyle_Gray);

	//
	
	//int  a = Image.getCalendarStyle();

	//托盘初始化
	init();

	//设置TextEdit的背景色
	QPalette pa = ui.textEditNote->palette();
	//pa.setColor(QPalette::Base, QColor(105, 105, 105));
	//pa.setColor(QPalette::Base, QColor(50, 50, 50));
	pa.setColor(QPalette::Base, QColor(97, 97, 97));
	pa.setColor(QPalette::Text, QColor(255, 255, 255));
	ui.textEditNote->setPalette(pa);

	QFont font("Microsoft YaHei", 15, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75） 

	//设置Static的颜色
	
	ui.label_Note->setStyleSheet("background-color: rgb(50, 50, 50);");
	ui.label->setStyleSheet("background-color: rgb(50, 50, 50);");

	//ui.label_Together->setGeometry(QRect(5, 5, 100, 30));
	ui.label_Together->setStyleSheet("background-color: rgb(50, 50, 50);");
	ui.label_Together->setFont(font);



	ui.label_NextSee->setStyleSheet("background-color: rgb(50, 50, 50);");
	ui.groupBox->setStyleSheet("background-color: rgb(50, 50, 50);");

	this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏

	//添加按钮的信号
	connect(ui.pushButtonHide, SIGNAL(clicked()), this, SLOT(ClickButton()));

}

void Note::TimeOutSelf()
{
	std::cout << "xiaobai  over" << std::endl;
}


Note::~Note()
{

}
void Note::SetTogetherTime()
{
	//设置在一起的时间

	//获取系统时间
	QDateTime m_CurrentTime = QDateTime::currentDateTime();
	QString m_StrCurrentTime = m_CurrentTime.toString("yyyy-MM-dd hh:mm:ss");


	QString m_StrOldTime = "2019-5-22 00:00:00";
	QDateTime m_OldTime = QDateTime::fromString(m_StrOldTime, "yyyy-MM-dd hh:mm:ss");


	//转换为int
	uint Currenttime = m_CurrentTime.toTime_t();

	uint Oldtime = m_OldTime.toTime_t();

	int ndaysec = 24 * 60 * 60;

	int TimeSpan = (Currenttime - Oldtime) / (ndaysec)+((Currenttime - Oldtime) % (ndaysec)+(ndaysec - 1)) / (ndaysec)-1;

	QString strTimeSpan;
	strTimeSpan = QString::number(TimeSpan);

	QString str;
	str.sprintf("%d Days", TimeSpan);


	ui.label_Together->setText(str);
	


}

void Note::SetLedNumber()
{
	//下次见面时间-当前时间
	//下次时间
	QString m_StrNextTime = "2019-9-13 00:00:00";
	QDateTime m_NextTime = QDateTime::fromString(m_StrNextTime, "yyyy-MM-dd hh:mm:ss");

	//获取系统时间
	QDateTime m_CurrentTime = QDateTime::currentDateTime();
	QString m_StrCurrentTime = m_CurrentTime.toString("yyyy-MM-dd hh:mm:ss");

	//转换为int
	uint Nexttime = m_NextTime.toTime_t();
	uint Currenttime = m_CurrentTime.toTime_t();
	int ndaysec = 24 * 60 * 60;
	int TimeSpan = (Nexttime - Currenttime) / (ndaysec)+((Nexttime - Currenttime) % (ndaysec)+(ndaysec - 1)) / (ndaysec)-1;
	//时间间隔
	QString strTimeSpan;
	strTimeSpan = QString::number(TimeSpan);

	if (TimeSpan<10)
	{
		ui.ledNumberL->setNumber(0);
		ui.ledNumberR->setNumber(TimeSpan);
	}
	else
	{
		int RDay = TimeSpan % 10;
		int LDay = TimeSpan / 10 % 10;

		ui.ledNumberL->setNumber(LDay);
		ui.ledNumberR->setNumber(RDay);
	}
}

void Note::GetSysTime()
{
	//Number++;
	//QString strTimeSpan;
	//strTimeSpan = QString::number(Number);

	//pLabel->setText(strTimeSpan);
}


void Note::ClickButton()
{
	SetLedNumber();
	hide();
	//QMessageBox::warning(NULL, "warning", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void Note::init()
{
	/****主窗口****/
	//this->setFixedSize(500, 500);
	this->setWindowTitle("Note");
	/****托盘*** */
	tray = new QSystemTrayIcon(this);                                                                                                                     /* 初始化托盘对象tray */
	tray->setIcon(QIcon(QPixmap("1.png")));                                                                                                 /* 设定托盘图标，引号内是自定义的png图片路径 */
	tray->show();                                                                                                                                           /* 让托盘图标显示在系统托盘上 */
	QObject::connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(TrayIconAction(QSystemTrayIcon::ActivationReason)));  /* 连接信号与槽，实现单击图标恢复窗口的功能，槽是自定义的槽 */
	/****初始化托盘菜单及功能****/
	menu = new QMenu(this);                                                                                                                            /* 初始化菜单 */
	reset = new QAction(this);                                                                                                                          /* 初始化恢复窗口 */
	reset->setText(QString::fromLocal8Bit("显示窗口"));
	QObject::connect(reset, SIGNAL(triggered()), this, SLOT(showNormal()));                                                                           /* 菜单中的显示窗口，单击连接显示窗口 */
	quit = new QAction(this);                                                                                                                             /* 初始化退出程序 */
	quit->setText(QString::fromLocal8Bit("退出程序"));
	QObject::connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));                                                                                  /* 菜单中的退出程序，单击连接退出</span> */

	/*
	* qApp，是Qt自带的demo中的知识点，查了一下文档，qApp是Qt中所有app的指针，关闭它就可以关闭当前的程序
	* 之所以不用this，close()，是由于软件要求关闭改为最小化到托盘，所以close()的功能已经不再是关闭窗口的功能，所以要另寻方法
	* 将定义好的菜单加入托盘的菜单模块中
	*/
	tray->setContextMenu(menu);
	menu->addAction(reset);
	menu->addAction(quit);
}
/* ***重置关闭close()*** */
void Note::closeEvent(QCloseEvent *event)
{
	hide();                 /* 隐藏窗口 */
	event->ignore();        /* 忽略关闭事件 */
}


/*
* 因为实现的是关闭窗口至系统托盘，所以我们先将窗口hide()隐藏，再忽略关闭窗口功能event->ignore()即可。
* ***托盘图标槽***
*/
void Note::TrayIconAction(QSystemTrayIcon::ActivationReason reason)
/* 参数是Qt的保留字，表示对托盘图标的操作，该槽函数功能只实现了单击功能，可以实现其他功能比如双击、中击，具体可查文档或者Qt自带demo(关键字tray) */
{
	if (reason == QSystemTrayIcon::Trigger)
		this->showNormal();  /* 如果对图标进行单击，则显示正常大小的窗口 */
}
