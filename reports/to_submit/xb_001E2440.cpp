// bin: xb
// va: 0x001E2440
// what: Sets the script field spawnTriggerObject of GenericSpawnObject (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_001E2440 (0x001E2440, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001E1650(int);
};

int __cdecl sub_001E2440(int a1, int a2)
{
    int r_eax;

    r_eax = a2;
    if (a2) {
        if (!*(unsigned char*)r_eax) goto L_17;
        r_eax = ((Object*)a1)->sub_001E1650(a2);
    }
L_17:
    return r_eax;
}
