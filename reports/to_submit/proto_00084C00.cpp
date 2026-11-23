// bin: proto
// va: 0x00084C00
// what: 
// tool: the portal's starter code (no AI)

// sub_00084C00 (Proto 0x00084C00, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_003F6270;
extern "C" int DAT_00453C5C;
extern "C" int __cdecl sub_00025140(int, int);

void __cdecl sub_00084C00(void)
{
    if (!DAT_00453C5C) {
        DAT_003F6270 = false;
        DAT_00453C5C = sub_00025140(256, 0);
        DAT_003F6270 = true;
    }
}
