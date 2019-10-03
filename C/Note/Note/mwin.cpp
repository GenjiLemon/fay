#include "mwin.h"
#include <QMenu>

MWin::MWin(QWidget *parent) :
QWidget(parent)
{
	init(); /* ��ʼ�� */
}


void MWin::init()
{
	/****������****/
	this->setFixedSize(500, 500);
	this->setWindowTitle("1APP");
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
void MWin::closeEvent(QCloseEvent *event)
{
	hide();                 /* ���ش��� */
	event->ignore();        /* ���Թر��¼� */
}


/*
* ��Ϊʵ�ֵ��ǹرմ�����ϵͳ���̣����������Ƚ�����hide()���أ��ٺ��Թرմ��ڹ���event->ignore()���ɡ�
* ***����ͼ���***
*/
void MWin::TrayIconAction(QSystemTrayIcon::ActivationReason reason)
/* ������Qt�ı����֣���ʾ������ͼ��Ĳ������òۺ�������ֻʵ���˵������ܣ�����ʵ���������ܱ���˫�����л�������ɲ��ĵ�����Qt�Դ�demo(�ؼ���tray) */
{
	if (reason == QSystemTrayIcon::Trigger)
		this->showNormal();  /* �����ͼ����е���������ʾ������С�Ĵ��� */
}

