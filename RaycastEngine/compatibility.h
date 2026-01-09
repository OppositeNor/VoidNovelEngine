#pragma once

#if defined(_WIN32)
// Windows compatibility

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

/**
 * @brief Show/hide a console.
 *
 * @param flag True to show the console, false otherwise.
 */
inline void show_console(bool flag) {
    ShowWindow(GetConsoleWindow(), flag ? SW_SHOW : SW_HIDE);
}

#elif defined(__linux)
// Linux compatibility
inline void show_console(bool) {
    // Do nothing.
}


#endif
