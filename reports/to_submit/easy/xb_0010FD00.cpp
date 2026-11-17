// bin: xb
// va: 0x0010FD00
// tool: the portal's starter code (no AI)
// sub_0010FD00 (0x0010FD00, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_0010FA70(int);

int __stdcall sub_0010FD00(int a1, int a2)
{
    int t1;

    t1 = sub_0010FA70(a1);
    if (t1) {
        if (0.0f >= *(float*)(t1 + 16)) goto L_28;
        *(int*)a2 = *(int*)(t1 + 16);
        return 1;
    }
L_28:
    return 0;
}
