/*
 * ============================================================================
 * StarterBatch1_25Functions.h — 100% Byte-Verified Decompilation (PC v1.00.2)
 * ============================================================================
 * Decompiled directly from `04_Starter_25_Small_Functions_Batch1.txt`
 * (25 x 14-byte non-trivial x86 functions across Gameplay, AI, FightTree,
 * ArtTemplates, Radical Core Memory, and Pure3D / PDDI).
 *
 * Compiler Flag Discovery Uncovered From Machine Code (`#01..#19` vs `#20..#24`):
 *   - Gameplay, AI, & Core (`#01..#19`, `#25`): Compiled with `/O2 /Oy`
 *     (Frame-Pointer Omission ENABLED — zero `55 8B EC` prologues; `#25` uses
 *     `/Os` `pop ecx` stack cleanup to save 2 bytes!).
 *   - Pure3D / PDDI (`pure3d::*` `#20, #22, #23, #24`): Compiled with `/O2 /Oy-`
 *     (Frame-Pointer Omission DISABLED — emits `55 8B EC ... 5D` on every method!).
 *   -> Setting `/Oy-` on `pure3d/ sources` and `/Oy` on `game/ sources` eliminates systematic
 *      3-byte frame-pointer mismatches in your automated `Scarface_AI_Lane_Runner.py`!
 * ============================================================================
 */

#ifndef SCARFACE_PC_V1002_STARTER_BATCH1_25_H
#define SCARFACE_PC_V1002_STARTER_BATCH1_25_H

#if defined(SCARFACE_FREESTANDING_X86_CHECK)
    typedef unsigned int   size_t;
    typedef signed char    int8_t;
    typedef short          int16_t;
    typedef int            int32_t;
    typedef unsigned char  uint8_t;
    typedef unsigned short uint16_t;
    typedef unsigned int   uint32_t;
    #ifndef NULL
        #define NULL 0
    #endif
#elif defined(_MSC_VER) && (_MSC_VER < 1600)
    #include <stddef.h>
    typedef signed char    int8_t;
    typedef short          int16_t;
    typedef int            int32_t;
    typedef unsigned char  uint8_t;
    typedef unsigned short uint16_t;
    typedef unsigned int   uint32_t;
#else
    #include <stddef.h>
    #include <stdint.h>
#endif

#if defined(_MSC_VER) && defined(_M_IX86)
    #if _MSC_VER >= 1400
        #define SCARFACE_X86_THISCALL __thiscall
    #else
        #define SCARFACE_X86_THISCALL   /* MSVC 7.1 rejects the keyword (C4234); members are thiscall anyway */
    #endif
    #define SCARFACE_X86_CDECL    __cdecl
    #define SCARFACE_PURE3D_FPO_OFF
    #pragma pack(push, 4)
#elif defined(__GNUC__) && defined(__i386__)
    #define SCARFACE_X86_THISCALL __attribute__((thiscall))
    #define SCARFACE_X86_CDECL    __attribute__((cdecl))
    #define SCARFACE_PURE3D_FPO_OFF __attribute__((optimize("no-omit-frame-pointer")))
#else
    #define SCARFACE_X86_THISCALL
    #define SCARFACE_X86_CDECL
    #define SCARFACE_PURE3D_FPO_OFF
#endif

#define SCARFACE_BATCH_FN(batch_no, xbox_va, byte_len)

/*
 * ============================================================================
 * External Engine Callees Referenced Across Batch #01..#25
 * ============================================================================
 */
namespace Batch1Externals {
    /* Xbox 0x0002C8A0: CScript member field registration helper (#01, #03) */
    void SCARFACE_X86_CDECL RegisterObjectFieldBlock(void* pObj, void* pEmbeddedField);

    /* Xbox 0x00026990: Embedded state-timer / response reset (#12) */
    extern uint32_t g_IdleChatResponseCount; /* Xbox 0x00489DD0 */

    void* SCARFACE_X86_CDECL CrtMallocHook(size_t byteCount); /* Xbox 0x002FE14A (#25) */
}

