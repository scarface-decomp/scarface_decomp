// bin: xb
// va: 0x0022D980
// what: 
// tool: the portal's starter code (no AI)

// sub_0022D980 (0x0022D980, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0049201C;
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_0022D980(int a1, int a2, int a3)
{
    int t1, t2;

    t1 = DAT_0049201C;
    t2 = sub_002FC43E(*(int*)(a3 + 4));
    if (t2 != *(int*)(t1 + 68)) {
        if (t2 > 4) goto L_26;
        *(int*)(t1 + 72) = t2;
    }
L_26:
    ;
}
