#pragma once
#include "baseWindow.h"

namespace ooBase
{

	class MainWindow : public ooBase::BaseWindow<ooBase::MainWindow>
	{
	public:
		PCWSTR ClassName() const;
		LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	};

}