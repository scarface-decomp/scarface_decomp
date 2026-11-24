// bin: xb
// va: 0x00230620
// what: 
// tool: the portal's starter code (no AI)

// sub_00230620 (0x00230620, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00226260();
};

extern "C" int DAT_00491EF8;

void __cdecl sub_00230620(void)
{
    ((Object*)DAT_00491EF8)->sub_00226260();
}