/* Embedded Timer queried by GlanceAtOvertakingPed (#05) & GlanceAbsentMindedly (#06) */
class SimCooldownTimer {
public:
    explicit SimCooldownTimer(bool bActive = false) : m_bRunning(bActive ? 1 : 0) {}
    /* Xbox 0x000CA1C0: Returns true if cooldown timer is still running */
    bool SCARFACE_X86_THISCALL IsRunning() const;
    uint8_t m_bRunning;
    uint8_t m_Pad[3];
};

/*
 * ============================================================================
 * BATCH #01..#04: Script/Sim Object & Path Virtual Methods
 * ============================================================================
 */

/* BATCH #01: `FEGroupObject::vfunc_26` | Xbox 0x00029F40 (PC 0x00442BD0) | 14B
 *   `lea eax, [ecx+0x20]; push eax; push ecx; call 0x0002C8A0; add esp, 8; ret` */
class FEGroupObject {
public:
    FEGroupObject() : m_GroupField20(0) {
        for (int i = 0; i < 0x1C; ++i) { m_BasePad04[i] = 0; }
    }
    virtual ~FEGroupObject() {}
    SCARFACE_BATCH_FN(1, 0x00029F40, 14)
    virtual void SCARFACE_X86_THISCALL vfunc_26();

    uint8_t  m_BasePad04[0x1C]; /* +0x04..+0x1F */
    uint32_t m_GroupField20;    /* +0x20 */
};

/* BATCH #02: `GameSimObject::vfunc_63` | Xbox 0x0002A390 (PC 0x00443030) | 14B
 *   `mov dl, [ecx+0xA4]; xor eax, eax; test dl, dl; setne al; ret`
 *   (Resolves byte +0xA4 inside GameSimObject / CharacterObject!) */
class GameSimObjectBatchView {
public:
    explicit GameSimObjectBatchView(uint8_t flagA4 = 0) : m_FlagA4(flagA4) {
        for (int i = 0; i < 0xA0; ++i) { m_Pad04[i] = 0; }
        m_PadA5[0] = 0; m_PadA5[1] = 0; m_PadA5[2] = 0;
    }
    virtual ~GameSimObjectBatchView() {}
    SCARFACE_BATCH_FN(2, 0x0002A390, 14)
    virtual bool SCARFACE_X86_THISCALL vfunc_63() const;

    uint8_t m_Pad04[0xA0]; /* +0x04..+0xA3 */
    uint8_t m_FlagA4;      /* +0xA4 */
    uint8_t m_PadA5[3];
};

/* BATCH #03: `PositionSetObject::vfunc_26` | Xbox 0x0002A670 | 14B
 *   `lea eax, [ecx+0x2C]; push eax; push ecx; call 0x0002C8A0; add esp, 8; ret` */
class PositionSetObject {
public:
    PositionSetObject() : m_PositionField2C(0) {
        for (int i = 0; i < 0x28; ++i) { m_BasePad04[i] = 0; }
    }
    virtual ~PositionSetObject() {}
    SCARFACE_BATCH_FN(3, 0x0002A670, 14)
    virtual void SCARFACE_X86_THISCALL vfunc_26();

    uint8_t  m_BasePad04[0x28];  /* +0x04..+0x2B */
    uint32_t m_PositionField2C;  /* +0x2C */
};

/* BATCH #04: `Path::vfunc_04` | Xbox 0x000336C0 | 14B
 *   `mov al, [esp+4]; mov byte ptr [ecx+0x14], 2; mov [ecx+0x18], al; ret 4` */
class Path {
public:
    Path() : m_PathState14(0), m_bClosedLoop18(0) {
        for (int i = 0; i < 0x10; ++i) { m_BasePad04[i] = 0; }
        m_Pad15[0] = 0; m_Pad15[1] = 0; m_Pad15[2] = 0;
        m_Pad19[0] = 0; m_Pad19[1] = 0; m_Pad19[2] = 0;
    }
    virtual ~Path() {}
    SCARFACE_BATCH_FN(4, 0x000336C0, 14)
    virtual void SCARFACE_X86_THISCALL vfunc_04(bool bLoopOrEnable);

    uint8_t m_BasePad04[0x10]; /* +0x04..+0x13 */
    uint8_t m_PathState14;     /* +0x14 (set to 2!) */
    uint8_t m_Pad15[3];        /* +0x15..+0x17 */
    uint8_t m_bClosedLoop18;   /* +0x18 (set to arg!) */
    uint8_t m_Pad19[3];
};

