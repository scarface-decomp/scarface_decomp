// bin: pc
// va: 0x006E51B0
// what: Calls the function whose address is kept in a global.
// tool: Claude Opus 5.5 (transplanted from pc:0x006DED30, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00FB0444;

class Class_006E51B0
{
public:
    void sub_006E51B0();
};

void Class_006E51B0::sub_006E51B0()
{
    ((void (__cdecl*)(void))DAT_00FB0444)();
}