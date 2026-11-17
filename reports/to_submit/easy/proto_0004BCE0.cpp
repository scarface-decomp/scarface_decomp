// bin: proto
// va: 0x0004BCE0
// tool: the portal's starter code (no AI)
// sub_0004BCE0 (0x0004BCE0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_0004EEB0(int);

int __stdcall sub_0004BCE0(float a1, float a2, float a3, float a4, float a5, float a6)
{
    int t1, t2;

    t1 = sub_0004EEB0(0);
    t2 = *(int*)*(int*)(t1 + 68);
    *(float*)(*(int*)*(int*)(t1 + 68) + 64) = a2;
    *(float*)(t2 + 68) = a1;
    *(float*)(t2 + 72) = a3;
    *(float*)(t2 + 76) = a4;
    *(float*)(t2 + 80) = a5;
    *(float*)(t2 + 84) = a6;
    return t2;
}
