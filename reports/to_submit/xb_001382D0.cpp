// bin: xb
// va: 0x001382D0
// what: Returns true if sub_00163D50() on the second argument is at least the threshold at +0x0C.
// tool: Gemini 4 Neon

struct Target_001382D0
{
    unsigned int sub_00163D50();
};

namespace AICommandWaits {

class Wait_AnimationPriority
{
public:
    virtual void vfunc_00();
    virtual bool vfunc_01(int a1, Target_001382D0* target);
    char m_pad04[0x8];
    unsigned int m_Field0C; // +0x0C
};

bool Wait_AnimationPriority::vfunc_01(int, Target_001382D0* target)
{
    return target->sub_00163D50() >= m_Field0C;
}

}
