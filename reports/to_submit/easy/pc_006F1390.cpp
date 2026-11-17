// bin: pc
// va: 0x006F1390
// tool: the portal's starter code (no AI)
// sub_006F1390 (0x006F1390, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool DAT_007F6BD4;

bool __cdecl sub_006F1390(int a1)
{
    return *(bool*)(((int)&DAT_007F6BD4) + ((a1 + (a1 * 2)) * 8));
}
