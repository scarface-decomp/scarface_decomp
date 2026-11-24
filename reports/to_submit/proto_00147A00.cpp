// bin: proto
// va: 0x00147A00
// what: 
// tool: the portal's starter code (no AI)

// sub_00147A00 (Proto 0x00147A00, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00072DC0(int);

class Class_00147A00
{
public:
    int sub_00147A00();
    char m_pad00[0x188];
    int m_Field188; // +0x188
};

int Class_00147A00::sub_00147A00()
{
    int r_eax;

    r_eax = m_Field188;
    if (r_eax) {
        r_eax = *(int*)(r_eax + 380);
        if (!r_eax) goto L_1E;
        r_eax = sub_00072DC0(r_eax);
        return r_eax;
    }
L_1E:
    r_eax |= -1;
    return r_eax;
}
