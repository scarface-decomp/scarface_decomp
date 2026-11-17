// bin: xb
// va: 0x0022C300
// tool: the portal's starter code (no AI)
// sub_0022C300 (0x0022C300, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00098BB0(int);
};

extern "C" Object DAT_00491FE8;
extern "C" int DAT_00491FEC;

int __cdecl sub_0022C300(void)
{
    return DAT_00491FE8.sub_00098BB0(DAT_00491FEC) != 0;
}
