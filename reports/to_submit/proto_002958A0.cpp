// bin: proto
// va: 0x002958A0
// what: Stores a decimal number at +0x98 of a global object.
// tool: Claude Opus 5.5 (transplanted from xb:0x002D30B0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00490C70;

void __cdecl sub_002958A0(float a1)
{
    int t1;

    t1 = DAT_00490C70;
    *(float*)(DAT_00490C70 + 152) = a1;
}