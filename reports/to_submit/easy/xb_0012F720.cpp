// bin: xb
// va: 0x0012F720
// tool: the portal's starter code (no AI)
// sub_0012F720 (0x0012F720, 77 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0042C258;
extern "C" int DAT_0042C25C;
extern "C" int DAT_0048A098;
extern "C" int DAT_0048A09C;
extern "C" int __cdecl sub_00028860(int, int, int, int, int);

void __cdecl sub_0012F720(void)
{
    if (!DAT_0048A098) {
        DAT_0048A098 = sub_00028860(DAT_0042C25C, 570, 32, 10, 16);
    }
    if (!DAT_0048A09C) {
        DAT_0048A09C = sub_00028860(DAT_0042C258, 32, 64, 10, 16);
    }
}
