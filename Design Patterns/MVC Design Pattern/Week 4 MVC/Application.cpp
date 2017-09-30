#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS



#include "Controller.h"
using namespace std;

HWND View::Tab = nullptr;
HINSTANCE View::_hInstance = nullptr;
int View::DialogHeight = 0;
int  View::DialogWidth = 0;
bool Controller::IsQueue1 = false;
bool Controller::Q1PlusQ2 = false;
Dialog View::_dialog;
TABCONTROL View::TabControl = Tab;
HWND View::FirstQueue = nullptr;
HWND View::SecondQueue = nullptr;
HWND View::ThirdQueue = nullptr;
HWND View::StatusDlg = nullptr;
KQueue<int> Controller::queue1 = { 0 };
KQueue<int> Controller::queue2 = { 0 };
KQueue<int> Controller::queue3 = { 0 };



int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	View view;
	
	KQueue<int> queue1 = initializer_list<int>{ 1,2,3,5,7,8,9 };
	KQueue<int> queue2 = initializer_list<int>{ 4,9,6,3,14,545 };
	KQueue<int>queue3;
	queue1.Resize(15);
	queue2.Resize(15);
	view.InitInstance (hInstance);
	Controller controller(queue1,queue2,queue3,view);
			
	if (!CreateDialogParamW(hInstance, MAKEINTRESOURCE(IDD_MyDialog), nullptr, controller.DialogProc, 0))
	{
		return FALSE;
	}

	ShowWindow((HWND)view._dialog, nCmdShow);
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}





