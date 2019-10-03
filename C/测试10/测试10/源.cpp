
/*********************ͷ�ļ�**************************/
#include<windows.h>

//��ý���豸�ӿڵ�ͷ�ļ��Ϳ��ļ�
#include<mmsystem.h>

#pragma comment(lib,"winmm.lib")


/************************************ȫ�ֺ�������**********************************************/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
BOOL GameInit(HWND hwnd);
VOID GamePaint(HWND hwnd);

/************************************ȫ�ֳ�������**********************************************/
#define WND_WIDTH 1920
#define WND_HEIGHT 1080


/************************************ȫ�ֱ�������**********************************************/
HDC g_hdc, g_memdc;//�豸�Ĵ��ھ�����ڴ��豸���
HBITMAP g_bmp;//��λͼ
HBITMAP g_backbmp;//����ͼƬ


//������

int WINAPI WinMain
(
    HINSTANCE hInstance,//��ǰʵ�������������־��Windowsϵͳ��ÿһ������ģ��������֤
    HINSTANCE hPreIstance, //��ǰʵ�������
    LPSTR lpCmdLine, //������
    int nShowCmd//��ʾ��ʽ
)
{
   
    WNDCLASSEX wnd = {0};  //wnd ��������Ҫ��һ������  ��Ҫ��ʼ��

	//��ƴ���

	wnd.cbSize = sizeof(WNDCLASSEX);//�������ڴ���������ڴ��С
	wnd.cbClsExtra = 0;//����ĸ����ڴ�
	wnd.cbWndExtra = 0;//���ڵĸ����ڴ�
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//�����Ļ�ˢ
    wnd.hCursor = NULL;//�����ʽ
	wnd.hIcon = NULL;//���
	wnd.hInstance = hInstance;
	wnd.style = CS_VREDRAW | CS_HREDRAW;//������ʽ	//ˮƽ����ֱ����ı䴰�ڴ�С
	wnd.lpszMenuName = NULL;//�˵�����
	wnd.lpszClassName = L"������ˮ";//���ڵ�������
	wnd.lpfnWndProc = WndProc;//���ڹ��̺���

	//ע�ᴰ��
	RegisterClassEx(&wnd);

	//��������
	HWND hwnd = //���ھ��
	CreateWindow
	(L"������ˮ",//������
	L"������һ�������", //���ڱ���
	WS_OVERLAPPEDWINDOW,//���ڷ��
	0, 0, //���ڳ�ʼλ��   CW_USEDEFAULTΪĬ��ֵ
	WND_WIDTH, WND_HEIGHT,//���ڴ�С
	NULL, NULL, hInstance, NULL);
	//����һ���ص�ʽ���ڡ�����ʽ���ڡ��Ӵ���


	//��ʾ���ڡ����´���
	ShowWindow(hwnd,nShowCmd);
	UpdateWindow(hwnd);
	
	mciSendString(L"open ./�����.mp3 alias music", 0, 0, 0); //�������㷢���ַ�����Ϣ
	mciSendString(L"play music", 0, 0, 0);
	
	//�������� �������������ݵĳ�ʼ��
	if (!GameInit(hwnd))
	{
		return -1;
	}

	//�ȴ��û�ָ���Ϣ
	MSG msg = {0};
	while (msg.message != WM_QUIT)//ѭ������������ʲôʱ���˳�
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		//PeekMessage����  ��Ϣ����߳���Ϣ���У���������Ϣ��������ڣ�����ָ���Ľṹ
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			GamePaint(hwnd);
		}
	}

    return 0;
}

//���ڹ��̺���
//����û���ָͬ�������ͬ��Ӧ
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}

	return DefWindowProc(hwnd,message,wparam,lparam);
}


BOOL GameInit(HWND hwnd)
{
	g_hdc = GetDC(hwnd);//��ȡ�����豸���
	g_memdc = CreateCompatibleDC(g_hdc);//�����봰�ڼ��ݵ��豸
	g_bmp = CreateCompatibleBitmap(g_hdc, WND_WIDTH, WND_HEIGHT);//�����봰�ڼ��ݵĿ�λͼ
	g_backbmp = (HBITMAP)LoadImage(NULL/*ʵ�����*/,L"./timg.bmp"/*�ļ���*/,IMAGE_BITMAP/*�ļ���ʽ*/,
		1920, 1080/*��С*/, LR_LOADFROMFILE/*���ط�ʽ��Դ���ļ�*/);

	/*
	���ߣ�g_hdc		g_memdc		g_bmp
	�زģ�g_backbmp
	���裺	1.����λͼ(g_bmp)д���ڴ��豸(memdc)��;
			2.������ͼ(g_backbmp)д���ڴ��豸(memdc)��;
			3.���ڴ��豸(memdc)���봰��(g_hdc)��;
	*/

	//����1��
	SelectObject(g_memdc,g_bmp);

	return TRUE;
}


VOID GamePaint(HWND hwnd)
{
	//����2��
	SelectObject(g_memdc,g_backbmp);

	//����3��
	//λͼ-->�豸��SelectObject
	//�豸-->�豸��BitBlt
	BitBlt(g_hdc/*Ŀ���豸*/,0,0,1920,1080/*�涨ճ������ʼλ�����ߣ����÷�Χ*/,
		g_memdc/*Դ�豸*/, 0, 0/*Դ�豸�е���ʼֵ*/, SRCCOPY/*����*/);

}
