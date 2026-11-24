// bin: xb
// va: 0x00315E70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315E70 (0x00315E70, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003A6CC8[];
extern "C" char DAT_003A6EE4[];
extern "C" char DAT_0042505C[];
extern "C" int DAT_0048778C;
extern "C" int DAT_00487794;
extern "C" int DAT_00487798;
extern "C" int DAT_0048779C;
extern "C" char sub_00182910[];
extern "C" char sub_003231B0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00315E70(void)
{
    ((Object*)(int)&DAT_0048778C)->sub_0023ED00((int)DAT_003A6EE4);
    DAT_0048778C = (int)DAT_003A6CC8;
    DAT_00487794 = (int)DAT_0042505C;
    DAT_00487798 = 6;
    DAT_0048779C = (int)sub_00182910;
    sub_002FBBEF((int)sub_003231B0);
}
