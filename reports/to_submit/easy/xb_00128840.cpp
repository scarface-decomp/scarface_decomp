// bin: xb
// va: 0x00128840
// tool: the portal's starter code (no AI)
// sub_00128840 (0x00128840, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00241E00();
};

extern "C" Object DAT_00489EF4;
extern "C" int DAT_00489F10;
extern "C" bool DAT_00489F14;
extern "C" char sub_00324380[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00128840(void)
{
    if (!(1 & DAT_00489F14)) {
        *(int*)&DAT_00489F14 = *(int*)&DAT_00489F14 | 1;
        DAT_00489EF4.sub_00241E00();
        DAT_00489F10 = 32;
        sub_002FBBEF((int)sub_00324380);
    }
}
