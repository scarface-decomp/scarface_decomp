// bin: proto
// va: 0x002E8AF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8AF0 (Proto 0x002E8AF0, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0048[];
extern "C" char DAT_003A0058[];
extern "C" char DAT_003A0068[];
extern "C" char DAT_003A0078[];
extern "C" char DAT_003A0088[];
extern "C" int DAT_00460264;
extern "C" int DAT_00460268;
extern "C" int DAT_0046026C;
extern "C" int DAT_00460270;
extern "C" int DAT_00460274;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E8AF0(void)
{
    DAT_00460264 = sub_00201440((int)DAT_003A0088, 0);
    DAT_00460268 = sub_00201440((int)DAT_003A0078, 0);
    DAT_0046026C = sub_00201440((int)DAT_003A0068, 0);
    DAT_00460270 = sub_00201440((int)DAT_003A0058, 0);
    DAT_00460274 = sub_00201440((int)DAT_003A0048, 0);
}
