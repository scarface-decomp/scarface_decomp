// bin: proto
// va: 0x001897B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001897B0 (Proto 0x001897B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00188900(void);
extern "C" int __cdecl sub_001895A0(void);

int __stdcall sub_001897B0(int a1)
{
    int r_eax;

    r_eax = a1;
    if (a1) {
        if (a1 != 4) goto L_1A;
        r_eax = sub_00188900();
        return r_eax;
    }
    r_eax = sub_001895A0();
L_1A:
    return r_eax;
}