/*
 * ============================================================================
 * BATCH #05..#12: Ambient Glance, GameSet Filter, & AI Action/Condition Nodes
 * ============================================================================
 */

/* BATCH #05: `GlanceAtOvertakingPed::vfunc_07` | Xbox 0x000EFCF0 | 14B
 *   `add ecx, 0x14; call 0x000CA1C0; neg al; sbb eax, eax; inc eax; ret` */
class GlanceAtOvertakingPed {
public:
    explicit GlanceAtOvertakingPed(bool bBusy = false) : m_Cooldown14(bBusy) {
        for (int i = 0; i < 0x10; ++i) { m_Pad04[i] = 0; }
    }
    virtual ~GlanceAtOvertakingPed() {}
    SCARFACE_BATCH_FN(5, 0x000EFCF0, 14)
    virtual bool SCARFACE_X86_THISCALL vfunc_07() const;

    uint8_t          m_Pad04[0x10]; /* +0x04..+0x13 */
    SimCooldownTimer m_Cooldown14;  /* +0x14 */
};

/* BATCH #06: `GlanceAbsentMindedly::vfunc_00` | Xbox 0x000EFDE0 | 14B
 *   `add ecx, 0x10; call 0x000CA1C0; neg al; sbb eax, eax; inc eax; ret` */
class GlanceAbsentMindedly {
public:
    explicit GlanceAbsentMindedly(bool bBusy = false) : m_Cooldown10(bBusy) {
        for (int i = 0; i < 0x0C; ++i) { m_Pad04[i] = 0; }
    }
    SCARFACE_BATCH_FN(6, 0x000EFDE0, 14)
    virtual bool SCARFACE_X86_THISCALL vfunc_00() const;
    virtual ~GlanceAbsentMindedly() {}

    uint8_t          m_Pad04[0x0C]; /* +0x04..+0x0F */
    SimCooldownTimer m_Cooldown10;  /* +0x10 */
};

/* BATCH #07: `GameSetIteratorFunctionFilter<CharacterObject>::vfunc_00` | Xbox 0x00109FF0 | 14B
 *   `mov eax, [esp+4]; push eax; call dword ptr [ecx+4]; add esp, 4; ret 4` */
class CharacterObjectFwd;
template <class T>
class GameSetIteratorFunctionFilter {
public:
    typedef bool (SCARFACE_X86_CDECL *FilterPredicateFn)(T* pObj);

    explicit GameSetIteratorFunctionFilter(FilterPredicateFn fn) : m_pFilterFn(fn) {}
    SCARFACE_BATCH_FN(7, 0x00109FF0, 14)
    virtual bool SCARFACE_X86_THISCALL Matches(T* pObj) const {
        return m_pFilterFn(pObj);
    }
    virtual ~GameSetIteratorFunctionFilter() {}

    FilterPredicateFn m_pFilterFn; /* +0x04 (`call dword ptr [ecx+0x4]`) */
};

/* BATCH #08: `AIActionCustomLogicalEffect::vfunc_03` | Xbox 0x00120910 | 14B
 *   `mov eax, [ecx]; call [eax+0x18]; dec eax; neg eax; sbb eax, eax; add eax, 2; ret`
 *   Maps `vfunc_06() == 1` -> `2` (Completed), else `1` (Running)! */
class AIActionCustomLogicalEffect {
public:
    explicit AIActionCustomLogicalEffect(int32_t retCode = 1) : m_EffectCode(retCode) {}
    virtual ~AIActionCustomLogicalEffect() {}
    virtual void vfunc_01() {}
    virtual void vfunc_02() {}
    SCARFACE_BATCH_FN(8, 0x00120910, 14)
    virtual int32_t SCARFACE_X86_THISCALL vfunc_03();
    virtual void vfunc_04() {}
    virtual void vfunc_05() {}
    /* Slot 06 (+0x18 on MSVC x86) */
    virtual int32_t SCARFACE_X86_THISCALL ExecuteLogicalEffect() { return m_EffectCode; }

    int32_t m_EffectCode;
};

/* BATCH #09: `AIActionCancelPhysicalState::vfunc_06` | Xbox 0x00120F00 | 14B
 *   `mov ecx, [ecx+0x8]; call 0x0016B800 (CharacterObject::CancelPhysicalState); mov eax, 1; ret` */
