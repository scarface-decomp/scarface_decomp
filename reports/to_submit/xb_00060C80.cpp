// bin: xb
// va: 0x00060C80
// what: Decrements the reference count at +0x04 and deletes the CementLoadTracker when it reaches zero.
// tool: Gemini 4 Neon

class CementLoadTracker
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ~CementLoadTracker();
    int m_RefCount; // +0x04
};

void CementLoadTracker::vfunc_01()
{
    if (--m_RefCount == 0) {
        m_RefCount = 0x02222222;
        delete this;
    }
}
