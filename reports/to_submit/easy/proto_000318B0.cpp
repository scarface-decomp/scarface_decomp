// bin: proto
// va: 0x000318B0
// tool: the portal's starter code (no AI)
// sub_000318B0 (0x000318B0, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_0002FB80(int, int, int, int, int, int, int, int);
};

extern "C" bool __cdecl sub_00031810(int, int, int, int, int);

bool __cdecl sub_000318B0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int local_4;

    if (sub_00031810(a1, (int)(&local_4), a2, a6, -1)) {
        return ((Object*)local_4)->sub_0002FB80(a1, a2, a3, a4, a5, a6, a7, a8);
    }
    return false;
}
