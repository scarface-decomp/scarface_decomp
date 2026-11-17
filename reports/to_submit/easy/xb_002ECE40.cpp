// bin: xb
// va: 0x002ECE40
// tool: the portal's starter code (no AI)
// sub_002ECE40 (0x002ECE40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004C0660;
extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_002EEB60(void);
extern "C" void __cdecl sub_002EFF00(void);
extern "C" void __cdecl sub_002F6560(void);

void __cdecl sub_002ECE40(void)
{
    int t4;

    sub_002EEB60();
    sub_002EFF00();
    sub_002F6560();
    t4 = DAT_004C0660;
    if (DAT_004C0660) {
        sub_00027600(t4);
    }
}
