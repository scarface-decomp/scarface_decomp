// bin: xb
// va: 0x00230600
// what: 
// tool: the portal's starter code (no AI)

// sub_00230600 (0x00230600, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002262C0(int);
    void sub_002263C0(int);
};

extern "C" int DAT_00491EF8;

void __cdecl sub_00230600(void)
{
    ((Object*)DAT_00491EF8)->sub_002262C0(0);
    ((Object*)DAT_00491EF8)->sub_002263C0(256);
}
