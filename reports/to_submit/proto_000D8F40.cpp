// bin: proto
// va: 0x000D8F40
// what: 
// tool: the portal's starter code (no AI)

// sub_000D8F40 (Proto 0x000D8F40, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;

int __cdecl sub_000D8F40(void)
{
    int t1;

    t1 = DAT_0045A0EC;
    *(bool*)(DAT_0045A0EC + 133) = !*(bool*)(DAT_0045A0EC + 133);
    return t1;
}
