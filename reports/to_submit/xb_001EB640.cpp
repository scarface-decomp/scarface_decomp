// bin: xb
// va: 0x001EB640
// what: Sets the script field spawnTemplateGroup of WorldAmbienceSpawnObject (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_001EB640 (0x001EB640, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001EB290(int);
};

int __cdecl sub_001EB640(int a1, int a2)
{
    int r_eax;

    r_eax = a2;
    if (a2) {
        if (!*(unsigned char*)r_eax) goto L_17;
        r_eax = ((Object*)a1)->sub_001EB290(a2);
    }
L_17:
    return r_eax;
}
