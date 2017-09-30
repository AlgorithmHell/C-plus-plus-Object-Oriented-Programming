#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS



#include <Windows.h>
#include "resource.h"
#include <iostream>
#include "Dialog.h"
#include "TabControl.h"
#include "KQueue.h"
#include <vector>
#include <string>
using namespace std;
KQueue <int> queue1 =initializer_list<int> { 1,2,3,5,7,8,9 };
KQueue <int> queue2 = initializer_list<int>{ 4,9,6,3,14,545 };

bool IsQueue1;

HINSTANCE _hInstance;
Dialog _dialog;
MSG msg;
static HWND Tab;
HWND ListBox;
static HDC hdc;
static HBRUSH BG;

HWND ThirdQueue;
HWND Push;
HWND Pop;
HWND FirstQueue;
HWND SecondQueue;
HWND ConfirmQ1;
HWND ConfirmQ2;
HWND ResizeProcess;
HWND AppendProcess;
HWND PushProcess;
HWND PopProcess;
HWND NameStatic;


HWND ButtonPlus;
HWND ButtonMinus;
HWND ButtonClear;
HWND Swap;
HWND Clear;
HWND Resize;
HWND StatusDlg;
HWND Q1Q2;
HWND Q2Q1;
static TABCONTROL TabControl(Tab);
const int DialogWidth = 800;
const int DialogHeight = 500;
int ListItemsCount = -1;

bool Q1PlusQ2;
namespace ControlID
{
	const int TabControlID = 1001;
	const int FirstQueue = 1002;
	const int SecondQueue = 1016;

	const int ID_Push = 1014;
	const int ID_Pop = 1015;
	const int ID_Swap = 1010;
	const int ID_Clear = 1011;
	const int ThirdQueue = 1100;
}
static INT_PTR CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);
static void OnInitialize();
static void SetDialogProperties();
static void InitializeTabControl();
static void InitializeControls();
static void InitializeSomething();
static BOOL OnNotify(LPARAM);
static void OnCommand(WPARAM);
static void OnPop();
static void OnResize();
static void InitializeQueue();
static void OnPush();
void ProcessListBox(WPARAM);
HWND GetControl(int id);
HWND GetControlQ(int id,HWND);
INT_PTR CALLBACK StatusProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);



