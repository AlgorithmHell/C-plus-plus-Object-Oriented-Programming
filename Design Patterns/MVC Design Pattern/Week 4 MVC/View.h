#pragma once


#include <Windows.h>
#include "TabControl.h"
#include "Dialog.h"
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
class View
{
private:
	static HWND Tab;
	static int DialogWidth;
	static int DialogHeight;
	static HWND GetControl(int id)
	{
		return GetDlgItem(_dialog, id);
	}
public:
	static HINSTANCE _hInstance;
	static Dialog _dialog;
	static TABCONTROL TabControl;
	
	static HWND FirstQueue;
	static HWND SecondQueue;
	static HWND ThirdQueue;
	static HWND StatusDlg;
	
	View(int Width=800,int Height=500)
	{
		DialogWidth = Width;
		DialogHeight = Height;
		TabControl = Tab;
	}
	static void SetWindowProperties(int width, int height)
	{
		DialogWidth = width;
		DialogHeight = height;
		_dialog.SetSize(DialogWidth, DialogHeight);
	}
	static void InitInstance(HINSTANCE&H)
	{
		_hInstance = H;
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


		StatusDlg = GetControl(ID_ClickStatus);
		TabControl.RegisterControl(2, ThirdQueue);
		TabControl.RegisterControl(2, GetControl(ID_Q2_Plus_Q1));
		TabControl.RegisterControl(2, GetControl(ID_Q1_Plus_Q2));
		TabControl.RegisterControl(2, GetControl(ID_Plus));
		TabControl.RegisterControl(2, GetControl(ID_Q3_Static));
		TabControl.RegisterControl(2, GetControl(ID_PlusEqual));
		TabControl.RegisterControl(1, StatusDlg);
		TabControl.RegisterControl(0, GetControl(ControlID::ID_Push));
		TabControl.RegisterControl(0, GetControl(ControlID::ID_Pop));
		TabControl.RegisterControl(0, GetControl(ControlID::ID_Swap));
		TabControl.RegisterControl(0, GetControl(ControlID::ID_Clear));
		TabControl.RegisterControl(0, GetControl(ID_Resize));
		TabControl.RegisterControl(0, GetControl(ID_Queue_1));
		TabControl.RegisterControl(0, GetControl(ID_Queue_2));
		TabControl.RegisterControl(0, GetControl(ID_ResizeProcess));
		TabControl.RegisterControl(0, GetControl(ID_PushProcess));



	}
	
};