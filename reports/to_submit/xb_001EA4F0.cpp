// bin: xb
// va: 0x001EA4F0
// what: Sets the script field spawnTemplate of SpawnTemplateGroup (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_001EA4F0 (0x001EA4F0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001E8630(int, int);
};

extern "C" int DAT_0048F740;

void __cdecl sub_001EA4F0(int a1, int a2)
{
    int t1, t2;

    if (!a2) goto L_39;
    if (!*(unsigned char*)a2) goto L_39;
    t1 = ((Object*)DAT_0048F740)->sub_001E8630(a2, 2);
    if (!t1) goto L_39;
    t2 = *(int*)(a1 + 36);
    if ((unsigned int)*(int*)(a1 + 36) < (unsigned int)*(int*)(a1 + 40)) {
        *(int*)(a1 + 36) = t2 + 4;
        if (!t2) goto L_38;
        *(int*)t2 = t1;
    }
L_38:
L_39:
    ;
}
