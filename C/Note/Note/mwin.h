#ifndef MWIN_H
#define MWIN_H

#include <QWidget>
#include <QtGui>
#include <QSystemTrayIcon>



class MWin : public QWidget
{
	Q_OBJECT
public:
	explicit MWin(QWidget *parent = 0);
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
};

#endif // MWIN_H
