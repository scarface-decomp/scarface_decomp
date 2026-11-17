// bin: xb
// va: 0x00224400
// tool: the portal's starter code (no AI)
// sub_00224400 (0x00224400, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00490BE0;
extern "C" int __cdecl sub_0002AC90(int);
extern "C" int __cdecl sub_00219730(void);

class Class_00224400
{
public:
    int sub_00224400();
    bool sub_002175D0();
    char m_pad00[0xE9];
    unsigned char m_FieldE9; // +0xE9
};

int Class_00224400::sub_00224400()
{
    if (m_FieldE9 & 2) {
        if (sub_00219730()) goto L_39;
        if (sub_002175D0()) goto L_39;
        if (sub_0002AC90(DAT_00490BE0) == (int)this) goto L_39;
        return 1;
    }
L_39:
    return 0;
}
