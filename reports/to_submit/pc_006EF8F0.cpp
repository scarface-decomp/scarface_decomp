// bin: pc
// va: 0x006EF8F0
// what: Returns the number at +0x24 of a global object.
// tool: Claude Opus 5.5 (transplanted from proto:0x0006D060, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D134;

int __cdecl sub_006EF8F0(void)
{
    return *(int*)(DAT_0085D134 + 36);
}