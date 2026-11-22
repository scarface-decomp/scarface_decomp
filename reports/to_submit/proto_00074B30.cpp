// bin: proto
// va: 0x00074B30
// what: 
// tool: the portal's starter code (no AI)

// sub_00074B30 (Proto 0x00074B30, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_00074850(int, int, int, int);
};

extern "C" int DAT_00453900;

bool __cdecl sub_00074B30(int a1, int a2, int a3, int a4)
{
    if (DAT_00453900) {
        return ((Object*)DAT_00453900)->sub_00074850(a1, a2, a3, a4);
    }
    return false;
}