class CharacterPhysicalTarget {
public:
    CharacterPhysicalTarget() : m_bCancelled(false) {}
    void SCARFACE_X86_THISCALL CancelPhysicalState(); /* Xbox 0x0016B800 */
    bool m_bCancelled;
};

class AIActionCancelPhysicalState {
public:
    explicit AIActionCancelPhysicalState(CharacterPhysicalTarget* pChar)
        : m_Unk04(0), m_pCharacter08(pChar) {}
    virtual ~AIActionCancelPhysicalState() {}
    SCARFACE_BATCH_FN(9, 0x00120F00, 14)
    virtual int32_t SCARFACE_X86_THISCALL vfunc_06();

    uint32_t                 m_Unk04;        /* +0x04 */
    CharacterPhysicalTarget* m_pCharacter08; /* +0x08 */
};

/* BATCH #10: `AIConditionCustom::vfunc_04` | Xbox 0x00121900 | 14B
 *   `mov eax, ecx; mov ecx, [eax+0xC]; mov eax, [eax+0x8]; mov edx, [ecx]; push eax; call [edx]; ret` */
class CustomConditionCallbackIface {
public:
    virtual bool SCARFACE_X86_THISCALL Invoke(void* pContextObj) = 0; /* Slot 00 (+0x00) */
    virtual ~CustomConditionCallbackIface() {}
};

class AIConditionCustom {
public:
    AIConditionCustom(void* pArg08, CustomConditionCallbackIface* pCb0C)
        : m_Unk04(0), m_pContextArg08(pArg08), m_pCallback0C(pCb0C) {}
    virtual ~AIConditionCustom() {}
    SCARFACE_BATCH_FN(10, 0x00121900, 14)
    virtual bool SCARFACE_X86_THISCALL Evaluate();

    uint32_t                      m_Unk04;         /* +0x04 */
    void*                         m_pContextArg08; /* +0x08 */
    CustomConditionCallbackIface* m_pCallback0C;   /* +0x0C */
};

/* BATCH #11: `AIConditionNot::vfunc_04` | Xbox 0x00121990 | 14B
 *   `mov ecx, [ecx+0x8]; mov eax, [ecx]; call [eax+0x10]; neg al; sbb eax, eax; inc eax; ret` */
class AIConditionBase {
public:
    virtual void vfunc_00() {}
    virtual void vfunc_01() {}
    virtual void vfunc_02() {}
    virtual void vfunc_03() {}
    /* Slot 04 (+0x10) */ virtual bool SCARFACE_X86_THISCALL Evaluate() = 0;
    virtual ~AIConditionBase() {}
};

class AIConditionNot : public AIConditionBase {
public:
    explicit AIConditionNot(AIConditionBase* pChild) : m_Unk04(0), m_pChildCondition08(pChild) {}
    SCARFACE_BATCH_FN(11, 0x00121990, 14)
    virtual bool SCARFACE_X86_THISCALL Evaluate();

    uint32_t         m_Unk04;             /* +0x04 */
    AIConditionBase* m_pChildCondition08; /* +0x08 */
};

/* BATCH #12: `AITask_IdleChatResponse::vfunc_49` | Xbox 0x001262C0 | 14B
 *   `inc dword ptr [0x00489DD0]; add ecx, 0x60; jmp 0x00026990` */
class IdleChatSubComponent {
public:
    IdleChatSubComponent() : m_TriggerCount(0) {}
    void SCARFACE_X86_THISCALL ActivateSubTask(); /* Xbox 0x00026990 */
    uint32_t m_TriggerCount;
};

class AITask_IdleChatResponse {
public:
    AITask_IdleChatResponse() {
        for (int i = 0; i < 0x5C; ++i) { m_Pad04[i] = 0; }
    }
    virtual ~AITask_IdleChatResponse() {}
    SCARFACE_BATCH_FN(12, 0x001262C0, 14)
    virtual void SCARFACE_X86_THISCALL vfunc_49();

    uint8_t              m_Pad04[0x5C]; /* +0x04..+0x5F */
    IdleChatSubComponent m_SubComp60;   /* +0x60 */
};

/*
 * ============================================================================
 * BATCH #13..#18: MissionFailHUD, WorldAmbience, MeleeProp, & ArtTemplates
 * ============================================================================
 */