int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{


	_hInstance = hInstance;
	if (!CreateDialogParamW(hInstance, MAKEINTRESOURCE(IDD_MyDialog), nullptr, DialogProc, 0))
	{
		return FALSE;
	}

	ShowWindow((HWND)_dialog, nCmdShow);
	
	while (GetMessage(&msg, nullptr, 0, 0))
	{

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return (int)msg.wParam;
}

static INT_PTR CALLBACK DialogProc(HWND hDialog, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (TabControl.TryProcessMessage(message, wParam, lParam)) return TRUE;

	switch (message)
	{
	
	
	case WM_INITDIALOG:
		_dialog.Initialize(hDialog);
		OnInitialize();
		
		return (INT_PTR)TRUE;

	case WM_CLOSE:
		_dialog.Destroy();
		return TRUE;
		
	case WM_COMMAND:
		OnCommand(wParam);
		break;
	

	case WM_DESTROY:
		PostQuitMessage(0);
		return TRUE;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK StatusProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	
	case WM_INITDIALOG:
	{
		SendMessage(GetControlQ(ID_Equal,hWnd), WM_SETTEXT, 0, queue1==queue2?(LPARAM)L"TRUE":(LPARAM)L"FALSE");
		SendMessage(GetControlQ(ID_NotEqual,hWnd), WM_SETTEXT, 0, queue1 != queue2 ? (LPARAM)L"TRUE":(LPARAM)L"FALSE");
		SendMessage(GetControlQ(ID_IsEmpty_1, hWnd), WM_SETTEXT, 0, queue1.isEmpty() ? (LPARAM)L"TRUE" : (LPARAM)L"FALSE");
		SendMessage(GetControlQ(ID_IsEmpty_2, hWnd), WM_SETTEXT, 0, queue2.isEmpty() ? (LPARAM)L"TRUE" : (LPARAM)L"FALSE");
		
		SetDlgItemInt(hWnd,ID_Size_1, queue1.Size(),0);
		SetDlgItemInt(hWnd, ID_Size_2, queue2.Size(), 0);
		SetDlgItemInt(hWnd, ID_Capacity_1, queue1.Capacity(), 0);
		SetDlgItemInt(hWnd, ID_Capacity_2, queue2.Capacity(), 0);
		
		try
		{
			if (queue1.isEmpty())
			{

				throw - 1;
			}
			SetDlgItemInt(hWnd, ID_Front_1, queue1.Front(), 0);
			SetDlgItemInt(hWnd, ID_Back_1, queue1.Back(), 0);			


		}
		catch (int i)
		{
			MessageBox(hWnd, L"Access Error Exists", L"Error", 0);
		}
		try
		{
			if (queue2.isEmpty())
			{
				
				throw -1;
			}
			
			
			SetDlgItemInt(hWnd, ID_Front_2, queue2.Front(), 0);
			SetDlgItemInt(hWnd, ID_Back_2, queue2.Back(), 0);
			
			
		}
		catch (int i)
		{
			MessageBox(hWnd, L"Access Error Exists",L"Error",0);
		}
	}
	break;

	case WM_CLOSE:
	{

		EndDialog(hWnd, 0);
	}
	return TRUE;

	}
	return (INT_PTR)FALSE;
}
static void OnInitialize()
{
	SetDialogProperties();
	InitializeTabControl();
	InitializeControls();
	InitializeSomething();
	TabControl.UpdateTabLayout(0);
	InitializeQueue();
}
static void SetDialogProperties()
{
	_dialog.SetSize(DialogWidth, DialogHeight);
	
}
static void InitializeTabControl()
{
	TabControl = _dialog.CreateControl(WC_TABCONTROL, NULL, 10, 10, DialogWidth - 40, DialogHeight - 60, ControlID::TabControlID);
	TabControl.AddTabControlItem(L"Create Queue");
	TabControl.AddTabControlItem(L"Status ");
	TabControl.AddTabControlItem(L"Operators");
}
static void InitializeControls()
{

    ThirdQueue = _dialog.CreateControl(WC_LISTBOX, LBS_NOTIFY, 500, 80, 100, DialogHeight - 120, ControlID::ThirdQueue);
	FirstQueue = _dialog.CreateControl(WC_LISTBOX, LBS_NOTIFY, 80, 80, 100, DialogHeight - 120, ControlID::FirstQueue);
	SecondQueue = _dialog.CreateControl(WC_LISTBOX, LBS_NOTIFY, 220, 80, 100, DialogHeight - 120, ControlID::SecondQueue);

	Push = GetControl(ControlID::ID_Push);
	Pop = GetControl(ControlID::ID_Pop);
	Clear = GetControl(ControlID::ID_Clear);
	Swap = GetControl(ControlID::ID_Swap);
	Resize = GetControl(ID_Resize);
	Q1Q2 = GetControl(ID_Q1_Plus_Q2);
	Q2Q1 = GetControl(ID_Q2_Plus_Q1);	
	ResizeProcess = GetControl(ID_ResizeProcess);
	PushProcess = GetControl(ID_PushProcess);
	ConfirmQ1 = GetControl(ID_Queue_1);
	ConfirmQ2 = GetControl(ID_Queue_2);
	StatusDlg = GetControl(ID_ClickStatus);

	TabControl.RegisterControl(2, ThirdQueue);
	TabControl.RegisterControl(2, Q2Q1);
	TabControl.RegisterControl(2, Q1Q2);
	TabControl.RegisterControl(2, GetControl(ID_Plus));
	TabControl.RegisterControl(2, GetControl(ID_Q3_Static));
	TabControl.RegisterControl(2, GetControl(ID_PlusEqual));
	TabControl.RegisterControl(1, StatusDlg);
	TabControl.RegisterControl(0, Push);
	TabControl.RegisterControl(0, Pop);
	TabControl.RegisterControl(0, Swap);
	TabControl.RegisterControl(0, Clear);
	TabControl.RegisterControl(0, Resize);	
	TabControl.RegisterControl(0, ConfirmQ1);
	TabControl.RegisterControl(0, ConfirmQ2);
	TabControl.RegisterControl(0, ResizeProcess);
	TabControl.RegisterControl(0, AppendProcess);
	TabControl.RegisterControl(0, PushProcess);
	TabControl.RegisterControl(0, PopProcess);
	TabControl.RegisterControl(0, NameStatic);
	

}
static void InitializeSomething()
{
	BG = CreateSolidBrush(RGB(250, 20, 147));
	SetClassLong(_dialog, GCL_HBRBACKGROUND, (LONG)BG);
	queue1.Resize(15);
	queue2.Resize(15);
}
HWND GetControl(int id)
{
	return GetDlgItem(_dialog, id);
}
HWND GetControlQ(int id,HWND hWnd)
{
	return GetDlgItem(hWnd, id);
}
static void OnCommand(WPARAM wParam)
{
	auto controlID = LOWORD(wParam);
	auto notificationID = HIWORD(wParam);

	switch (controlID)
	{
	
	
	case ID_Q1_Plus_Q2:
	{
		Q1PlusQ2 = true;
		break;
	}
	case ID_Q2_Plus_Q1:
	{
		Q1PlusQ2 = false;
		break;
	}
	case ID_PlusEqual:
	{
		Q1PlusQ2 ? queue1 += queue2 : queue2 += queue1;
		InitializeQueue();
		
		break;
	}
	case ID_Plus:
	{

		SendMessage(ThirdQueue, LB_RESETCONTENT, 0, 0);
		
		KQueue<int> queue3 = Q1PlusQ2 ? queue1 + queue2 : queue2 + queue1;
		KQueue<int>::iterator iter = queue3.begin();
		for (; iter != queue3.end(); ++iter)
		{
			SendMessage(ThirdQueue, LB_ADDSTRING, 0, (LPARAM)to_wstring(*iter).c_str());
		}
		break;
	}
	case ID_Queue_1:
		IsQueue1 = true;
		break;
	case ID_Queue_2:
		IsQueue1 = false;
		break;
	case ID_Resize :
	{
		OnResize();
		break;
	}
	case ControlID::ID_Clear:

		SendMessage(IsQueue1?FirstQueue:SecondQueue, LB_RESETCONTENT, 0, 0);
		IsQueue1 ? queue1.Clear() : queue2.Clear();
		break;
	case ControlID::ID_Pop:
		try
		{
			OnPop();
		}
		catch (exception e)
		{
			MessageBox(_dialog, (LPCWSTR)e.what(), L"Exception caught", 0);
		}
		break;
	
	case ControlID::ID_Push:
	{
		OnPush();
		break;
	}
	

	case ControlID::ID_Swap:
	{
		queue1.Swap(queue2);
		SendMessage(IsQueue1 ? FirstQueue : SecondQueue, LB_RESETCONTENT, 0, 0);
		SendMessage(!IsQueue1 ? FirstQueue : SecondQueue, LB_RESETCONTENT, 0, 0);
		InitializeQueue();
		break;
	}

	case ID_ClickStatus:
	{
		
		DialogBox(_hInstance, MAKEINTRESOURCE(ID_StatusDialog), _dialog, StatusProc);
		break;
	}
	}
	
}
static void OnPush()
{
	BOOL uVal;
	auto item = GetDlgItemInt(_dialog, ID_PushProcess, &uVal, true);
	if (IsQueue1)
	{
		if (queue1.Size() != MAX_SIZE)
		{
			queue1.Push(item);
			InitializeQueue();
		}

		else
			MessageBox(_dialog, L"Queue is full ", L"Queue #1", 0);
		
	}
	else
	{
		if (queue2.Size() != MAX_SIZE)
		{
			queue2.Push(item);
			InitializeQueue();			
		}

		else
			MessageBox(_dialog, L"Queue is full ", L"Queue #2", 0);
		}

	
	
}
static void InitializeQueue()
{
	
	SendMessage(FirstQueue, LB_RESETCONTENT, 0, 0);
	SendMessage(SecondQueue, LB_RESETCONTENT, 0, 0);
		KQueue<int>::iterator iter;
		for (iter = queue1.begin(); iter != queue1.end(); ++iter)
		{
			auto item = to_wstring(*iter);
			SendMessage(FirstQueue, LB_ADDSTRING, NULL, (LPARAM)item.c_str());
		}
		for (iter = queue2.begin(); iter != queue2.end(); ++iter)
		{
			auto item = to_wstring(*iter);
			SendMessage(SecondQueue, LB_ADDSTRING, NULL, (LPARAM)item.c_str());
		}

		
	
}
static void OnPop()
{
	if (IsQueue1&&queue1.isEmpty() == false)
	{
		SendMessage(FirstQueue, LB_DELETESTRING, 0, 0);
		queue1.Pop();
	}
	else
	{
		if (!IsQueue1&&queue2.isEmpty() == false)
		{
			SendMessage(SecondQueue, LB_DELETESTRING, 0, 0);
			queue2.Pop();

		}
	}
}
void OnResize()
{
	BOOL lp;
	int size = GetDlgItemInt(_dialog, ID_ResizeProcess, &lp, 1);
	if (size <= MAX_SIZE)
	{
		IsQueue1 ? queue1.Resize(size) : queue2.Resize(size);
		InitializeQueue();
		wstring str = L"Resised to " + to_wstring(size);
		MessageBox(_dialog, (LPCWSTR)str.c_str(), IsQueue1 ? L"Queue #1" : L"Queue #2", 0);
	}
	else MessageBox(_dialog, L"Incorrect value", L"Error", ERROR);
}