// bin: xb
// va: 0x00323390
// what: 
// tool: the portal's starter code (no AI)

// sub_00323390 (0x00323390, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00242120(int, int);
};

extern "C" Object DAT_00489670;
extern "C" char sub_00107BC0[];

void __cdecl sub_00323390(void)
{
    DAT_00489670.sub_00242120((int)sub_00107BC0, (int)&DAT_00489670);
}