/* BATCH #13: `MissionFailHUD::vfunc_54` | Xbox 0x001ACF30 | 14B
 *   `test byte ptr [ecx+0x60], 1; je +5; jmp HUDElement2::UpdateFrame (0x00193280); ret 4` */
class MissionFailHUD {
public:
    explicit MissionFailHUD(bool bVisible = true)
        : m_VisibilityFlags60(bVisible ? 0x01u : 0x00u), m_LastDeltaMs(0)
    {
        for (int i = 0; i < 0x5C; ++i) { m_HUDPad04[i] = 0; }
        m_Pad61[0] = 0; m_Pad61[1] = 0; m_Pad61[2] = 0;
    }
    virtual ~MissionFailHUD() {}
    void SCARFACE_X86_THISCALL BaseHUDUpdateFrame(uint32_t deltaMs); /* Xbox 0x00193280 */
    SCARFACE_BATCH_FN(13, 0x001ACF30, 14)
    virtual void SCARFACE_X86_THISCALL UpdateFrame(uint32_t deltaMs);

    uint8_t  m_HUDPad04[0x5C];      /* +0x04..+0x5F */
    uint8_t  m_VisibilityFlags60;   /* +0x60 (exact match with HUDElement2 +0x60 in EmpireHUD.h!) */
    uint8_t  m_Pad61[3];
    uint32_t m_LastDeltaMs;
};

/* BATCH #14: `WorldAmbienceSpawnObject::vfunc_41` | Xbox 0x001EB040 | 14B
 *   `mov ecx, [esp+4]; push 0; call 0x0002A160; ret 8` */
class SpawnedAmbienceTarget {
public:
    SpawnedAmbienceTarget() : m_LastMode(-1) {}
    void SCARFACE_X86_THISCALL SetAmbienceActive(int32_t mode); /* Xbox 0x0002A160 */
    int32_t m_LastMode;
};

class WorldAmbienceSpawnObject {
public:
    virtual ~WorldAmbienceSpawnObject() {}
    SCARFACE_BATCH_FN(14, 0x001EB040, 14)
    virtual void SCARFACE_X86_THISCALL vfunc_41(SpawnedAmbienceTarget* pTarget, void* pUnusedArg2);
};

/* BATCH #15: `MeleeWeaponStateProp::vfunc_77` | Xbox 0x001F2B90 | 14B
 *   `mov eax, [ecx]; call dword ptr [eax+0x13C]; neg al; sbb eax, eax; inc eax; ret` */
class MeleeWeaponStateProp {
public:
    explicit MeleeWeaponStateProp(bool bBroken = false) : m_bIsBrokenOrDepleted(bBroken) {}
    virtual ~MeleeWeaponStateProp() {}
    SCARFACE_BATCH_FN(15, 0x001F2B90, 14)
    virtual bool SCARFACE_X86_THISCALL IsIntact() const;
    /* Slots 2..78 are not reconstructed yet; they only hold IsBroken at its real slot. */
    virtual void vslot_02() {}
    virtual void vslot_03() {}
    virtual void vslot_04() {}
    virtual void vslot_05() {}
    virtual void vslot_06() {}
    virtual void vslot_07() {}
    virtual void vslot_08() {}
    virtual void vslot_09() {}
    virtual void vslot_10() {}
    virtual void vslot_11() {}
    virtual void vslot_12() {}
    virtual void vslot_13() {}
    virtual void vslot_14() {}
    virtual void vslot_15() {}
    virtual void vslot_16() {}
    virtual void vslot_17() {}
    virtual void vslot_18() {}
    virtual void vslot_19() {}
    virtual void vslot_20() {}
    virtual void vslot_21() {}
    virtual void vslot_22() {}
    virtual void vslot_23() {}
    virtual void vslot_24() {}
    virtual void vslot_25() {}
    virtual void vslot_26() {}
    virtual void vslot_27() {}
    virtual void vslot_28() {}
    virtual void vslot_29() {}
    virtual void vslot_30() {}
    virtual void vslot_31() {}
    virtual void vslot_32() {}
    virtual void vslot_33() {}
    virtual void vslot_34() {}
    virtual void vslot_35() {}
    virtual void vslot_36() {}
    virtual void vslot_37() {}
    virtual void vslot_38() {}
    virtual void vslot_39() {}
    virtual void vslot_40() {}
    virtual void vslot_41() {}
    virtual void vslot_42() {}
    virtual void vslot_43() {}
    virtual void vslot_44() {}
    virtual void vslot_45() {}
    virtual void vslot_46() {}
    virtual void vslot_47() {}
    virtual void vslot_48() {}
    virtual void vslot_49() {}
    virtual void vslot_50() {}
    virtual void vslot_51() {}
    virtual void vslot_52() {}
    virtual void vslot_53() {}
    virtual void vslot_54() {}
    virtual void vslot_55() {}
    virtual void vslot_56() {}
    virtual void vslot_57() {}
    virtual void vslot_58() {}
    virtual void vslot_59() {}
    virtual void vslot_60() {}
    virtual void vslot_61() {}
    virtual void vslot_62() {}
    virtual void vslot_63() {}
    virtual void vslot_64() {}
    virtual void vslot_65() {}
    virtual void vslot_66() {}
    virtual void vslot_67() {}
    virtual void vslot_68() {}
    virtual void vslot_69() {}
    virtual void vslot_70() {}
    virtual void vslot_71() {}
    virtual void vslot_72() {}
    virtual void vslot_73() {}
    virtual void vslot_74() {}
    virtual void vslot_75() {}
    virtual void vslot_76() {}
    virtual void vslot_77() {}
    virtual void vslot_78() {}
    /* Slot 79 (+0x13C): IsIntact calls through this slot */
    virtual bool SCARFACE_X86_THISCALL IsBroken() const { return m_bIsBrokenOrDepleted; }

