// bin: xb
// va: 0x00099BC0
// tool: the portal's starter code (no AI)
// sub_00099BC0 (0x00099BC0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D810[];
extern "C" char DAT_0039E2B8[];
extern "C" char DAT_003A48B0[];
extern "C" int __cdecl sub_002FDD41(int, int);

bool __cdecl sub_00099BC0(int a1)
{
    if (a1) {
        if (!*(unsigned char*)a1) goto L_48;
        if (!sub_002FDD41(a1, (int)DAT_0039E2B8)) goto L_48;
        if (!sub_002FDD41(a1, (int)DAT_0039D810)) goto L_48;
        if (!sub_002FDD41(a1, (int)DAT_003A48B0)) goto L_48;
        return true;
    }
L_48:
    return false;
}
