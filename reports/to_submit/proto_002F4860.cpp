// bin: proto
// va: 0x002F4860
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F4860 (Proto 0x002F4860, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00460238;
extern "C" int DAT_0046023C;
extern "C" int __cdecl sub_00201990(int, int);

int __cdecl sub_002F4860(void)
{
    int r_eax;

    r_eax = DAT_00460238;
    DAT_0046023C = r_eax;
    if (r_eax) {
        r_eax = sub_00201990(14, r_eax);
    }
    return r_eax;
}
