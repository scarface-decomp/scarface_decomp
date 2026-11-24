// bin: proto
// va: 0x002F1CD0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1CD0 (Proto 0x002F1CD0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00403D70;
extern "C" int DAT_00403D74;
extern "C" unsigned short DAT_00403D7C;
extern "C" unsigned short DAT_00403D7E;
extern "C" unsigned short DAT_00403D82;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1CD0(void)
{
    DAT_00403D70 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00403D74);
    DAT_00403D74 = 0;
    DAT_00403D7C = 0;
    DAT_00403D7E = 0;
    DAT_00403D82 = 0;
    return 0;
}
