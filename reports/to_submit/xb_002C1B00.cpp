// bin: xb
// va: 0x002C1B00
// what: core::DriveThread's constructor: empties its three queues and hold records, makes its two semaphores and starts the worker thread.
// tool: Claude (from SPEC-018 section B.4.9)

extern "C" char DAT_0039E22C[];     // a base class's table
extern "C" char DAT_0039F094[];     // a base class's table
extern "C" char DAT_003DAC24[];     // core::SafeRefCount's table
extern "C" char DAT_003DB5F0[];     // core::DriveThread's table for the part at +0xC
extern "C" char DAT_003DB600[];     // core::DriveThread's table for the part at +0x4
extern "C" char DAT_003DB608[];     // core::DriveThread's main table
extern "C" void* DAT_0045894C;      // the allocator in use

// A system semaphore's handle.
struct Semaphore
{
    void* m_Handle; // +0x0
};

// A thread's record (0x4C bytes); SPEC-018 part A has its fields.
struct Thread
{
    char m_pad00[0x4C];
};

void __cdecl sub_00250EB0();
void __cdecl sub_00283B90(Semaphore* semaphore, int count);     // creates the semaphore
int __cdecl sub_002C18B0(void* driveThread);                    // what the worker thread runs
void __cdecl sub_00283FE0(Thread* thread, int (__cdecl* entry)(void*), void* argument, int priority, unsigned int stackSize, void* allocator);

namespace core
{
    class Request;

    // What is known about one priority while it is held back.
    struct HoldRecord
    {
        unsigned int m_Field0;      // +0x0
        unsigned int m_Field4;      // +0x4
        int m_Field8;               // +0x8
        unsigned short m_Count;     // +0xC
        bool m_Woken;               // +0xE
    };

    class DriveThread
    {
    public:
        DriveThread* sub_002C1B00(void* mutex, void* allocator);

        void* m_Table00;            // +0x00
        void* m_Table04;            // +0x04
        void* m_Allocator;          // +0x08
        void* m_Table0C;            // +0x0C
        int m_RefCount;             // +0x10
        void* m_Mutex;              // +0x14
        Thread m_Thread;            // +0x18
        bool m_Stop;                // +0x64
        Semaphore m_Wake;           // +0x68
        Request* m_Head[3];         // +0x6C
        Request* m_Tail[3];         // +0x78
        HoldRecord m_Hold[3];       // +0x84
        unsigned int m_Swallow;     // +0xB4
        Semaphore m_Answered;       // +0xB8
        bool m_Retry;               // +0xBC
        unsigned int m_Outstanding; // +0xC0
        Request* m_Current;         // +0xC4
        bool m_CurrentCancelled;    // +0xC8
    };
}

// The three base parts, whose constructors the compiler expanded at the start (SPEC-017 section 4.11).
struct RefCountPart
{
    void* m_Table;      // +0x0
};

struct AllocatedPart
{
    void* m_Table;      // +0x0
    void* m_Allocator;  // +0x4
};

struct SafeRefCountPart
{
    void* m_Table;      // +0x0
    int m_RefCount;     // +0x4
};

inline void ConstructRefCount(RefCountPart* part)
{
    part->m_Table = DAT_0039E22C;
}

inline void ConstructAllocated(AllocatedPart* part)
{
    part->m_Table = DAT_0039F094;
    part->m_Allocator = DAT_0045894C;
}

inline void ConstructSafeRefCount(SafeRefCountPart* part)
{
    part->m_Table = DAT_003DAC24;
    part->m_RefCount = 1;
}

core::DriveThread* core::DriveThread::sub_002C1B00(void* mutex, void* allocator)
{
    ConstructRefCount((RefCountPart*)&m_Table00);
    ConstructAllocated((AllocatedPart*)&m_Table04);
    ConstructSafeRefCount((SafeRefCountPart*)&m_Table0C);

    m_Table00 = DAT_003DB608;
    m_Table04 = DAT_003DB600;
    m_Table0C = DAT_003DB5F0;
    m_Mutex = mutex;
    m_Stop = false;
    m_Swallow = 0;
    m_Retry = false;
    m_Outstanding = 0;
    m_Current = 0;
    m_CurrentCancelled = false;
    sub_00250EB0();
    for (int i = 0; i < 3; ++i)
    {
        m_Head[i] = 0;
        m_Tail[i] = 0;
        m_Hold[i].m_Count = 0;
        m_Hold[i].m_Field4 = 0;
        m_Hold[i].m_Woken = false;
        m_Hold[i].m_Field8 = -1;
    }
    sub_00283B90(&m_Wake, 0);
    sub_00283B90(&m_Answered, 0);
    sub_00283FE0(&m_Thread, sub_002C18B0, this, 4, 0x2000, allocator);
    return this;
}