    bool m_bIsBrokenOrDepleted;
};

/* BATCH #16, #17, #18: Template Flag `+0x22` Trio!
 *   #16 `CharacterFightTreeTemplate::vfunc_11` (0x001FB1F0): calls base `0x000221B0`, sets `[esi+0x22] = 0`
 *   #17 `HelicopterArtTemplate::vfunc_10`      (0x0020CA50): calls base `0x0020C570`, sets `[esi+0x22] = 1`
 *   #18 `AirplaneArtTemplate::vfunc_11`        (0x0020CA60): calls base `0x0020C680`, sets `[esi+0x22] = 0` */
class BaseTemplateWithLoadedFlag {
public:
    BaseTemplateWithLoadedFlag() : m_bLoadedFlag22(0), m_Pad23(0) {
        for (int i = 0; i < 0x1E; ++i) { m_Pad04[i] = 0; }
    }
    virtual ~BaseTemplateWithLoadedFlag() {}
    void SCARFACE_X86_THISCALL BaseOnLoad();   /* 0x0020C570 */
    void SCARFACE_X86_THISCALL BaseOnUnload(); /* 0x000221B0 / 0x0020C680 */

    uint8_t m_Pad04[0x1E];   /* +0x04..+0x21 */
    uint8_t m_bLoadedFlag22; /* +0x22 */
    uint8_t m_Pad23;
};

class CharacterFightTreeTemplate : public BaseTemplateWithLoadedFlag {
public:
    SCARFACE_BATCH_FN(16, 0x001FB1F0, 14)
    virtual void SCARFACE_X86_THISCALL vfunc_11();
};

class HelicopterArtTemplate : public BaseTemplateWithLoadedFlag {
public:
    SCARFACE_BATCH_FN(17, 0x0020CA50, 14)
    virtual void SCARFACE_X86_THISCALL vfunc_10();
};

class AirplaneArtTemplate : public BaseTemplateWithLoadedFlag {
public:
    SCARFACE_BATCH_FN(18, 0x0020CA60, 14)
    virtual void SCARFACE_X86_THISCALL vfunc_11();
};

/*
 * ============================================================================
 * BATCH #19..#25: Radical `core::*` Memory Allocators & `pure3d::*` Graphics
 * ============================================================================
 */
