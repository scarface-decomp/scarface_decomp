// bin: proto
// va: 0x002F1C50
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1C50 (Proto 0x002F1C50, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403D18;
extern "C" int DAT_00403D1C;
extern "C" unsigned short DAT_00403D24;
extern "C" unsigned short DAT_00403D26;
extern "C" unsigned short DAT_00403D2A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1C50(void)
{
    DAT_00403D18 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403D1C);
    DAT_00403D1C = 0;
    DAT_00403D24 = 0;
    DAT_00403D26 = 0;
    DAT_00403D2A = 0;
    return 0;
}
