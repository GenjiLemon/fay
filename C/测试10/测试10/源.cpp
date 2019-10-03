
/*********************头文件**************************/
#include<windows.h>

//多媒体设备接口的头文件和库文件
#include<mmsystem.h>

#pragma comment(lib,"winmm.lib")


/************************************全局函数声明**********************************************/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
BOOL GameInit(HWND hwnd);
VOID GamePaint(HWND hwnd);

/************************************全局常量定义**********************************************/
#define WND_WIDTH 1920
#define WND_HEIGHT 1080


/************************************全局变量定义**********************************************/
HDC g_hdc, g_memdc;//设备的窗口句柄，内存设备句柄
HBITMAP g_bmp;//空位图
HBITMAP g_backbmp;//背景图片


//主程序

int WINAPI WinMain
(
    HINSTANCE hInstance,//当前实例句柄：用来标志在Windows系统中每一个程序的，程序身份证
    HINSTANCE hPreIstance, //先前实例句柄：
    LPSTR lpCmdLine, //命令行
    int nShowCmd//显示格式
)
{
   
    WNDCLASSEX wnd = {0};  //wnd 是我们需要的一个窗口  需要初始化

	//设计窗口

	wnd.cbSize = sizeof(WNDCLASSEX);//窗口在内存中所需的内存大小
	wnd.cbClsExtra = 0;//程序的附加内存
	wnd.cbWndExtra = 0;//窗口的附加内存
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//背景的画刷
    wnd.hCursor = NULL;//鼠标样式
	wnd.hIcon = NULL;//像标
	wnd.hInstance = hInstance;
	wnd.style = CS_VREDRAW | CS_HREDRAW;//窗口样式	//水平、垂直方向改变窗口大小
	wnd.lpszMenuName = NULL;//菜单名称
	wnd.lpszClassName = L"萌新试水";//窗口的类名称
	wnd.lpfnWndProc = WndProc;//窗口过程函数

	//注册窗口
	RegisterClassEx(&wnd);

	//创建窗口
	HWND hwnd = //窗口句柄
	CreateWindow
	(L"萌新试水",//窗口类
	L"给你听一首起风了", //窗口标题
	WS_OVERLAPPEDWINDOW,//窗口风格
	0, 0, //窗口初始位置   CW_USEDEFAULT为默认值
	WND_WIDTH, WND_HEIGHT,//窗口大小
	NULL, NULL, hInstance, NULL);
	//创建一个重叠式窗口、弹出式窗口、子窗口


	//显示窗口、更新窗口
	ShowWindow(hwnd,nShowCmd);
	UpdateWindow(hwnd);
	
	mciSendString(L"open ./起风了.mp3 alias music", 0, 0, 0); //向驱动层发送字符串消息
	mciSendString(L"play music", 0, 0, 0);
	
	//主函数中 对整个程序数据的初始化
	if (!GameInit(hwnd))
	{
		return -1;
	}

	//等待用户指令、消息
	MSG msg = {0};
	while (msg.message != WM_QUIT)//循环条件：设置什么时候退出
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		//PeekMessage函数  消息检查线程消息队列，并将该消息（如果存在）放于指定的结构
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

//窗口过程函数
//针对用户不同指令，做出不同反应
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
	g_hdc = GetDC(hwnd);//获取窗口设备句柄
	g_memdc = CreateCompatibleDC(g_hdc);//创建与窗口兼容的设备
	g_bmp = CreateCompatibleBitmap(g_hdc, WND_WIDTH, WND_HEIGHT);//创建与窗口兼容的空位图
	g_backbmp = (HBITMAP)LoadImage(NULL/*实例句柄*/,L"./timg.bmp"/*文件名*/,IMAGE_BITMAP/*文件格式*/,
		1920, 1080/*大小*/, LR_LOADFROMFILE/*加载方式：源于文件*/);

	/*
	工具：g_hdc		g_memdc		g_bmp
	素材：g_backbmp
	步骤：	1.将空位图(g_bmp)写入内存设备(memdc)中;
			2.将背景图(g_backbmp)写入内存设备(memdc)中;
			3.将内存设备(memdc)载入窗口(g_hdc)中;
	*/

	//步骤1：
	SelectObject(g_memdc,g_bmp);

	return TRUE;
}


VOID GamePaint(HWND hwnd)
{
	//步骤2：
	SelectObject(g_memdc,g_backbmp);

	//步骤3：
	//位图-->设备：SelectObject
	//设备-->设备：BitBlt
	BitBlt(g_hdc/*目标设备*/,0,0,1920,1080/*规定粘贴的起始位置与宽高，设置范围*/,
		g_memdc/*源设备*/, 0, 0/*源设备中的起始值*/, SRCCOPY/*拷贝*/);

}
