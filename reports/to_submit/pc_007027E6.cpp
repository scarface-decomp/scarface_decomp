// bin: pc
// va: 0x007027E6
// what: Calls the function whose address is kept in a global.
// tool: Claude Opus 5.5 (transplanted from pc:0x006DED30, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F214;

class Class_007027E6
{
public:
    void sub_007027E6();
};

void Class_007027E6::sub_007027E6()
{
    ((void (__cdecl*)(void))DAT_0072F214)();
}