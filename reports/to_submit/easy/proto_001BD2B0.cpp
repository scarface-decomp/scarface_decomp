// bin: proto
// va: 0x001BD2B0
// tool: the portal's starter code (no AI)
// sub_001BD2B0 (0x001BD2B0, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F4D64[];
extern "C" char DAT_003F4DA4[];
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

bool __cdecl sub_001BD2B0(int a1)
{
    if (a1) {
        return sub_002C92F8(a1, 0, (int)DAT_003F4DA4, (int)DAT_003F4D64, 0) != 0;
    }
    return false;
}