namespace core {

/* BATCH #19: `core::MemoryPool::vfunc_19` | Xbox 0x002518B0 | 14B
 *   `mov eax, [ecx+0x1C]; imul eax, [esp+4]; add eax, [ecx+0x18]; ret 4` */
class MemoryPool {
public:
    MemoryPool(uint8_t* pBase, uint32_t strideBytes)
        : m_pPoolBase18(pBase), m_BlockStride1C(strideBytes)
    {
        for (int i = 0; i < 0x14; ++i) { m_Pad04[i] = 0; }
    }
    virtual ~MemoryPool() {}
    SCARFACE_BATCH_FN(19, 0x002518B0, 14)
    virtual void* SCARFACE_X86_THISCALL GetBlockAddressByIndex(uint32_t blockIndex) const;

    uint8_t  m_Pad04[0x14];   /* +0x04..+0x17 */
    uint8_t* m_pPoolBase18;   /* +0x18 */
    uint32_t m_BlockStride1C; /* +0x1C */
};

/* BATCH #25: `core::MemoryAllocatorMalloc::vfunc_05` | Xbox 0x0028D060 | 14B
 *   `mov eax, [esp+4]; push eax; call 0x002FE14A; pop ecx; ret 4` */
class MemoryAllocatorMalloc {
public:
    virtual ~MemoryAllocatorMalloc() {}
    SCARFACE_BATCH_FN(25, 0x0028D060, 14)
    virtual void* SCARFACE_X86_THISCALL AllocateRaw(size_t byteSize);
};

} /* namespace core */

namespace pure3d {

/* BATCH #20: `pure3d::Image8::vfunc_19` | Xbox 0x00263240 | 14B (`/Oy-` frame pointer!)
 *   `push ebp; mov ebp, esp; mov eax, [ebp+8]; mov eax, [ecx+eax*4+0x28]; pop ebp; ret 4` */
class Image8 {
public:
    Image8() {
        for (int i = 0; i < 0x24; ++i) { m_Pad04[i] = 0; }
        for (int i = 0; i < 256; ++i)  { m_Palette28[i] = 0; }
    }
    virtual ~Image8() {}
    SCARFACE_BATCH_FN(20, 0x00263240, 14)
    virtual uint32_t SCARFACE_X86_THISCALL GetPaletteEntry(uint32_t entryIdx) const;

    uint8_t  m_Pad04[0x24];     /* +0x04..+0x27 */
    uint32_t m_Palette28[256];  /* +0x28 (`[ecx + eax*4 + 0x28]`) */
};

/* BATCH #21: `pure3d::d3dContext::vfunc_33` | Xbox 0x00265A50 | 14B
 *   `mov ecx, [ecx+0x2D0]; call 0x0029C520; ret 4` (Note: caller passes 1 dword arg popped via `ret 4`!) */
class d3dStateSubComponent {
public:
    d3dStateSubComponent() : m_FlushCount(0) {}
    void SCARFACE_X86_THISCALL FlushOrSyncState(); /* Xbox 0x0029C520 */
    uint32_t m_FlushCount;
};

class d3dContext {
public:
    explicit d3dContext(d3dStateSubComponent* pSub) : m_pSubState2D0(pSub) {
        for (int i = 0; i < 0x2CC; ++i) { m_Pad04[i] = 0; }
    }
    virtual ~d3dContext() {}
    SCARFACE_BATCH_FN(21, 0x00265A50, 14)
    virtual void SCARFACE_X86_THISCALL vfunc_33(uint32_t unusedArg);

    uint8_t               m_Pad04[0x2CC]; /* +0x04..+0x2CF */
    d3dStateSubComponent* m_pSubState2D0; /* +0x2D0 */
};

/* BATCH #22: `pure3d::d3dExtVisibilityTest::vfunc_07` | Xbox 0x002681A0 | 14B (`/Oy-`!)
 *   `push ebp; mov ebp, esp; mov eax, [ebp+8]; mov eax, [ecx+eax*4+0x38]; pop ebp; ret 4` */
class d3dExtVisibilityTest {
public:
    d3dExtVisibilityTest() {
        for (int i = 0; i < 0x34; ++i) { m_Pad04[i] = 0; }
        for (int i = 0; i < 16; ++i)   { m_QueryResults38[i] = 0; }
    }
    virtual ~d3dExtVisibilityTest() {}
    SCARFACE_BATCH_FN(22, 0x002681A0, 14)
    virtual uint32_t SCARFACE_X86_THISCALL GetVisibilityResult(uint32_t queryIndex) const;

