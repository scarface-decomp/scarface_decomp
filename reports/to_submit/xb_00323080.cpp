// bin: xb
// va: 0x00323080
// what: 
// tool: the portal's starter code (no AI)

// sub_00323080 (0x00323080, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000999A0();
};

extern "C" Object DAT_00481B90;

void __cdecl sub_00323080(void)
{
    DAT_00481B90.sub_000999A0();
    DAT_00481B90.sub_000999A0();
}
