// bin: xb
// va: 0x001BF100
// what: 
// tool: the portal's starter code (no AI)

// sub_001BF100 (0x001BF100, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048C898;

bool __cdecl sub_001BF100(void)
{
    int t1;

    t1 = DAT_0048C898;
    if (DAT_0048C898) {
        return *(bool*)(t1 + 354);
    }
    return false;
}
