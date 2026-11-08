/*
 * 32-Bit x86 Compiler Proof for `AIAction` & MSVC 7.10 RTTI/CRT (`Custom_AIAction_WorkPack.txt`)
 * Compiled with `g++ -m32 -fno-pic -msse2 -nostdinc -O2 -Wall -Wextra -Werror`
 */
#define SCARFACE_FREESTANDING_X86_CHECK 1
#include "AIAction.h"

int VerifyAIActionLayoutX86() {
    if (sizeof(AIAction)                      != 0x04) return -1;
    if (sizeof(AIActionUnary)                 != 0x08) return -2;
    if (sizeof(_PMD)                          != 0x0C) return -3;
    if (sizeof(type_info_raw)                 != 0x0C) return -4;
    if (sizeof(_RTTIBaseClassDescriptor)      != 0x18) return -5;
    if (sizeof(_RTTIClassHierarchyDescriptor) != 0x10) return -6;
    if (sizeof(_RTTICompleteObjectLocator)    != 0x14) return -7;
    if (sizeof(_iobuf_xbox)                   != 0x20) return -8;
    if (sizeof(_ioinfo_xbox)                  != 0x28) return -9;
    if (sizeof(_tiddata_xbox)                 != 0x88) return -10;
    if (sizeof(exception_xbox)                != 0x0C) return -11;
    return VerifyAIActionAndRTTIOffsetsX86();
}