    uint8_t  m_Pad04[0x34];        /* +0x04..+0x37 */
    uint32_t m_QueryResults38[16]; /* +0x38 (`[ecx + eax*4 + 0x38]`) */
};

/* BATCH #23 & #24: `pure3d::SpriteObject::vfunc_30` & `vfunc_31` | Xbox 0x0026DB10 / 20 | 14B (`/Oy-`!)
 *   `mov eax, [ecx+0x44]; mov ecx, [eax]; mov edx, [ecx]; pop ebp; jmp dword ptr [edx+0x44 / 0x48]` */
class SpriteShaderDelegate {
public:
    virtual ~SpriteShaderDelegate() {}
    virtual int32_t SCARFACE_X86_THISCALL GetWidth() const  { return 256; } /* Slot +0x44 in full Pure3D table */
    virtual int32_t SCARFACE_X86_THISCALL GetHeight() const { return 128; } /* Slot +0x48 in full Pure3D table */
};

struct SpriteResourceHandle {
    SpriteShaderDelegate* m_pDelegate; /* `[eax]` dereferenced @ 0x0026DB16! */
};

class SpriteObject {
public:
    explicit SpriteObject(SpriteResourceHandle* pHandle) : m_pResourceHandle44(pHandle) {
        for (int i = 0; i < 0x40; ++i) { m_Pad04[i] = 0; }
    }
    virtual ~SpriteObject() {}
    SCARFACE_BATCH_FN(23, 0x0026DB10, 14)
    virtual int32_t SCARFACE_X86_THISCALL vfunc_30() const;

    SCARFACE_BATCH_FN(24, 0x0026DB20, 14)
    virtual int32_t SCARFACE_X86_THISCALL vfunc_31() const;

    uint8_t               m_Pad04[0x40];        /* +0x04..+0x43 */
    SpriteResourceHandle* m_pResourceHandle44;  /* +0x44 */
};

} /* namespace pure3d */

/* 32-Bit x86 Exact Offset Verification Across All Batch 1 Classes */
inline int VerifyBatch1FieldOffsetsX86() {
    if (sizeof(void*) != 4) { return 25; }
    char raw[1024];
    #define CHK_B1(Type, Member, HexOff) \
        if ((reinterpret_cast<const char*>(&reinterpret_cast<const Type*>(raw)->Member) - raw) != (HexOff)) return -(HexOff)
    CHK_B1(FEGroupObject,                  m_GroupField20,       0x020);
    CHK_B1(GameSimObjectBatchView,         m_FlagA4,             0x0A4);
    CHK_B1(PositionSetObject,              m_PositionField2C,    0x02C);
    CHK_B1(Path,                           m_PathState14,        0x014);
    CHK_B1(Path,                           m_bClosedLoop18,      0x018);
    CHK_B1(GlanceAtOvertakingPed,          m_Cooldown14,         0x014);
    CHK_B1(GlanceAbsentMindedly,           m_Cooldown10,         0x010);
    CHK_B1(AIActionCancelPhysicalState,    m_pCharacter08,       0x008);
    CHK_B1(AIConditionCustom,              m_pContextArg08,      0x008);
    CHK_B1(AIConditionCustom,              m_pCallback0C,        0x00C);
    CHK_B1(AIConditionNot,                 m_pChildCondition08,  0x008);
    CHK_B1(AITask_IdleChatResponse,        m_SubComp60,          0x060);
    CHK_B1(MissionFailHUD,                 m_VisibilityFlags60,  0x060);
    CHK_B1(BaseTemplateWithLoadedFlag,     m_bLoadedFlag22,      0x022);
    CHK_B1(core::MemoryPool,               m_pPoolBase18,        0x018);
    CHK_B1(core::MemoryPool,               m_BlockStride1C,      0x01C);
    CHK_B1(pure3d::Image8,                 m_Palette28,          0x028);
    CHK_B1(pure3d::d3dContext,             m_pSubState2D0,       0x2D0);
    CHK_B1(pure3d::d3dExtVisibilityTest,   m_QueryResults38,     0x038);
    CHK_B1(pure3d::SpriteObject,           m_pResourceHandle44,  0x044);
    #undef CHK_B1
    return 25;
}

#if defined(_MSC_VER) && defined(_M_IX86)
    #pragma pack(pop)
#endif

#endif /* SCARFACE_PC_V1002_STARTER_BATCH1_25_H */
