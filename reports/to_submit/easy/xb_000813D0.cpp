// bin: xb
// va: 0x000813D0
// tool: the portal's starter code (no AI)
// sub_000813D0 (0x000813D0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_000813D0(int a1)
{
    if (*(bool*)(a1 + 52)) {
        if (*(unsigned char*)(a1 + 53)) goto L_1B;
        if (0.0f >= *(float*)(a1 + 36)) goto L_26;
    }
L_1B:
    *(bool*)(a1 + 53) = false;
    *(bool*)(a1 + 52) = false;
    *(float*)(a1 + 36) = 0.0f;
L_26:
    return a1;
}
