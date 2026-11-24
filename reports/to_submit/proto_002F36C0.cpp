// bin: proto
// va: 0x002F36C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F36C0 (Proto 0x002F36C0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045ED74;
extern "C" int DAT_0045ED78;
extern "C" int __cdecl sub_00201990(int, int);

int __cdecl sub_002F36C0(void)
{
    int r_eax;

    r_eax = DAT_0045ED74;
    DAT_0045ED78 = r_eax;
    if (r_eax) {
        r_eax = sub_00201990(7, r_eax);
    }
    return r_eax;
}
