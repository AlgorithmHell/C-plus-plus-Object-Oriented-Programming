#pragma once
#include "Dialog.h"
#include <map>
#include <algorithm>
#include <CommCtrl.h>
using namespace std;

class TABCONTROL
{
private:
	HWND TabControl;
	multimap <int, HWND> Controls;
	TCITEM CreateTabControlItem(wchar_t* text);
public:
	TABCONTROL(HWND handle);
	void AddTabControlItem(wchar_t*text);
	BOOL TryProcessMessage(UINT message, WPARAM wParam, LPARAM lParam);
	void UpdateTabLayout(int currentIndex);
	void RegisterControl(int TabIndex, HWND Control);
	operator HWND__*() const
	{
		return TabControl;
	}
	TABCONTROL& operator=(HWND&handle)
	{
		TabControl = handle;
		return *this;
	}
};

