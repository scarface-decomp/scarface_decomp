/*
 * Partial_Proven_Checkpoints.cpp
 * Partially proven functions (saved when a contributor cancels or a claim timer expires)
 * are stored here so the next contributor can resume from the verified bytes.
 */

// ============================================================================
// [PARTIAL PROVEN CHECKPOINT: 9/11 B (81.8%)]
// Function: core::DriveThread::vfunc_00 (PC 0x006E7EB0) | Saved by: RRutherrfordd (Founder) at 2026-11-07 00:23:35
// ============================================================================
namespace core {
void* __cdecl ResolveDescA(void* pDesc);

class DriveThread {
public:
    int   m_Field04; // +0x04
    void* m_pDesc08; // +0x08
    virtual void* vfunc_00(); // PC VA 0x006E7EB0 (11 B)
};

#pragma optimize("s", on)
#pragma optimize("s", on)
void* DriveThread::vfunc_00() {
    return ResolveDescA(m_pDesc08);
}
#pragma optimize("", on)
#pragma optimize("", on)
}

// ============================================================================
// [PARTIAL PROVEN CHECKPOINT: 5/11 B (45.5%)]
// Function: core::DriveThread::vfunc_01 (PC 0x006E7EC0) | Saved by: RRutherrfordd (Founder) at 2026-11-07 00:23:35
// ============================================================================
namespace core {
void* __cdecl ResolveDescB(void* pDesc);

class DriveThread {
public:
    int   m_Field04; // +0x04
    void* m_pDesc08; // +0x08
    virtual void* vfunc_01(); // PC VA 0x006E7EC0 (11 B)
};

#pragma optimize("s", on)
#pragma optimize("s", on)
void* DriveThread::vfunc_01() {
    return ResolveDescB(m_pDesc08);
}
#pragma optimize("", on)
#pragma optimize("", on)
}

// ============================================================================
// [PARTIAL PROVEN CHECKPOINT: 23/40 B (57.5%)]
// Function: audio::OmHalStream::vfunc_12 (PC 0x006EC5F0) | Saved by: RRutherrfordd (Founder) at 2026-11-07 00:23:36
// ============================================================================
namespace audio {
extern int g_AudioPool7F646C;
void __cdecl FreeToAudioPool(int* pool, void* ptr);
void __cdecl DestroySub1C0(void* pSub);

class OmHalStream {
public:
    char pad[0x1BC];
    char m_Sub1C0[16]; // +0x1C0
    virtual void vfunc_12(); // PC VA 0x006EC5F0 (40 B)
};

void OmHalStream::vfunc_12() {
    if (this != 0) {
        DestroySub1C0(m_Sub1C0);
        FreeToAudioPool(&g_AudioPool7F646C, this);
    }
}
}

// ============================================================================
// [PARTIAL PROVEN CHECKPOINT: 9/11 B (81.8%)]
// Function: core::DriveThread::vfunc_00 (PC 0x006E7EB0) | Saved by: RRutherrfordd (Founder) at 2026-11-07 00:25:34
// ============================================================================
namespace core {
void* __cdecl ResolveDescA(void* pDesc);

class DriveThread {
public:
    int   m_Field04; // +0x04
    void* m_pDesc08; // +0x08
    virtual void* vfunc_00(); // PC VA 0x006E7EB0 (11 B)
};

#pragma optimize("s", on)
#pragma optimize("s", on)
void* DriveThread::vfunc_00() {
    return ResolveDescA(m_pDesc08);
}
#pragma optimize("", on)
#pragma optimize("", on)
}

// ============================================================================
// [PARTIAL PROVEN CHECKPOINT: 5/11 B (45.5%)]
// Function: core::DriveThread::vfunc_01 (PC 0x006E7EC0) | Saved by: RRutherrfordd (Founder) at 2026-11-07 00:25:34
// ============================================================================
namespace core {
void* __cdecl ResolveDescB(void* pDesc);

class DriveThread {
public:
    int   m_Field04; // +0x04
    void* m_pDesc08; // +0x08
    virtual void* vfunc_01(); // PC VA 0x006E7EC0 (11 B)
};

#pragma optimize("s", on)
#pragma optimize("s", on)
void* DriveThread::vfunc_01() {
    return ResolveDescB(m_pDesc08);
}
#pragma optimize("", on)
#pragma optimize("", on)
}

