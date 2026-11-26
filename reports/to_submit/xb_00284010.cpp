// bin: xb
// va: 0x00284010
// what: Makes a new fiber on the thread that calls it: fills in its record, adds it to the thread's list and creates the system fiber.
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

extern "C" void* __stdcall sub_00309449(unsigned int stackSize, void (__stdcall* start)(void*), void* parameter);     // CreateFiber
extern "C" void __stdcall sub_00283F20(void* unused);          // what a new fiber runs first
Thread* __cdecl sub_00283EB0();                                 // the calling thread's record

// Adds a fiber to the end of its thread's list of fibers.
inline void AppendFiber(Thread* thread, Fiber* fiber)
{
    if (thread->m_FiberHead == 0)
    {
        thread->m_FiberHead = fiber;
        fiber->m_Previous = 0;
    }
    else
    {
        thread->m_FiberTail->m_Next = fiber;
        fiber->m_Previous = thread->m_FiberTail;
    }
    thread->m_FiberTail = fiber;
    fiber->m_Next = 0;
}

void __cdecl sub_00284010(Fiber* fiber, int (__cdecl* entry)(void*), void* argument, int a4, unsigned int stackSize, int a6)
{
    fiber->m_Field20 = 0;
    fiber->m_Entry = entry;
    fiber->m_Argument = argument;
    Thread* owner = sub_00283EB0();
    fiber->m_Owner = owner;
    AppendFiber(owner, fiber);
    void* systemFiber = sub_00309449(stackSize, sub_00283F20, fiber);
    fiber->m_Field1C = 0;
    fiber->m_Field18 = 0;
    fiber->m_SystemFiber = systemFiber;
}
