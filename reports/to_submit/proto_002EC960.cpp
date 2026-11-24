// bin: proto
// va: 0x002EC960
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC960 (Proto 0x002EC960, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AB74C[];
extern "C" Object DAT_00462F70;
extern "C" char sub_001EC2E0[];

void __cdecl sub_002EC960(void)
{
    DAT_00462F70.sub_000D8CC0(41, 31, 20, 31, 4, (int)DAT_003AB74C, (int)sub_001EC2E0, 208, 0, 1);
}
