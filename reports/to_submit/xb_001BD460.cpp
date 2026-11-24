// bin: xb
// va: 0x001BD460
// what: 
// tool: the portal's starter code (no AI)

// sub_001BD460 (0x001BD460, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00196CA0(int);
};

extern "C" int DAT_0048C23C;

void __cdecl sub_001BD460(void)
{
    ((Object*)DAT_0048C23C)->sub_00196CA0(1);
}
