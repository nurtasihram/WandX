#pragma once

#ifndef WANDX_CPPM_EXPORT_NATIVE
import WandX.Win32.Dialogs;
#endif

#include "Win32.Window.h"

#define SFINAE_Dialog(name) friend class WandX::DialogBase<name>; friend class WandX::WindowBase<name>
#define BaseOf_Dialog(name) name : public WandX::DialogBase<name>
