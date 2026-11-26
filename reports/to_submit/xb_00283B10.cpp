// bin: xb
// va: 0x00283B10
// what: Takes a fiber out of its thread's list of fibers, and frees the system fiber unless it is a thread's own first fiber.
// tool: Claude (from SPEC-018)

struct Thread;

// One fiber of a thread (0x24 bytes).
struct Fiber
{
    int (__cdecl* m_Entry)(void* argument);     // +0x00
    void* m_Argument;       // +0x04
    Thread* m_Owner;        // +0x08
    Fiber* m_Next;          // +0x0C
    Fiber* m_Previous;      // +0x10
    void* m_SystemFiber;    // +0x14
    int m_Field18;          // +0x18
    int m_Field1C;          // +0x1C
    int m_Field20;          // +0x20
};

// A thread's record (0x4C bytes). Its first fiber is part of it.
struct Thread
{
    Thread* m_Next;         // +0x00
    Thread* m_Previous;     // +0x04
    Fiber m_FirstFiber;     // +0x08
    Fiber* m_CurrentFiber;  // +0x2C
    Fiber* m_FiberHead;     // +0x30
    Fiber* m_FiberTail;     // +0x34
    bool m_Running;         // +0x38
    int m_Result;           // +0x3C
    int m_Priority;         // +0x40
    unsigned int m_Id;      // +0x44
    void* m_Handle;         // +0x48
};

extern "C" Thread DAT_004BDCD0;                                 // the record of the thread that started the library
extern "C" void __stdcall sub_003094D5(void* systemFiber);     // DeleteFiber

// Takes a fiber out of a thread's list of fibers. Written as its own helper with the thread passed in:
// that is what gives 0x283D20, where this is expanded with a fixed fiber, its two copies of the thread.
inline void RemoveFiber(Thread* thread, Fiber* fiber)
{
    if (fiber->m_Previous == 0)
    {
        thread->m_FiberHead = fiber->m_Next;
    }
    else
    {
        fiber->m_Previous->m_Next = fiber->m_Next;
    }
    if (fiber->m_Next == 0)
    {
        thread->m_FiberTail = fiber->m_Previous;
    }
    else
    {
        fiber->m_Next->m_Previous = fiber->m_Previous;
    }
}

void __cdecl sub_00283B10(Fiber* fiber)
{
    if (fiber != &DAT_004BDCD0.m_FirstFiber && fiber != &fiber->m_Owner->m_FirstFiber)
    {
        sub_003094D5(fiber->m_SystemFiber);
    }
    RemoveFiber(fiber->m_Owner, fiber);
}
