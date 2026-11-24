// bin: xb
// va: 0x00230540
// what: 
// tool: the portal's starter code (no AI)

// sub_00230540 (0x00230540, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002259E0();
};

extern "C" int DAT_00491EF8;

void __cdecl sub_00230540(void)
{
    ((Object*)DAT_00491EF8)->sub_002259E0();
}
