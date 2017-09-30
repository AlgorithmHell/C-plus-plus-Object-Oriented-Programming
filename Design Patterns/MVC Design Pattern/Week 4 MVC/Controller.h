#pragma once


#include "resource.h"
#include <iostream>



#include <vector>
#include <string>
#include "View.h"
#include "Model.h"



class Controller
{
	static bool IsQueue1;
	static bool Q1PlusQ2;
	static KQueue<int> queue1;
	static KQueue<int> queue2;
	static KQueue<int> queue3;
	static View view;
	static HWND GetControl(int id)
	{
		return GetDlgItem(view._dialog, id);
	}
	static HWND GetControlQ(int id, HWND hWnd)
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

			SendMessage(view.ThirdQueue, LB_RESETCONTENT, 0, 0);

			KQueue<int> queue3 = Q1PlusQ2 ? queue1 + queue2 : queue2 + queue1;
			KQueue<int>::iterator iter = queue3.begin();
			for (; iter != queue3.end(); ++iter)
			{
				SendMessage(view.ThirdQueue, LB_ADDSTRING, 0, (LPARAM)to_wstring(*iter).c_str());
			}
			break;
		}
		case ID_Queue_1:
			IsQueue1 = true;
			break;
		case ID_Queue_2:
			IsQueue1 = false;
			break;
		case ID_Resize:
		{
			OnResize();
			break;
		}
		case ControlID::ID_Clear:

			SendMessage(IsQueue1 ? view.FirstQueue : view.SecondQueue, LB_RESETCONTENT, 0, 0);
			IsQueue1 ? queue1.Clear() : queue2.Clear();
			break;
		case ControlID::ID_Pop:
			try
			{
				OnPop();
			}
			catch (exception e)
			{
				MessageBox(view._dialog, (LPCWSTR)e.what(), L"Exception caught", 0);
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
			SendMessage(IsQueue1 ? view.FirstQueue : view.SecondQueue, LB_RESETCONTENT, 0, 0);
			SendMessage(!IsQueue1 ? view.FirstQueue : view.SecondQueue, LB_RESETCONTENT, 0, 0);
			InitializeQueue();
			break;
		}

		case ID_ClickStatus:
		{

			DialogBox(view._hInstance, MAKEINTRESOURCE(ID_StatusDialog), view._dialog, StatusProc);
			break;
		}
		}

	}
	static void OnInitialize()
	{
		view.InitializeTabControl();
		view.InitializeControls();
		view.SetWindowProperties(800, 500);
		view.TabControl.UpdateTabLayout(0);
		InitializeQueue();
	}
	static void OnPush()
	{
		BOOL uVal;
		auto item = GetDlgItemInt(view._dialog, ID_PushProcess, &uVal, true);
		if (IsQueue1)
		{
			if (queue1.Size() != MAX_SIZE)
			{
				queue1.Push(item);
				InitializeQueue();
			}

			else
				MessageBox(view._dialog, L"Queue is full ", L"Queue #1", 0);

		}
		else
		{
			if (queue2.Size() != MAX_SIZE)
			{
				queue2.Push(item);
				InitializeQueue();
			}

			else
				MessageBox(view._dialog, L"Queue is full ", L"Queue #2", 0);
		}



	}
	static void InitializeQueue()
	{

		SendMessage(view.FirstQueue, LB_RESETCONTENT, 0, 0);
		SendMessage(view.SecondQueue, LB_RESETCONTENT, 0, 0);
		KQueue<int>::iterator iter;
		for (iter = queue1.begin(); iter != queue1.end(); ++iter)
		{
			auto item = to_wstring(*iter);
			SendMessage(view.FirstQueue, LB_ADDSTRING, NULL, (LPARAM)item.c_str());
		}
		for (iter = queue2.begin(); iter != queue2.end(); ++iter)
		{
			auto item = to_wstring(*iter);
			SendMessage(view.SecondQueue, LB_ADDSTRING, NULL, (LPARAM)item.c_str());
		}



	}
	static void OnPop()
	{
		if (IsQueue1&&queue1.isEmpty() == false)
		{
			SendMessage(view.FirstQueue, LB_DELETESTRING, 0, 0);
			queue1.Pop();
		}
		else
		{
			if (!IsQueue1&&queue2.isEmpty() == false)
			{
				SendMessage(view.SecondQueue, LB_DELETESTRING, 0, 0);
				queue2.Pop();

			}
		}
	}
	static void OnResize()
	{
		BOOL lp;
		int size = GetDlgItemInt(view._dialog, ID_ResizeProcess, &lp, 1);
		if (size <= MAX_SIZE)
		{
			IsQueue1 ? queue1.Resize(size) : queue2.Resize(size);
			InitializeQueue();
			wstring str = L"Resised to " + to_wstring(size);
			MessageBox(view._dialog, (LPCWSTR)str.c_str(), IsQueue1 ? L"Queue #1" : L"Queue #2", 0);
		}
		else MessageBox(view._dialog, L"Incorrect value", L"Error", ERROR);
	}
	static INT_PTR CALLBACK StatusProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{

		switch (message)
		{

		case WM_INITDIALOG:
		{
			SendMessage(GetControlQ(ID_Equal, hWnd), WM_SETTEXT, 0, queue1 == queue2 ? (LPARAM)L"TRUE" : (LPARAM)L"FALSE");
			SendMessage(GetControlQ(ID_NotEqual, hWnd), WM_SETTEXT, 0, queue1 != queue2 ? (LPARAM)L"TRUE" : (LPARAM)L"FALSE");
			SendMessage(GetControlQ(ID_IsEmpty_1, hWnd), WM_SETTEXT, 0, queue1.isEmpty() ? (LPARAM)L"TRUE" : (LPARAM)L"FALSE");
			SendMessage(GetControlQ(ID_IsEmpty_2, hWnd), WM_SETTEXT, 0, queue2.isEmpty() ? (LPARAM)L"TRUE" : (LPARAM)L"FALSE");

			SetDlgItemInt(hWnd, ID_Size_1, queue1.Size(), 0);
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

					throw - 1;
				}


				SetDlgItemInt(hWnd, ID_Front_2, queue2.Front(), 0);
				SetDlgItemInt(hWnd, ID_Back_2, queue2.Back(), 0);


			}
			catch (int i)
			{
				MessageBox(hWnd, L"Access Error Exists", L"Error", 0);
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
	static void UpdateIsQueue1(bool value)
	{
		IsQueue1 = value;
	}
	static bool isQueue1()
	{
		return IsQueue1;
	}
	static void UpdateQ1PlusQ2(bool value)
	{
		Q1PlusQ2 = value;
	}
	static bool isQ1PlusQ2()
	{
		return Q1PlusQ2;
	}
	KQueue<int>& GetQueueControl(int NumberOfQueue)
	{
		switch (NumberOfQueue)
		{
		case 1:
			return queue1;
		case 2:
			return queue2;
		case 3:
			return queue3;
		default:
			return KQueue<int>(0);
		}
	}
public:
	Controller(const KQueue<int> &_model1, const KQueue<int> &_model2, const KQueue<int> &_model3, const View &_view)
	{
		queue1 = _model1;
		queue2 = _model2;
		queue3 = _model3;
		view = _view;
		IsQueue1 = false;
		Q1PlusQ2 = false;
	}	
	static INT_PTR CALLBACK DialogProc(HWND hDialog, UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (view.TabControl.TryProcessMessage(message, wParam, lParam)) return TRUE;

		switch (message)
		{


		case WM_INITDIALOG:
			view._dialog.Initialize(hDialog);
			OnInitialize();

			return (INT_PTR)TRUE;

		case WM_CLOSE:
			view._dialog.Destroy();
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
	
	
};