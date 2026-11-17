// bin: proto
// va: 0x002BA610
// tool: the portal's starter code (no AI)
// sub_002BA610 (0x002BA610, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004916F0;
extern "C" void __cdecl sub_00025160(int);
extern "C" void __cdecl sub_002BC300(void);
extern "C" void __cdecl sub_002BD650(void);
extern "C" void __cdecl sub_002C3C80(void);

void __cdecl sub_002BA610(void)
{
    int t4;

    sub_002BC300();
    sub_002BD650();
    sub_002C3C80();
    t4 = DAT_004916F0;
    if (DAT_004916F0) {
        sub_00025160(t4);
    }
}
