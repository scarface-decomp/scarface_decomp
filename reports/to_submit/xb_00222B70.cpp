// bin: xb
// va: 0x00222B70
// what: 
// tool: the portal's starter code (no AI)

// sub_00222B70 (0x00222B70, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002263C0(int);
    void sub_00226500(int);
    void sub_002265C0(int);
};

extern "C" int DAT_00491EF8;

void __cdecl sub_00222B70(void)
{
    ((Object*)DAT_00491EF8)->sub_002263C0(32);
    ((Object*)DAT_00491EF8)->sub_00226500(32);
    ((Object*)DAT_00491EF8)->sub_002265C0(32);
}
