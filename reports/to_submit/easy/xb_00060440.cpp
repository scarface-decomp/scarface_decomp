// bin: xb
// va: 0x00060440
// tool: the portal's starter code (no AI)
// sub_00060440 (0x00060440, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00060440
{
public:
    int sub_00060440(float a1);
    char m_pad00[0x84];
    int m_Field84; // +0x84
};

int Class_00060440::sub_00060440(float a1)
{
    int r_eax;

    r_eax = m_Field84;
    if (r_eax) {
        r_eax = *(int*)(r_eax + 68);
        r_eax = *(int*)r_eax;
        if (!r_eax) goto L_21;
        *(float*)(r_eax + 3716) = a1;
    }
L_21:
    return r_eax;
}
