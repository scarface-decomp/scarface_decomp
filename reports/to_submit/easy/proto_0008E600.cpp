// bin: proto
// va: 0x0008E600
// tool: the portal's starter code (no AI)
// sub_0008E600 (0x0008E600, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CFE0[];
extern "C" char DAT_0037D8E8[];
extern "C" char DAT_00383E04[];
extern "C" int __cdecl sub_002CB041(int, int);

bool __cdecl sub_0008E600(int a1)
{
    if (a1) {
        if (!*(unsigned char*)a1) goto L_48;
        if (!sub_002CB041(a1, (int)DAT_0037D8E8)) goto L_48;
        if (!sub_002CB041(a1, (int)DAT_0037CFE0)) goto L_48;
        if (!sub_002CB041(a1, (int)DAT_00383E04)) goto L_48;
        return true;
    }
L_48:
    return false;
}
