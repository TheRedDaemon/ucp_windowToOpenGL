// pch.h: Dies ist eine vorkompilierte Headerdatei.
// Die unten aufgeführten Dateien werden nur einmal kompiliert, um die Buildleistung für zukünftige Builds zu verbessern.
// Dies wirkt sich auch auf die IntelliSense-Leistung aus, Codevervollständigung und viele Features zum Durchsuchen von Code eingeschlossen.
// Die hier aufgeführten Dateien werden jedoch ALLE neu kompiliert, wenn mindestens eine davon zwischen den Builds aktualisiert wird.
// Fügen Sie hier keine Dateien hinzu, die häufig aktualisiert werden sollen, da sich so der Leistungsvorteil ins Gegenteil verkehrt.

#ifndef PCH_H
#define PCH_H

// Fügen Sie hier Header hinzu, die vorkompiliert werden sollen.
#include "framework.h"

// openGL
#include "gl/gl.h"
#include "gl/glext.h"
#include "gl/wglext.h" // needed for windows OpenGL

// for ptr
#include <memory>

#include "ddraw.h"

// config is needed everywhere
#include "toOpenGLconfig.h"

// for structures
#include <array>

// one can always use a string
#include <string>

// adding simple Size template

// w and x, and h and y are the same values (unions)
template <typename T>
struct Size
{
  union
  {
    T w;  // width
    T x;
  };
  union
  {
    T h;  // height
    T y;
  };
};

#endif //PCH_H
