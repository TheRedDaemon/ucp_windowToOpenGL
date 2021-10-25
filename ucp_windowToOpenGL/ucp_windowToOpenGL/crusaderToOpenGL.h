
#pragma once

// includes that are always used with this
#include "fakeDDClasses.h"

namespace UCPtoOpenGL
{
  // forward declared
  struct SHCWindowOrMainStructFake;
  class WindowCore;

  class CrusaderToOpenGL : public FakeDirectDraw
  {
  public:
    CrusaderToOpenGL(ToOpenGLConfig& conf);
    virtual ~CrusaderToOpenGL();

    /*** need impl ***/

    STDMETHOD(EnumDisplayModes)(THIS_ DWORD dw, LPDDSURFACEDESC lpsurf, LPVOID lpvoid, LPDDENUMMODESCALLBACK callback);
    STDMETHOD(GetCaps)(THIS_ LPDDCAPS cap1, LPDDCAPS cap2);
    STDMETHOD(CreateSurface)(THIS_  LPDDSURFACEDESC, LPDIRECTDRAWSURFACE FAR*, IUnknown FAR*);
    STDMETHOD(SetDisplayMode)(THIS_ DWORD, DWORD, DWORD);


    /* copied structure end */

    // that -> the stronghold object(whatever it is)
     void __thiscall createWindow(WNDPROC windowCallbackFunc, SHCWindowOrMainStructFake* that,
      HINSTANCE hInstance, LPSTR windowName, unsigned int cursorResource);

    HRESULT createDirectDraw(GUID* lpGUID, LPDIRECTDRAW* lplpDD, IUnknown* pUnkOuter);

    int getFakeSystemMetrics(int nIndex);

    BOOL getWindowCursorPos(LPPOINT lpPoint);

    BOOL setWindowPosFake(HWND, HWND, int, int, int, int, UINT);

    BOOL WINAPI updateWindowFake(HWND hWnd);

    BOOL WINAPI adjustWindowRectFake(LPRECT lpRect, DWORD dwStyle, BOOL bMenu);

    LONG WINAPI setWindowLongAFake(HWND hWnd, int nIndex, LONG dwNewLong);

    HWND WINAPI GetForegroundWindowFake();

    // returns 'true' if the mouse action should get transported, 'false' if it should get discarded
    bool transformMouseMovePos(LPARAM* ptrlParam);

    // false, if the message should be devoured
    bool windowLostFocus();

    // false, if the message should be devoured
    bool windowSetFocus();

    // false, if the message should be devoured
    bool windowActivated(bool active);

    void windowDestroyed();

    void windowEditEnded();

    // send if down in the client
    bool mouseDown();

  private:  // functions

     /*** need impl ***/
    virtual HRESULT renderNextFrame(unsigned short* sourcePtr) override;
    virtual int getRenderTexWidth() override;
    virtual int getRenderTexHeight() override;
    virtual PixelFormat getPixelFormat() override;

    // config
    void setWindowStyleAndSize();
    void clipCursor();

  private:  // variables

    // config:
    ToOpenGLConfig& confRef;

    // intern:

    const std::unique_ptr<WindowCore> window;

    // contains data values
    struct
    {
      // flags
      bool            windowDone        { false };      // this might get removed, instead becoming a working or breaking situation
      bool            hasFocus          { true };       // should have focus at start
      bool            devourAfterFocus  { false };      // only window continue without render, after the foucs is regained, it requires a first click to get the input again
      bool            cursorClipped     { false };      // only for window mode

      // sizes
      Size<int>       windowSize        { 1280, 720 };  // ignores border etc.
      Size<int>       windowOffset      { 0, 0 };
      Size<int>       gameWindowRange   { 1279, 719 };  // window size - 1, because range
      Size<int>       gameTexSize       { 0, 0 };
      Size<int>       scrollRange       { 1279, 719 };  // game size - 1, because scroll max
      Size<double>    winToGamePos      { 1.0, 1.0 };   // used for positions, since they range from 0 to width - 1 and need handling for both axes
    } d;  // data

    SHCWindowOrMainStructFake* shcWinStrucPtr{ nullptr };
  };
}