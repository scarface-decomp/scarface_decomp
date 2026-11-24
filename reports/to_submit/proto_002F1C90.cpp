// bin: proto
// va: 0x002F1C90
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1C90 (Proto 0x002F1C90, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403D44;
extern "C" int DAT_00403D48;
extern "C" unsigned short DAT_00403D50;
extern "C" unsigned short DAT_00403D52;
extern "C" unsigned short DAT_00403D56;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1C90(void)
{
    DAT_00403D44 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403D48);
    DAT_00403D48 = 0;
    DAT_00403D50 = 0;
    DAT_00403D52 = 0;
    DAT_00403D56 = 0;
    return 0;
}
