#ifndef NOTE_H
#define NOTE_H

#include <QtWidgets/QMainWindow>

#include "ui_note.h"
#include "imagecalendar.h"
#include <QSystemTrayIcon>

#include <QWidget>
#include <QtGui>

#pragma comment(lib, "quc.lib")  
//#pragma comment(lib, "qucd.lib")  



class  QTimer;
class  QLabel;

class Note : public QMainWindow
{
	Q_OBJECT

public:
	Note(QWidget *parent = 0);
	~Note();


public:
	void GetSysTime();

	QLabel *pLabel;
	int Number = 0;

	private slots:
	void TimeOutSelf();
	void SetLedNumber();	//����Led������
	void SetTogetherTime();

private:
	QTimer*  m_pTimer;

private:
	Ui::NoteClass ui;

public:

	void init();//��ʼ������

	QSystemTrayIcon *tray;//����ͼ��
	QMenu *menu;//���̲˵�
	QAction *reset;//�˵�ʵ�ֹ��ܣ��ָ�����
	QAction *quit;//�˵�ʵ�ֹ��ܣ��˳�����

protected:
	void closeEvent(QCloseEvent *event);//����Ҫ�رմ��ڱ�Ϊ����������ͼ�꣬����Ҫ��дclose�¼�

signals:
	public slots :
		void TrayIconAction(QSystemTrayIcon::ActivationReason reason);//������ͼ������Ĳۣ�������ʵ�ֵ���ͼ��ָ����ڹ���
	void ClickButton();

};

#endif // NOTE_H
