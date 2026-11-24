// bin: proto
// va: 0x002F2CF0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2CF0 (Proto 0x002F2CF0, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045C370;
extern "C" int DAT_0045C374;
extern "C" int DAT_0045C380;
extern "C" int DAT_0045C384;
extern "C" int DAT_0045C390;
extern "C" int DAT_0045C394;
extern "C" void __cdecl sub_00025160(int);

void __cdecl sub_002F2CF0(void)
{
    int t1, t3, t5;

    t1 = DAT_0045C390;
    DAT_0045C394 = DAT_0045C390;
    if (DAT_0045C390) {
        sub_00025160(t1);
    }
    t3 = DAT_0045C380;
    DAT_0045C384 = DAT_0045C380;
    if (DAT_0045C380) {
        sub_00025160(t3);
    }
    t5 = DAT_0045C370;
    DAT_0045C374 = DAT_0045C370;
    if (DAT_0045C370) {
        sub_00025160(t5);
    }
}
