// bin: pc
// va: 0x006EFA50
// what: Stores 3 at +0x18 of a record and returns the record.
// tool: Claude Opus 5.5 (transplanted from proto:0x002AB460, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_006EFA50(int a1)
{
    *(int*)(a1 + 24) = 3;
    return a1;
}