// bin: xb
// va: 0x00231160
// what: 
// tool: the portal's starter code (no AI)

// sub_00231160 (0x00231160, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004879E8;
extern "C" bool DAT_004928F8;
extern "C" int DAT_004928FC;

bool __cdecl sub_00231160(void)
{
    if (!DAT_004928F8) {
        if (*(unsigned char*)(DAT_004879E8 + 68) & 16) goto L_27;
        if (*(bool*)(DAT_004928FC + 144)) goto L_27;
        return false;
    }
L_27:
    return true;
}