// ============================================================================
// [PARTIAL PROVEN CHECKPOINT: 23/40 B (57.5%)]
// Function: audio::OmHalStream::vfunc_12 (PC 0x006EC5F0) | Saved by: RRutherrfordd (Founder) at 2026-11-07 00:25:35
// ============================================================================
namespace audio {
extern int g_AudioPool7F646C;
void __cdecl FreeToAudioPool(int* pool, void* ptr);
void __cdecl DestroySub1C0(void* pSub);

class OmHalStream {
public:
    char pad[0x1BC];
    char m_Sub1C0[16]; // +0x1C0
    virtual void vfunc_12(); // PC VA 0x006EC5F0 (40 B)
};

void OmHalStream::vfunc_12() {
    if (this != 0) {
        DestroySub1C0(m_Sub1C0);
        FreeToAudioPool(&g_AudioPool7F646C, this);
    }
}
}

// ============================================================================
// [PARTIAL PROVEN CHECKPOINT: 9/11 B (81.8%)]
// Function: core::DriveThread::vfunc_00 (PC 0x006E7EB0) | Saved by: RRutherrfordd (Founder) at 2026-11-07 00:26:46
// ============================================================================
namespace core {
void* __cdecl ResolveDescA(void* pDesc);

class DriveThread {
public:
    int   m_Field04; // +0x04
    void* m_pDesc08; // +0x08
    virtual void* vfunc_00(); // PC VA 0x006E7EB0 (11 B)
};

#pragma optimize("s", on)
#pragma optimize("s", on)
void* DriveThread::vfunc_00() {
    return ResolveDescA(m_pDesc08);
}
#pragma optimize("", on)
#pragma optimize("", on)
}

// ============================================================================
// [PARTIAL PROVEN CHECKPOINT: 5/11 B (45.5%)]
// Function: core::DriveThread::vfunc_01 (PC 0x006E7EC0) | Saved by: RRutherrfordd (Founder) at 2026-11-07 00:26:46
// ============================================================================
namespace core {
void* __cdecl ResolveDescB(void* pDesc);

class DriveThread {
public:
    int   m_Field04; // +0x04
    void* m_pDesc08; // +0x08
    virtual void* vfunc_01(); // PC VA 0x006E7EC0 (11 B)
};

#pragma optimize("s", on)
#pragma optimize("s", on)
void* DriveThread::vfunc_01() {
    return ResolveDescB(m_pDesc08);
}
#pragma optimize("", on)
#pragma optimize("", on)
}

// ============================================================================
// [PARTIAL PROVEN CHECKPOINT: 23/40 B (57.5%)]
// Function: audio::OmHalStream::vfunc_12 (PC 0x006EC5F0) | Saved by: RRutherrfordd (Founder) at 2026-11-07 00:26:48
// ============================================================================
namespace audio {
extern int g_AudioPool7F646C;
void __cdecl FreeToAudioPool(int* pool, void* ptr);
void __cdecl DestroySub1C0(void* pSub);

class OmHalStream {
public:
    char pad[0x1BC];
    char m_Sub1C0[16]; // +0x1C0
    virtual void vfunc_12(); // PC VA 0x006EC5F0 (40 B)
};

void OmHalStream::vfunc_12() {
    if (this != 0) {
        DestroySub1C0(m_Sub1C0);
        FreeToAudioPool(&g_AudioPool7F646C, this);
    }
}
}

// ============================================================================
// [PARTIAL PROVEN CHECKPOINT: 9/11 B (81.8%)]
// Function: core::DriveThread::vfunc_00 (PC 0x006E7EB0) | Saved by: RRutherrfordd (Founder) at 2026-11-07 00:32:15
// ============================================================================
namespace core {
void* __cdecl ResolveDescA(void* pDesc);

class DriveThread {
public:
    int   m_Field04; // +0x04
    void* m_pDesc08; // +0x08
    virtual void* vfunc_00(); // PC VA 0x006E7EB0 (11 B)
};

#pragma optimize("s", on)
#pragma optimize("s", on)
void* DriveThread::vfunc_00() {
    return ResolveDescA(m_pDesc08);
}
#pragma optimize("", on)
#pragma optimize("", on)
}

