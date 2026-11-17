// bin: xb
// va: 0x00212240
// tool: the portal's starter code (no AI)
// sub_00212240 (0x00212240, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003CF280;

class Class_00212240
{
public:
    int sub_00212240(int a1);
    char m_pad00[0x174];
    short m_Field174; // +0x174
    short m_Field176; // +0x176
    short m_Field178; // +0x178
};

int Class_00212240::sub_00212240(int a1)
{
    float t1;

    t1 = DAT_003CF280;
    *(float*)a1 = ((float)m_Field174) * t1;
    *(float*)(a1 + 4) = ((float)m_Field176) * t1;
    *(float*)(a1 + 8) = ((float)m_Field178) * t1;
    return a1;
}
