// bin: xb
// va: 0x00316150
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316150 (0x00316150, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023ED00(int);
};

extern "C" char DAT_003A8D2C[];
extern "C" char DAT_003A8D58[];
extern "C" char DAT_004271A0[];
extern "C" int DAT_004878F4;
extern "C" int DAT_004878FC;
extern "C" int DAT_00487900;
extern "C" int DAT_00487904;
extern "C" char sub_000E8090[];
extern "C" char sub_00323270[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00316150(void)
{
    ((Object*)(int)&DAT_004878F4)->sub_0023ED00((int)DAT_003A8D58);
    DAT_004878F4 = (int)DAT_003A8D2C;
    DAT_004878FC = (int)DAT_004271A0;
    DAT_00487900 = 4;
    DAT_00487904 = (int)sub_000E8090;
    sub_002FBBEF((int)sub_00323270);
}
