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
	void SetLedNumber();	//设置Led的数字
	void SetTogetherTime();

private:
	QTimer*  m_pTimer;

private:
	Ui::NoteClass ui;

public:

	void init();//初始化函数

	QSystemTrayIcon *tray;//托盘图标
	QMenu *menu;//托盘菜单
	QAction *reset;//菜单实现功能：恢复窗口
	QAction *quit;//菜单实现功能：退出程序

protected:
	void closeEvent(QCloseEvent *event);//由于要关闭窗口变为隐藏至托盘图标，所以要重写close事件

signals:
	public slots :
		void TrayIconAction(QSystemTrayIcon::ActivationReason reason);//对托盘图标操作的槽：本代码实现单机图标恢复窗口功能
	void ClickButton();

};

#endif // NOTE_H
