// bin: xb
// va: 0x00316250
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316250 (0x00316250, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EBB0(int);
};

extern "C" char DAT_003A8E54[];
extern "C" char DAT_003A8EC0[];
extern "C" int DAT_00487934;
extern "C" int DAT_0048793C;
extern "C" char sub_000EA2F0[];
extern "C" char sub_003232D0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00316250(void)
{
    ((Object*)(int)&DAT_00487934)->sub_0023EBB0((int)DAT_003A8EC0);
    DAT_00487934 = (int)DAT_003A8E54;
    DAT_0048793C = (int)sub_000EA2F0;
    sub_002FBBEF((int)sub_003232D0);
}
