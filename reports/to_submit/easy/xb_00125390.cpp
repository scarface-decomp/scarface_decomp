// bin: xb
// va: 0x00125390
// tool: the portal's starter code (no AI)
// sub_00125390 (0x00125390, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00125150();
};

extern "C" Object DAT_00489D9C;
extern "C" bool DAT_00489DAC;
extern "C" char sub_00324340[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00125390(void)
{
    if (!(1 & DAT_00489DAC)) {
        *(int*)&DAT_00489DAC = *(int*)&DAT_00489DAC | 1;
        DAT_00489D9C.sub_00125150();
        sub_002FBBEF((int)sub_00324340);
    }
}
