// bin: proto
// va: 0x001EF910
// what: 
// tool: the portal's starter code (no AI)

// sub_001EF910 (Proto 0x001EF910, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004635CC;

int __cdecl sub_001EF910(void)
{
    int t1;

    t1 = DAT_004635CC;
    *(bool*)(DAT_004635CC + 102) = true;
    return t1;
}
