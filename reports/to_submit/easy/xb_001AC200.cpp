// bin: xb
// va: 0x001AC200
// tool: the portal's starter code (no AI)
// sub_001AC200 (0x001AC200, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048CFE0;
extern "C" int DAT_0048CFE4;
extern "C" int DAT_0048CFE8;

void __stdcall sub_001AC200(bool a1)
{
    int t1;

    if (a1) {
        if (DAT_0048CFE4 >= 0x7FFFFFFF) goto L_27;
        t1 = DAT_0048CFE0;
        if (!DAT_0048CFE0) goto L_27;
        ((void (__cdecl*)(int))t1)(DAT_0048CFE8);
    }
L_27:
    ;
}
