// bin: xb
// va: 0x00230630
// what: 
// tool: the portal's starter code (no AI)

// sub_00230630 (0x00230630, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002263C0(int);
    void sub_00226500(int);
    void sub_00226560(int);
    void sub_002265C0(int);
};

extern "C" int DAT_00491EF8;

void __cdecl sub_00230630(void)
{
    ((Object*)DAT_00491EF8)->sub_00226500(16);
    ((Object*)DAT_00491EF8)->sub_00226560(16);
    ((Object*)DAT_00491EF8)->sub_002265C0(16);
    ((Object*)DAT_00491EF8)->sub_002263C0(16);
}
