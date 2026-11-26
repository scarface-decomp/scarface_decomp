// bin: xb
// va: 0x00283F20
// what: What a new fiber runs first: finds the calling thread's current fiber and calls that fiber's function with its argument.
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

Thread* __cdecl sub_00283EB0();     // the calling thread's record

// The calling thread's current fiber, or null when the thread has no record (0x283EF0), expanded below.
Fiber* __cdecl sub_00283EF0()
{
    Thread* thread = sub_00283EB0();
    if (thread == 0)
    {
        return 0;
    }
    return thread->m_CurrentFiber;
}

void __stdcall sub_00283F20(void* unused)
{
    Fiber* fiber = sub_00283EF0();
    fiber->m_Field18 = 0;
    fiber->m_Entry(fiber->m_Argument);
}
