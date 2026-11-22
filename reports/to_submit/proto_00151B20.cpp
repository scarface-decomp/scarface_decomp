// bin: proto
// va: 0x00151B20
// what: 
// tool: the portal's starter code (no AI)

// sub_00151B20 (Proto 0x00151B20, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00150860(int);

class Class_00151B20
{
public:
    void sub_00151B20(int a1);
    char m_pad00[0x3FC];
    int m_Field3FC; // +0x3FC
    char m_pad400[0x8];
    bool m_Field408; // +0x408
};

void Class_00151B20::sub_00151B20(int a1)
{
    if (m_Field3FC != a1) {
        m_Field3FC = a1;
        if (m_Field408) goto L_25;
        a1 = a1;
        sub_00150860(a1);
        return;
    }
L_25:
    ;
}
