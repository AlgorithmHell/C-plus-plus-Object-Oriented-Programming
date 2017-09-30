#include "TabControl.h"

using namespace std;

TABCONTROL::TABCONTROL(HWND handle) : TabControl(handle)
{

}

void TABCONTROL::AddTabControlItem(wchar_t * text)
{

	auto tabControlItem = CreateTabControlItem(text);
	auto newTabIndex = TabCtrl_GetItemCount(TabControl);
	TabCtrl_InsertItem(TabControl, newTabIndex, &tabControlItem);

}
TCITEM TABCONTROL::CreateTabControlItem(wchar_t* text)
{
	TCITEM tabControlItem;
	tabControlItem.mask = TCIF_TEXT;
	tabControlItem.pszText = text;
	return tabControlItem;
}

BOOL TABCONTROL::TryProcessMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_NOTIFY)
	{

		auto notificationMessageHandler = (NMHDR*)lParam;
		if (notificationMessageHandler->hwndFrom != TabControl) return FALSE;

		switch (notificationMessageHandler->code)
		{
		case TCN_SELCHANGE:
		{
			auto tabIndex = TabCtrl_GetCurSel((HWND)TabControl);
			UpdateTabLayout(tabIndex);
			return TRUE;
		}
		}

		return FALSE;

	}
	else return FALSE;
}

void TABCONTROL::UpdateTabLayout(int currentIndex)
{
	auto low = Controls.lower_bound(currentIndex);
	auto high = Controls.upper_bound(currentIndex);

	for (auto it = Controls.begin(); it != low; ++it)
	{
		ShowWindow(it->second, SW_HIDE);
	}
	for (auto it = low; it != high; ++it)
	{
		ShowWindow(it->second, SW_SHOW);
	}
	for (auto it = high; it != Controls.end(); ++it)
	{
		ShowWindow(it->second, SW_HIDE);
	}
}

void TABCONTROL::RegisterControl(int TabIndex, HWND Control)
{
	Controls.insert(make_pair(TabIndex, Control));
}
