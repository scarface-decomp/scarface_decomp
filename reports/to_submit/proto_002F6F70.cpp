// bin: proto
// va: 0x002F6F70
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6F70 (Proto 0x002F6F70, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00421698;
extern "C" int DAT_0042169C;
extern "C" unsigned short DAT_004216A4;
extern "C" unsigned short DAT_004216A6;
extern "C" unsigned short DAT_004216AA;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6F70(void)
{
    DAT_00421698 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0042169C);
    DAT_0042169C = 0;
    DAT_004216A4 = 0;
    DAT_004216A6 = 0;
    DAT_004216AA = 0;
    return 0;
}
