#pragma once

namespace UCPtoOpenGL
{
  DWORD GetWindowStyle(WindowType type);

  DWORD GetExtendedWindowStyle(WindowType type);

  RECT GetWindowRect(WindowConfig& winConf);

  int GetGameWidth(WindowConfig& winConf);
  int GetGameHeight(WindowConfig& winConf);
}