// bin: xb
// va: 0x002C13E0
// what: core::DriveThread's destructor: sets the quit flag, wakes the thread, waits for it and destroys it, closes two semaphores, then restores the base tables.
// tool: Claude (from SPEC-016 section 12.4)

extern "C" char DAT_0039E22C[];     // a base class's table
extern "C" char DAT_0039F08C[];     // a base class's table
extern "C" char DAT_003DAC24[];     // core::SafeRefCount's table
extern "C" char DAT_003DB5F0[];     // core::DriveThread's table for the part at +0xC
extern "C" char DAT_003DB600[];     // core::DriveThread's table for the part at +0x4
extern "C" char DAT_003DB608[];     // core::DriveThread's main table
extern "C" void* DAT_0045894C;      // the allocator in use

// The two base parts whose destructors the compiler expanded at the end (SPEC-016 section 12.4).
struct RefCountPart
{
    void* m_Table;      // +0x0
};

struct AllocatedPart
{
    void* m_Table;      // +0x0
    void* m_Allocator;  // +0x4
};

inline void DestroyRefCount(RefCountPart* part)
{
    part->m_Table = DAT_003DAC24;
}

inline void DestroyAllocated(AllocatedPart* part)
{
    DAT_0045894C = part->m_Allocator;
    part->m_Table = DAT_0039F08C;
}

// A system semaphore's handle.
struct Semaphore
{
    void* m_Handle; // +0x0
};

// The system thread and what goes with it (0x4C bytes are used here; its functions know the rest).
struct Thread
{
    char m_pad00[0x4C];
};

void __cdecl sub_00283BD0(Semaphore* semaphore);    // signal it once
void __cdecl sub_00283BB0(Semaphore* semaphore);    // close its handle
void __cdecl sub_00283AF0(Thread* thread);
void __cdecl sub_00283DD0(Thread* thread);          // wait for the thread to end and destroy it

namespace core
{
    class DriveThread
    {
    public:
        void sub_002C13E0();

        void* m_Table00;        // +0x00
        void* m_Table04;        // +0x04
        void* m_Allocator;      // +0x08
        void* m_Table0C;        // +0x0C
        char m_pad10[0x8];
        Thread m_Thread;        // +0x18
        bool m_Quit;            // +0x64
        char m_pad65[0x3];
        Semaphore m_Wake;       // +0x68
        char m_pad6C[0x4C];
        Semaphore m_FieldB8;    // +0xB8
    };
}

void core::DriveThread::sub_002C13E0()
{
    m_Table00 = DAT_003DB608;
    m_Table04 = DAT_003DB600;
    m_Table0C = DAT_003DB5F0;

    m_Quit = true;
    sub_00283BD0(&m_Wake);
    sub_00283AF0(&m_Thread);
    sub_00283DD0(&m_Thread);
    sub_00283BB0(&m_Wake);
    sub_00283BB0(&m_FieldB8);

    // the base classes' destructors
    DestroyRefCount((RefCountPart*)&m_Table0C);
    DestroyAllocated((AllocatedPart*)&m_Table04);
    m_Table00 = DAT_0039E22C;
}
