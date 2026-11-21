// bin: xb
// va: 0x00263FC0
// what: Stores a value in the global at 0x004BD4C8.
// tool: Claude Opus 5.5 (generated from the shape 'set int global (framed)', checked on decomp.me preset 266 by example)
#pragma optimize("y", off)

extern "C" int DAT_004BD4C8;

void __stdcall sub_00263FC0(int value)
{
    DAT_004BD4C8 = value;
}
