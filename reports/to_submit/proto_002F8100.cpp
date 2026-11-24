// bin: proto
// va: 0x002F8100
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F8100 (Proto 0x002F8100, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004916AC;
extern "C" int DAT_004916B0;
extern "C" int DAT_004916B8;
extern "C" int DAT_004916D4;
extern "C" int __cdecl sub_00025160(int);
extern "C" void __cdecl sub_002BD460(int, int);

int __cdecl sub_002F8100(void)
{
    int r_eax;

    r_eax = DAT_004916D4;
    if (r_eax) {
        sub_00025160(r_eax);
    }
    r_eax = DAT_004916B8;
    if (r_eax) {
        sub_00025160(r_eax);
    }
    r_eax = DAT_004916AC;
    if (r_eax) {
        sub_002BD460(r_eax, DAT_004916B0);
        r_eax = sub_00025160(DAT_004916AC);
    }
    return r_eax;
}
