// bin: proto
// va: 0x001EF040
// what: 
// tool: the portal's starter code (no AI)

// sub_001EF040 (Proto 0x001EF040, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00462ED0;

bool __cdecl sub_001EF040(bool a1)
{
    *(bool*)(DAT_00462ED0 + 28) = a1;
    return a1;
}
