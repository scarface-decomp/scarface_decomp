// bin: xb
// va: 0x0006F9C0
// what: Formats a debug message into a local buffer; this build prints it nowhere.
// tool: Claude Opus 5.5 (symcov hint: _SNDAPP_DebugPrint)
// sub_0006F9C0 (0x0006F9C0, 36 bytes)

#include <stdarg.h>

extern "C" int __cdecl vsprintf(char *buffer, const char *format, va_list args);

// Formats the message; the output step is compiled out of the retail build.
void __cdecl sub_0006F9C0(const char *format, ...)
{
    char buffer[1024];
    va_list args;

    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
}
