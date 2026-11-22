// bin: proto
// va: 0x00021A00
// what: 
// tool: the portal's starter code (no AI)

// sub_00021A00 (Proto 0x00021A00, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_003F56B8;
extern "C" bool DAT_003F56B9;
extern "C" int DAT_003F56BC;

void __cdecl sub_00021A00(bool a1, bool a2)
{
    DAT_003F56BC = 1;
    if ((unsigned int)a2 < (unsigned int)255) {
        DAT_003F56B8 = a2;
        DAT_003F56B9 = a1;
        return;
    }
    DAT_003F56B9 = a1;
}
