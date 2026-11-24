// bin: proto
// va: 0x001EF8E0
// what: 
// tool: the portal's starter code (no AI)

// sub_001EF8E0 (Proto 0x001EF8E0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;
extern "C" bool DAT_004635C8;
extern "C" int DAT_004635CC;

bool __cdecl sub_001EF8E0(void)
{
    if (!DAT_004635C8) {
        if (*(unsigned char*)(DAT_0045A0EC + 84) & 16) goto L_24;
        if (*(bool*)(DAT_004635CC + 96)) goto L_24;
        return false;
    }
L_24:
    return true;
}
