// bin: xb
// va: 0x001E5600
// what: Sets the script field spawnTemplate of ScatteredEnemyCharacterGeneratorSpawnObject (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_001E5600 (0x001E5600, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001E8630(int, int);
};

extern "C" int DAT_0048F740;

void __cdecl sub_001E5600(int a1, int a2)
{
    if (a2) {
        if (!*(unsigned char*)a2) goto L_31;
        *(int*)(a1 + (*(int*)(a1 + 172) * 4) + 120) = ((Object*)DAT_0048F740)->sub_001E8630(a2, 0);
        *(int*)(a1 + 172) += 1;
    }
L_31:
    ;
}
