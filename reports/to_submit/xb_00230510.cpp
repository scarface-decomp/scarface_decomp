// bin: xb
// va: 0x00230510
// what: 
// tool: the portal's starter code (no AI)

// sub_00230510 (0x00230510, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00224080(int, int);
};

extern "C" int DAT_00491EF8;

void __cdecl sub_00230510(int a1, int a2)
{
    ((Object*)DAT_00491EF8)->sub_00224080(a1, a2);
}
