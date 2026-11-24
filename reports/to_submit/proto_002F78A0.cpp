// bin: proto
// va: 0x002F78A0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F78A0 (Proto 0x002F78A0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AFF48[];
extern "C" int DAT_0042AD10;
extern "C" int DAT_0042AD18;
extern "C" void __cdecl sub_00025160(int);

void __cdecl sub_002F78A0(void)
{
    int t1;

    t1 = DAT_0042AD18;
    DAT_0042AD10 = (int)DAT_003AFF48;
    if (DAT_0042AD18) {
        sub_00025160(t1);
    }
}
