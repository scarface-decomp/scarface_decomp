// bin: xb
// va: 0x00317910
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317910 (0x00317910, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042E87C[];
extern "C" char DAT_0042E88C[];
extern "C" Object DAT_0048A3EC;
extern "C" char sub_0015C6D0[];

void __cdecl sub_00317910(void)
{
    DAT_0048A3EC.sub_0006F830((int)DAT_0042E88C, (int)DAT_0042E87C, (int)sub_0015C6D0, 0, 3, 3);
}
