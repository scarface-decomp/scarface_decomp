// bin: xb
// va: 0x0012DF30
// tool: the portal's starter code (no AI)
// sub_0012DF30 (0x0012DF30, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048A010;
extern "C" int DAT_0048A018;
extern "C" float DAT_0048A01C;

int __stdcall sub_0012DF30(float a1)
{
    int t1;

    t1 = DAT_0048A010;
    *(int*)(((int)&DAT_0048A018) + (DAT_0048A010 * 8)) = 2;
    *(float*)(((int)&DAT_0048A01C) + (t1 * 8)) = a1;
    DAT_0048A010 = t1 + 1;
    return t1 + 1;
}
