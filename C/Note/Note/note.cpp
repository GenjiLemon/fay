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
	

	//��ʱ��
	m_pTimer = new QTimer(this);  
	connect(m_pTimer, &QTimer::timeout, this, &Note::GetSysTime);
	connect(m_pTimer, &QTimer::timeout, this, &Note::SetLedNumber);
	connect(m_pTimer, &QTimer::timeout, this, &Note::SetTogetherTime);

	m_pTimer->start(100);

	//������������
	ui.imageCalendar->setCalendarStyle(ImageCalendar::CalendarStyle_Gray);

	//
	
	//int  a = Image.getCalendarStyle();

	//���̳�ʼ��
	init();

	//����TextEdit�ı���ɫ
	QPalette pa = ui.textEditNote->palette();
	//pa.setColor(QPalette::Base, QColor(105, 105, 105));
	//pa.setColor(QPalette::Base, QColor(50, 50, 50));
	pa.setColor(QPalette::Base, QColor(97, 97, 97));
	pa.setColor(QPalette::Text, QColor(255, 255, 255));
	ui.textEditNote->setPalette(pa);

	QFont font("Microsoft YaHei", 15, 75); //��һ�����������壨΢���źڣ����ڶ����Ǵ�С���������ǼӴ֣�Ȩ����75�� 

	//����Static����ɫ
	
	ui.label_Note->setStyleSheet("background-color: rgb(50, 50, 50);");
	ui.label->setStyleSheet("background-color: rgb(50, 50, 50);");

	//ui.label_Together->setGeometry(QRect(5, 5, 100, 30));
	ui.label_Together->setStyleSheet("background-color: rgb(50, 50, 50);");
	ui.label_Together->setFont(font);



	ui.label_NextSee->setStyleSheet("background-color: rgb(50, 50, 50);");
	ui.groupBox->setStyleSheet("background-color: rgb(50, 50, 50);");

	this->setWindowFlags(Qt::FramelessWindowHint);//ȥ��������

	//��Ӱ�ť���ź�
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
	//������һ���ʱ��

	//��ȡϵͳʱ��
	QDateTime m_CurrentTime = QDateTime::currentDateTime();
	QString m_StrCurrentTime = m_CurrentTime.toString("yyyy-MM-dd hh:mm:ss");


	QString m_StrOldTime = "2019-5-22 00:00:00";
	QDateTime m_OldTime = QDateTime::fromString(m_StrOldTime, "yyyy-MM-dd hh:mm:ss");


	//ת��Ϊint
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
	//�´μ���ʱ��-��ǰʱ��
	//�´�ʱ��
	QString m_StrNextTime = "2019-9-13 00:00:00";
	QDateTime m_NextTime = QDateTime::fromString(m_StrNextTime, "yyyy-MM-dd hh:mm:ss");

	//��ȡϵͳʱ��
	QDateTime m_CurrentTime = QDateTime::currentDateTime();
	QString m_StrCurrentTime = m_CurrentTime.toString("yyyy-MM-dd hh:mm:ss");

	//ת��Ϊint
	uint Nexttime = m_NextTime.toTime_t();
	uint Currenttime = m_CurrentTime.toTime_t();
	int ndaysec = 24 * 60 * 60;
	int TimeSpan = (Nexttime - Currenttime) / (ndaysec)+((Nexttime - Currenttime) % (ndaysec)+(ndaysec - 1)) / (ndaysec)-1;
	//ʱ����
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
	/****������****/
	//this->setFixedSize(500, 500);
	this->setWindowTitle("Note");
	/****����*** */
	tray = new QSystemTrayIcon(this);                                                                                                                     /* ��ʼ�����̶���tray */
	tray->setIcon(QIcon(QPixmap("1.png")));                                                                                                 /* �趨����ͼ�꣬���������Զ����pngͼƬ·�� */
	tray->show();                                                                                                                                           /* ������ͼ����ʾ��ϵͳ������ */
	QObject::connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(TrayIconAction(QSystemTrayIcon::ActivationReason)));  /* �����ź���ۣ�ʵ�ֵ���ͼ��ָ����ڵĹ��ܣ������Զ���Ĳ� */
	/****��ʼ�����̲˵�������****/
	menu = new QMenu(this);                                                                                                                            /* ��ʼ���˵� */
	reset = new QAction(this);                                                                                                                          /* ��ʼ���ָ����� */
	reset->setText(QString::fromLocal8Bit("��ʾ����"));
	QObject::connect(reset, SIGNAL(triggered()), this, SLOT(showNormal()));                                                                           /* �˵��е���ʾ���ڣ�����������ʾ���� */
	quit = new QAction(this);                                                                                                                             /* ��ʼ���˳����� */
	quit->setText(QString::fromLocal8Bit("�˳�����"));
	QObject::connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));                                                                                  /* �˵��е��˳����򣬵��������˳�</span> */

	/*
	* qApp����Qt�Դ���demo�е�֪ʶ�㣬����һ���ĵ���qApp��Qt������app��ָ�룬�ر����Ϳ��Թرյ�ǰ�ĳ���
	* ֮���Բ���this��close()�����������Ҫ��رո�Ϊ��С�������̣�����close()�Ĺ����Ѿ������ǹرմ��ڵĹ��ܣ�����Ҫ��Ѱ����
	* ������õĲ˵��������̵Ĳ˵�ģ����
	*/
	tray->setContextMenu(menu);
	menu->addAction(reset);
	menu->addAction(quit);
}
/* ***���ùر�close()*** */
void Note::closeEvent(QCloseEvent *event)
{
	hide();                 /* ���ش��� */
	event->ignore();        /* ���Թر��¼� */
}


/*
* ��Ϊʵ�ֵ��ǹرմ�����ϵͳ���̣����������Ƚ�����hide()���أ��ٺ��Թرմ��ڹ���event->ignore()���ɡ�
* ***����ͼ���***
*/
void Note::TrayIconAction(QSystemTrayIcon::ActivationReason reason)
/* ������Qt�ı����֣���ʾ������ͼ��Ĳ������òۺ�������ֻʵ���˵������ܣ�����ʵ���������ܱ���˫�����л�������ɲ��ĵ�����Qt�Դ�demo(�ؼ���tray) */
{
	if (reason == QSystemTrayIcon::Trigger)
		this->showNormal();  /* �����ͼ����е���������ʾ������С�Ĵ��� */
}
