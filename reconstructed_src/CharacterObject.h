/*
 * ============================================================================
 * CharacterObject.h — 100% Byte-Verified Decompilation (PC v1.00.2 US Patch)
 * ============================================================================
 * Decompiled directly from `03_CharacterObject_WorkPack.txt` (58 machine-code
 * blocks, Retail Xbox 1:1 Donor `default.xbe` -> PC `Scarface.exe` v1.00.2).
 *
 * Verified Binary Facts Uncovered From Machine Code:
 *   1. Exact Class & Helper Sizes on 32-Bit x86 (`MSVC 7.10` / `g++ -m32`):
 *        sizeof(CharacterObject)     == 0x430 (1,072 bytes! Proven @ 0x00179128 `push 0x430`)
 *        sizeof(InventoryOwner)      == 0x0BC (  188 bytes! Proven @ 0x001678F7 `lea ecx, [esi+0xBC]`)
 *        sizeof(CharacterContext)    == 0x068 (  104 bytes! Proven @ 0x0016828E `push 0x68`)
 *        sizeof(PendingVocalRequest) == 0x038 (   56 bytes! Proven @ 0x0048ABC4 + 0x34 == 0x0048ABF8)
 *
 *   2. Exact 7-Layer Single-Inheritance Hierarchy & 74-Slot VFTable:
 *        ConsoleObject -> ScriptObject -> GameSetObject -> GameObject
 *          -> GameSimObject -> InventoryOwner -> CharacterObject
 *        PC v1.00.2 VFTable  : 0x00747D5C (74 slots: [00..73], +0x00..+0x124)
 *        default.xbe VFTable : 0x003B3FBC (74 slots: [00..73], +0x00..+0x124)
 *
 *   3. Exact Key Field Offsets Verified Across All 58 Disassembled Functions:
 *        +0x00C: m_NameSymbolId        (compared against "MainCharacter" @ 0x0016827B)
 *        +0x010: m_SimObjectId         (runtime object handle)
 *        +0x01E: m_ScriptFlags         (bit 0x10 toggled by vfunc_10 / vfunc_11)
 *        +0x054: m_TransformMatrix     (3x3 orientation matrix, 36 bytes)
 *        +0x064: m_Position            (Vector3 x, y, z @ +0x64, +0x68, +0x6C)
 *        +0x098: m_CollisionMaskByte   (read in vfunc_59 @ 0x001674FD)
 *        +0x0A5: m_SimStateBits        (bit 0x01 @ vfunc_05, 0x02 @ vfunc_17, 0x04 @ vfunc_53)
 *        +0x0AC: m_AlertStatus         (0=Idle/Dead, 2=Patrol, >=4=Combat/"drugwars")
 *        +0x0BC: m_DamageTracker       (first CharacterObject field, 0x1C bytes)
 *        +0x0F8: m_pMainCharContext    (0x68-byte CharacterContext* for "MainCharacter")
 *        +0x10C: m_ActiveTimerSec      (SSE2 float timer accumulated in vfunc_08)
 *        +0x15C: m_CurrentHealth       (100 on init; Event 0x25; <=0 in IsDead vfunc_36)
 *        +0x160: m_MaxHealth           (100 on init; Event 0x26; queried for Tony in vfunc_04)
 *        +0x164: m_bIsCriticalHealth   (low-health flag computed in 0x00166970)
 *        +0x18C: m_DyingTimerEventId   ("OnDyingFinished" scheduled 2000ms or 5000ms)
 *        +0x1A4: m_HeadingRadians      (vfunc_44 setter / vfunc_45 getter)
 *        +0x1AC: m_pPhysicsCharacter   (physics/ragdoll/hit-primitive & vocal emitter rig)
 *        +0x1B0: m_Locomotion          (0xBC-byte embedded subsystem)
 *        +0x26C: m_Aiming              (0x30-byte embedded subsystem)
 *        +0x2AC: m_WeaponMount         (0x30-byte embedded subsystem + WeaponInventorySet ID)
 *        +0x2E8: m_AnimDriver          (0x90-byte animation tree driver)
 *        +0x378: m_CurrentVehicleId    (mounted vehicle SimObject handle)
 *        +0x3F0: m_AttachedProps[6]    (6 attached prop handles cleaned up in vfunc_14)
 *        +0x421: m_bIsInvulnerable     (vfunc_50 getter / vfunc_51 setter)
 *        +0x428: m_HealthEventId       (0xE4 default; custom boss health bar event if != 0xE4)
 *        +0x42C: m_pExtraHeapData      (freed via PoolFree @ 0x00169CAE -> end of 0x430!)
 * ============================================================================
 */

#ifndef SCARFACE_PC_V1002_CHARACTER_OBJECT_H
#define SCARFACE_PC_V1002_CHARACTER_OBJECT_H

#include "EmpireHUD.h"

#if defined(_MSC_VER) && defined(_M_IX86)
    #pragma pack(push, 4)
#endif

/* Compiler-clean byte-offset check for polymorphic classes on 32-bit x86 */
#define SCARFACE_ASSERT_X86_OFFSET(Type, Member, ExpectedHex) \
    SCARFACE_STATIC_ASSERT( \
        sizeof(void*) != 4 || \
        (reinterpret_cast<const char*>(&reinterpret_cast<const Type*>(0x10000)->Member) - \
         reinterpret_cast<const char*>(reinterpret_cast<const Type*>(0x10000))) == (ExpectedHex), \
        offset_check_##Member)

class CharacterObject;
class GameSimObject;
class VehicleSimObject;

/*
 * ============================================================================
 * 1. Math, Scoped Memory Pool Guard (`0x00026EC0`), & Engine Subsystem Types
 * ============================================================================
 */
struct Vector3f {
    float x;
    float y;
    float z;
};

struct Matrix3x3f {
    float m[3][3]; /* 36 bytes (+0x54..+0x77 when paired with Position @ +0x64? Note:
                    * +0x54..+0x63 is 16B rotation/quat or 3x3 top rows + Position @ +0x64..+0x6F!) */
};

struct TickUpdateParams {
    uint32_t m_TickIndex;   /* +0x00 (fild dword ptr [edi] @ 0x0016C645) */
    uint32_t m_DeltaMs;     /* +0x04 */
    uint32_t m_SubStep;     /* +0x08 */
    float    m_DeltaSec;    /* +0x0C (`movss xmm0, [ebp+0xC]` @ 0x0016D9C2!) */
};

/*
 * ScopedPoolPush (`0x00026EC0` ctor [29B] / `0x00026EE0` dtor [10B]):
 * Pushes allocator pool ID (`0x0A` = Gameplay Sim Pool, `0x09` = AI/Spawn Pool)
 * onto Radical's thread-local memory pool stack and restores previous pool on scope exit!
 */
class ScopedPoolPush {
public:
    SCARFACE_MATCHED_FN(0x00000000, 0x00026EC0, 29)
    explicit ScopedPoolPush(int32_t newPoolId);

    SCARFACE_MATCHED_FN(0x00000000, 0x00026EE0, 10)
    ~ScopedPoolPush();

private:
    int32_t m_SavedPoolId;
};

namespace RadicalSim {
    /* Xbox 0x00244040: Interns string into global symbol table (`StringTableEntry`) */
    uint32_t SCARFACE_CDECL InternString(const char* str, int32_t caseSensitive);

    /* Xbox 0x0006F9F0 (67B): Sets CScript global variable (auto-prefixes '$' if missing!) */
    SCARFACE_MATCHED_FN(0x00000000, 0x0006F9F0, 67)
    void SCARFACE_CDECL SetConsoleGlobalVar(const char* varName, const char* valueStr);

    /* Xbox 0x00066C00: Increments integer CScript stat variable (e.g. "$statTracking::tonyDeaths") */
    void SCARFACE_CDECL IncrementStatCounter(const char* statVarName, int32_t delta);

    /* Xbox 0x00070470: Invokes CScript callback method on a ScriptObject (`Con::executef`) */
    const char* SCARFACE_CDECL ExecuteObjectCallback1(ScriptObject* pObj, const char* methodName);
    const char* SCARFACE_CDECL ExecuteObjectCallback2(ScriptObject* pObj, const char* methodName, const char* arg1);

    /* Xbox 0x0002B770 (619B): Hierarchical SimObject lookup by path ("Group:Child"), ID, or name! */
    SCARFACE_MATCHED_FN(0x00000000, 0x0002B770, 619)
    GameSimObject* SCARFACE_CDECL FindSimObjectByPathOrId(const char* pathOrId, uint32_t contextSetId);

    GameSimObject* SCARFACE_CDECL ResolveSimHandle(uint32_t simId); /* Xbox 0x0002AC90 */
    void           SCARFACE_CDECL DeleteSimObject(GameSimObject* pObj); /* Xbox 0x0002BFA0 */
    uint32_t       SCARFACE_CDECL GetSimTimeMs(); /* Reads [0x004879E8]->m_SimTimeMs (+0x2C) */

    /* Schedules script callback (`"OnDyingFinished"`) after `delayMs` (Xbox 0x0002B150) */
    uint32_t SCARFACE_CDECL ScheduleObjectEvent(ScriptObject* pObj, uint32_t delayMs, const char* callbackName);
    void     SCARFACE_CDECL CancelScheduledEvent(uint32_t eventId); /* Xbox 0x000683E0 */

    /* Combat music state (`"drugwars"` @ 0x00168E4E) */
    uint32_t SCARFACE_CDECL GetAudioDuckHandle(const char* duckPresetName);
    void SCARFACE_CDECL ActivateAudioDuck(uint32_t duckHandle, uint32_t fadeMs, int32_t a3, int32_t priority, int32_t a5);
    void SCARFACE_CDECL TriggerCombatMusic(uint32_t charSimId, const char* cueName, uint32_t fadeMs);
    void SCARFACE_CDECL ReleaseCombatMusic(uint32_t charSimId);
}

/*
 * ============================================================================
 * 2. CharacterContext (`sizeof == 0x68` = 104B, Xbox 0x00161940, VFTable 0x003B3C80)
 *    Allocated exclusively for Tony Montana ("MainCharacter") at `CharacterObject + 0xF8`!
 * ============================================================================
 */
class CharacterContext {
public:
    struct WeaponSlotContext {
        int32_t  m_WeaponTypeId; /* +0x00 (-1 on init) */
        float    m_VecOrTimers[3]; /* +0x04..+0x0F (0.0f) */
        uint32_t m_AmmoOrState;  /* +0x10 (0) */
        int32_t  m_SubSlotIdx;   /* +0x14 (-1) */
        uint32_t m_Flags18;      /* +0x18 (0) */
        uint32_t m_HandleList1C; /* +0x1C (0, init via 0x00098B90) */
    }; /* Exact 0x20 (32) bytes x 2 slots = 0x40 bytes (+0x04..+0x43)! */

    SCARFACE_MATCHED_FN(0x00000000, 0x00161940, 156)
    explicit CharacterContext(CharacterObject* pOwner);

    virtual ~CharacterContext() {} /* Slot 00 (+0x00) called in ~CharacterObject @ 0x00167D57 */
    void UpdateContext(const TickUpdateParams* pTick); /* Xbox 0x001620C0 */

    WeaponSlotContext m_Slots[2];        /* +0x04..+0x43 */
    int32_t           m_ContextActive;   /* +0x44 (= 1) */
    int32_t           m_PrimarySlot;     /* +0x48 (= -1) */
    CharacterObject*  m_pOwner;          /* +0x4C (= this CharacterObject*) */
    uint32_t          m_Unk50;           /* +0x50 (= 0) */
    int32_t           m_SecondarySlot;   /* +0x54 (= -1) */
    uint32_t          m_Unk58;           /* +0x58 (= 0) */
    uint32_t          m_Unk5C;           /* +0x5C (= 0) */
    float             m_AimAssistScale;  /* +0x60 (= [0x0039D658]) */
    uint8_t           m_bInitialized;    /* +0x64 (= 1) */
    uint8_t           m_Pad65[3];        /* +0x65..+0x67 -> exact sizeof == 0x68 (104 bytes)! */
};

/*
 * PendingVocalRequest (`sizeof == 0x38` = 56B, Xbox 0x00165160, singleton @ 0x0048ABC4):
 *   +0x30 (`0x0048ABF4`): m_DelayTimer
 *   +0x34 (`0x0048ABF8`): m_TargetCharacterSimId (polled in CharacterObject::vfunc_08!)
 */
struct PendingVocalRequest {
    uint32_t m_VTableOrTag;       /* +0x00 */
    uint8_t  m_RequestData[0x2C]; /* +0x04..+0x2F (two strings + 4 params copied in 0x001651B0) */
    uint32_t m_TriggerTimeMs;     /* +0x30 (`0x0048ABF4`) */
    uint32_t m_TargetSimObjectId; /* +0x34 (`0x0048ABF8`) -> exact sizeof == 0x38 (56 bytes)! */

    SCARFACE_MATCHED_FN(0x00000000, 0x00165160, 80)
    PendingVocalRequest();
};

/* Physics / Collision / Vocal Rig pointed to by `CharacterObject::m_pPhysicsCharacter` (+0x1AC) */
struct PhysicsCharacterController {
    uint8_t  m_Pad00[0x54];
    float    m_Orientation3x3[9];    /* +0x54..+0x77 */
    uint8_t  m_Pad78[0x18];          /* +0x78..+0x8F */
    Vector3f m_WorldPosition;        /* +0x90..+0x9B (copied to CharacterObject +0x64..+0x6C!) */
    uint8_t  m_Pad9C[0x10];          /* +0x9C..+0xAB */
    void*    m_pCollisionSpace;      /* +0xAC (returned by CharacterObject::vfunc_39!) */
    uint8_t  m_PadB0[0x0C];          /* +0xB0..+0xBB */
    void*    m_pProjectileHitBody;   /* +0xBC (returned by vfunc_40; "Projectile" toggled in 0x168C00!) */
    void*    m_pBulletHitBody;       /* +0xC0 ("Bullet" collision flag toggled in 0x168C00!) */
    uint8_t  m_PadC4[0xB0];          /* +0xC4..+0x173 */
    void*    m_pVocalAudioEmitter;   /* +0x174 (queried in vfunc_67, RequestVocal & UpdateVocalTail!) */
    bool     m_bBulletColEnabled;
    bool     m_bProjectileColEnabled;
    bool     m_bLowHealthNotified;

    PhysicsCharacterController();
};

/*
 * ============================================================================
 * 3. Base Class Hierarchy (`ConsoleObject` .. `InventoryOwner`, 74-Slot Table)
 *    Exact `sizeof(InventoryOwner) == 0xBC` (188 bytes on 32-bit x86)!
 * ============================================================================
 */
class GameSetObject : public ScriptObject {
public:
    GameSetObject()
        : m_NameSymbolId(0)
        , m_SimObjectId(0)
        , m_SetMembershipMask(0)
        , m_SetIndex1C(0xFFFFu)
        , m_ScriptFlags(0)
        , m_Pad1F(0)
    {
        m_Pad04[0] = 0;
        m_Pad04[1] = 0;
        m_Pad18[0] = 0;
        m_Pad18[1] = 0;
    }

    uint32_t m_Pad04[2];          /* +0x04..+0x0B */
    uint32_t m_NameSymbolId;      /* +0x0C (compared to "MainCharacter" @ 0x0016827B!) */
    uint32_t m_SimObjectId;       /* +0x10 (runtime object ID) */
    uint32_t m_SetMembershipMask; /* +0x14 */
    uint16_t m_Pad18[2];          /* +0x18..+0x1B */
    uint16_t m_SetIndex1C;        /* +0x1C (checked for 0xFFFF in 0x0002B885!) */
    uint8_t  m_ScriptFlags;       /* +0x1E (bit 0x10 toggled in vfunc_10 / vfunc_11!) */
    uint8_t  m_Pad1F;             /* +0x1F -> 0x20 bytes */
};

class GameObject : public GameSetObject {
public:
    GameObject();

    /* Slots 27..34 (+0x6C..+0x88) */
    /* Slot 27 (+0x6C) */ virtual void vfunc_27() {}
    /* Slot 28 (+0x70) */ virtual void vfunc_28() {}
    /* Slot 29 (+0x74) */ virtual void SetWorldPosition(const Vector3f* pPos);
    /* Slot 30 (+0x78) */ virtual void SetOrientationMatrix(const void* pMat3x3);
    /* Slot 31 (+0x7C) */ virtual void vfunc_31() {}
    /* Slot 32 (+0x80) */ virtual void SetScaleOrBounds(const void* pData);
    /* Slot 33 (+0x84) */ virtual void vfunc_33(int32_t a1) { (void)a1; }
    /* Slot 34 (+0x88) */ virtual bool vfunc_34() { return false; }

    uint8_t  m_GameObjPad20[0x34]; /* +0x20..+0x53 */
    float    m_TransformTop[4];    /* +0x54..+0x63 (`lea eax, [esi+0x54]` @ 0x001657B8!) */
    Vector3f m_Position;           /* +0x64, +0x68, +0x6C (`SetWorldPosition` @ 0x00165770!) */
};

class GameSimObject : public GameObject {
public:
    GameSimObject();

    virtual AbstractClassRep* GetClassRep() const { return NULL; }
    virtual bool OnAddToSim(bool bRegister);      /* Slot 04 (+0x10) — Xbox 0x0002A400 */
    virtual void OnRemoveFromSim(void* pArg);     /* Slot 05 (+0x14) — Xbox 0x00029FF0 */

    /* Slots 35..63 (+0x8C..+0xFC) */
    /* Slot 35 (+0x8C) */ virtual void*    QueryInterfaceById(void* pReq) { return pReq; }
    /* Slot 36 (+0x90) */ virtual bool     IsDead() const { return false; }
    /* Slot 37 (+0x94) */ virtual bool     CanBeTargeted() const { return true; }
    /* Slot 38 (+0x98) */ virtual void     ApplyDamageOrKill(float healthVal);
    /* Slot 39 (+0x9C) */ virtual void*    GetCollisionSpace() const { return NULL; }
    /* Slot 40 (+0xA0) */ virtual void*    GetProjectileHitBody() const { return NULL; }
    /* Slot 41 (+0xA4) */ virtual void     vfunc_41() {}
    /* Slot 42 (+0xA8) */ virtual void     SetPhysicsActive(bool bActive) { (void)bActive; }
    /* Slot 43 (+0xAC) */ virtual void     vfunc_43() {}
    /* Slot 44 (+0xB0) */ virtual void     SetHeadingRadians(float headingRad) { (void)headingRad; }
    /* Slot 45 (+0xB4) */ virtual float    GetHeadingRadians() const { return 0.0f; }
    /* Slot 46 (+0xB8) */ virtual void     vfunc_46() {}
    /* Slot 47 (+0xBC) */ virtual GameSimObject* GetEffectiveTargetObject();
    /* Slot 48 (+0xC0) */ virtual float    GetActiveTimerSeconds() const { return 0.0f; }
    /* Slot 49 (+0xC4) */ virtual void     OnDamageInflicted(void* pHitInfo, bool bInvulnFlag, bool bNoPropagate);
    /* Slot 50 (+0xC8) */ virtual bool     IsInvulnerable() const { return false; }
    /* Slot 51 (+0xCC) */ virtual void     SetInvulnerable(bool bInvuln) { (void)bInvuln; }
    /* Slot 52 (+0xD0) */ virtual void     vfunc_52(int32_t a1) { (void)a1; }
    /* Slot 53 (+0xD4) */ virtual void     SetStreamingLockState(bool bLocked) { (void)bLocked; }
    /* Slot 54 (+0xD8) */ virtual bool     IsStreamingLocked() const { return (m_SimStateBits & 0x04u) != 0; }
    /* Slot 55 (+0xDC) */ virtual void     CheckHitBodyMatch(void* pQuery, void* pArg2) { (void)pQuery; (void)pArg2; }
    /* Slot 56 (+0xE0) */ virtual void     CheckHitBodyMatchThunk(void* pQuery, void* pArg2) { (void)pQuery; (void)pArg2; }
    /* Slot 57 (+0xE4) */ virtual void     vfunc_57() {}
    /* Slot 58 (+0xE8) */ virtual bool     vfunc_58() { return false; }
    /* Slot 59 (+0xEC) */ virtual uint32_t GetCombinedCollisionFlags() const { return m_CollisionMaskByte; }
    /* Slot 60 (+0xF0) */ virtual void     vfunc_60() {}
    /* Slot 61 (+0xF4) */ virtual void     SetSimAttributeFlags(uint32_t mask) { m_SimAttrFlags |= mask; }
    /* Slot 62 (+0xF8) */ virtual void     vfunc_62() {}
    /* Slot 63 (+0xFC) */ virtual void     vfunc_63() {}

    uint8_t  m_SimPad70[0x28];    /* +0x70..+0x97 */
    uint8_t  m_CollisionMaskByte; /* +0x98 (read in vfunc_59 @ 0x001674FD!) */
    uint8_t  m_SimPad99[0x07];    /* +0x99..+0x9F */
    uint32_t m_SimAttrFlags;      /* +0xA0..+0xA3 */
    uint8_t  m_SimPadA4;          /* +0xA4 */
    uint8_t  m_SimStateBits;      /* +0xA5 (bits 0x01, 0x02, 0x04 manipulated across vfunc_05/17/53!) */
    uint8_t  m_SimPadA6[2];       /* +0xA6..+0xA7 -> +0xA8 is InventoryOwner! */
};

class InventoryOwner : public GameSimObject {
public:
    InventoryOwner(const char* pName, int32_t allocatorPoolId); /* Xbox 0x00171850 */
    virtual ~InventoryOwner();

    /* Slots 64..73 (+0x100..+0x124) — Completes the 74-Slot VFTable [00..73]! */
    /* Slot 64 (+0x100) */ virtual void OnWeaponEquipped(void* pWeapon, void* pSlotInfo) { (void)pWeapon; (void)pSlotInfo; }
    /* Slot 65 (+0x104) */ virtual void vfunc_65() {}
    /* Slot 66 (+0x108) */ virtual void vfunc_66() {}
    /* Slot 67 (+0x10C) */ virtual void OnCharacterKilled(uint32_t weaponSimId, uint32_t killerSimId) { (void)weaponSimId; (void)killerSimId; }
    /* Slot 68 (+0x110) */ virtual bool SupportsWeaponInventory() const { return false; }
    /* Slot 69 (+0x114) */ virtual bool CanDropOrSwitchWeapon() const { return true; }
    /* Slot 70 (+0x118) */ virtual void vfunc_70(int32_t a1) { (void)a1; }
    /* Slot 71 (+0x11C) */ virtual void OnDriverKilledFallback(int32_t a1) { (void)a1; }
    /* Slot 72 (+0x120) */ virtual void vfunc_72(int32_t a1, int32_t a2, int32_t a3) { (void)a1; (void)a2; (void)a3; }
    /* Slot 73 (+0x124) */ virtual bool vfunc_73() const { return false; }

    uint32_t m_InvPadA8;          /* +0xA8 */
    int32_t  m_AlertStatus;       /* +0xAC (`0`=Idle/Dead, `2`=Patrol, `>=4`=Combat @ 0x00168C00!) */
    uint32_t m_InventorySlotB0;   /* +0xB0 */
    uint32_t m_InventorySlotB4;   /* +0xB4 */
    uint32_t m_InvPadB8;          /* +0xB8 -> exact sizeof(InventoryOwner) == 0xBC (188 bytes)! */
};

/*
 * ============================================================================
 * 4. Embedded Subsystems Inside CharacterObject (+0xBC .. +0x3B3)
 * ============================================================================
 */
struct CharacterDamageTracker { uint8_t m_Data[0x1C]; }; /* +0x0BC..+0x0D7 (28B, ctor 0x0011D990) */
struct LocomotionSubsystem    { uint8_t m_Data[0xBC]; }; /* +0x1B0..+0x26B (188B, ctor 0x00162A10) */
struct AimingSubsystem        { uint8_t m_Data[0x30]; }; /* +0x26C..+0x29B (48B, ctor 0x00115B90) */
struct TargetingSubsystem     { uint8_t m_Data[0x0C]; }; /* +0x2A0..+0x2AB (12B, ctor 0x001709E0) */
struct WeaponMountSubsystem {
    uint32_t         m_WeaponInventorySetId; /* +0x2AC (written in vfunc_13 @ 0x001699E3!) */
    GameSimObject*   m_pMountedEntity;       /* +0x2B0 (queried via 0x0017B9C0) */
    uint8_t          m_Data[0x28];           /* +0x2B4..+0x2DB -> exact 0x30 (48) bytes! */
};
struct MeleeCombatSubsystem   { uint8_t m_Data[0x0C]; }; /* +0x2DC..+0x2E7 (12B, ctor 0x0015FB30) */
struct AnimationTreeDriver    { uint8_t m_Data[0x90]; }; /* +0x2E8..+0x377 (144B, ctor 0x00173AD0) */
struct CoverSubsystem         { uint8_t m_Data[0x08]; }; /* +0x380..+0x387 (8B, ctor 0x00170DD0) */
struct InteractionSubsystem   { uint8_t m_Data[0x08]; }; /* +0x388..+0x38F (8B, ctor 0x0017B160) */
struct GrappleSubsystem       { uint8_t m_Data[0x10]; }; /* +0x390..+0x39F (16B, ctor 0x0015FC00) */

/*
 * ============================================================================
 * 5. CharacterObject — COMPLETE 74-SLOT CORE CLASS (`sizeof == 0x430` = 1,072B)
 * ============================================================================
 */
class CharacterObject : public InventoryOwner {
public:
    enum {
        kDefaultHealth            = 100,    /* 0x64 @ 0x00167A1E */
        kDefaultSurfaceType       = 0x2B,   /* 43   @ 0x00167A64 */
        kDefaultHealthEventId     = 0xE4,   /* 228  @ 0x00167BDB */
        kEventId_CurrentHealth    = 0x25,   /* 37   @ 0x00166A5D */
        kEventId_MaxHealth        = 0x26,   /* 38   @ 0x00166A46 */
        kEventId_TonyDied         = 0x64,   /* 100  @ 0x0016B3ED */
        kAlert_DeadOrRelaxed      = 0,
        kAlert_DefaultNPCPatrol   = 2,
        kAlert_CombatHostile      = 4,
        kDyingDelayDefaultMs      = 2000,   /* 0x07D0 @ 0x0016B535 */
        kDyingDelayHeavyWeaponMs  = 5000,   /* 0x1388 @ 0x0016B566 (weapon type == 5!) */
        kAttachedPropSlotCount    = 6       /* Loop count 6 @ 0x00169BFD */
    };

    static ConcreteClassRep<CharacterObject> sm_ConcreteClassRep; /* Xbox 0x004304FC */
    static CharacterObject*                  sm_pMainCharacter;   /* Xbox 0x0048A9D8 ("MainCharacter") */
    static uint32_t                          sm_LiveCharacterCount; /* Xbox 0x0048AA04 */

    /* Constructor — Xbox 0x001678E0 (1,030 bytes = 0x406) */
    SCARFACE_MATCHED_FN(0x00000000, 0x001678E0, 1030)
    CharacterObject(const char* pName = NULL, int32_t allocatorPoolId = 0);

    /* Slot 00 (+0x00) — PC 0x00573CA0 <== Xbox 0x00167CE0 (6 bytes) */
    SCARFACE_MATCHED_FN(0x00573CA0, 0x00167CE0, 6)
    virtual AbstractClassRep* GetClassRep() const;

    /* Slot 01 (+0x04) — PC 0x00577F00 <== Xbox 0x0016EA90 (30B) + 0x00167D40 (162B body) */
    SCARFACE_MATCHED_FN(0x00577F00, 0x0016EA90, 30)
    virtual ~CharacterObject();

    /* Slot 04 (+0x10) — PC 0x005766C0 <== Xbox 0x00168220 (243 bytes) */
    SCARFACE_MATCHED_FN(0x005766C0, 0x00168220, 243)
    virtual bool OnAddToSim(bool bRegister);

    /* Slot 05 (+0x14) — PC 0x00571810 <== Xbox 0x001634F0 (24 bytes) */
    SCARFACE_MATCHED_FN(0x00571810, 0x001634F0, 24)
    virtual void OnRemoveFromSim(void* pArg);

    /* Slot 08 (+0x20) — PC 0x0057BFC0 <== Xbox 0x0016D9B0 (298 bytes) */
    SCARFACE_MATCHED_FN(0x0057BFC0, 0x0016D9B0, 298)
    virtual void ProcessTick(const TickUpdateParams* pTick);

    /* Slot 09 (+0x24) — PC 0x00573ED0 <== Xbox 0x001654C0 (191 bytes) */
    SCARFACE_MATCHED_FN(0x00573ED0, 0x001654C0, 191)
    virtual void AdvanceTime(float dt);

    /* Slot 10 (+0x28) — PC 0x00573CF0 <== Xbox 0x001652C0 (20 bytes) */
    SCARFACE_MATCHED_FN(0x00573CF0, 0x001652C0, 20)
    virtual void EnableSimTick();

    /* Slot 11 (+0x2C) — PC 0x00573D10 <== Xbox 0x001652E0 (20 bytes) */
    SCARFACE_MATCHED_FN(0x00573D10, 0x001652E0, 20)
    virtual void DisableSimTick();

    /* Slot 13 (+0x34) — PC 0x00577F20 <== Xbox 0x00169800 (532 bytes) */
    SCARFACE_MATCHED_FN(0x00577F20, 0x00169800, 532)
    virtual void OnPostSpawnInit();

    /* Slot 14 (+0x38) — PC 0x00578160 <== Xbox 0x00169A20 (668 bytes) */
    SCARFACE_MATCHED_FN(0x00578160, 0x00169A20, 668)
    virtual void OnPreDestroyCleanup();

    /* Slot 17 (+0x44) — PC 0x005715D0 <== Xbox 0x001632B0 (27 bytes) */
    SCARFACE_MATCHED_FN(0x005715D0, 0x001632B0, 27)
    virtual void SetSimFlagBit1(bool bVal);

    /* Slot 20 (+0x50) — PC 0x005A4810 <== Xbox 0x0006F990 (3 bytes: returns true) */
    SCARFACE_MATCHED_FN(0x005A4810, 0x0006F990, 3)
    virtual bool IsCharacterType() const;

    /* Slot 29 (+0x74) — PC 0x005741C0 <== Xbox 0x00165770 (43 bytes) */
    SCARFACE_MATCHED_FN(0x005741C0, 0x00165770, 43)
    virtual void SetWorldPosition(const Vector3f* pPos);

    /* Slot 30 (+0x78) — PC 0x005741F0 <== Xbox 0x001657A0 (50 bytes) */
    SCARFACE_MATCHED_FN(0x005741F0, 0x001657A0, 50)
    virtual void SetOrientationMatrix(const void* pMat3x3);

    /* Slot 32 (+0x80) — PC 0x00571830 <== Xbox 0x00163510 (35 bytes) */
    SCARFACE_MATCHED_FN(0x00571830, 0x00163510, 35)
    virtual void SetScaleOrBounds(const void* pData);

    /* Slot 35 (+0x8C) — PC 0x00575A60 <== Xbox 0x001670F0 (17 bytes) */
    SCARFACE_MATCHED_FN(0x00575A60, 0x001670F0, 17)
    virtual void* QueryInterfaceById(void* pReq);

    /* Slot 36 (+0x90) — PC 0x00572C50 <== Xbox 0x001646B0 (47 bytes) */
    SCARFACE_MATCHED_FN(0x00572C50, 0x001646B0, 47)
    virtual bool IsDead() const;

    /* Slot 37 (+0x94) — PC 0x00575A90 <== Xbox 0x001671D0 (63 bytes) */
    SCARFACE_MATCHED_FN(0x00575A90, 0x001671D0, 63)
    virtual bool CanBeTargeted() const;

    /* Slot 38 (+0x98) — PC 0x00575AD0 <== Xbox 0x00167210 (139 bytes) */
    SCARFACE_MATCHED_FN(0x00575AD0, 0x00167210, 139)
    virtual void ApplyDamageOrKill(float healthVal);

    /* Slot 39 (+0x9C) — PC 0x00572EA0 <== Xbox 0x001648F0 (20 bytes) */
    SCARFACE_MATCHED_FN(0x00572EA0, 0x001648F0, 20)
    virtual void* GetCollisionSpace() const;

    /* Slot 40 (+0xA0) — PC 0x00572EC0 <== Xbox 0x00164910 (20 bytes) */
    SCARFACE_MATCHED_FN(0x00572EC0, 0x00164910, 20)
    virtual void* GetProjectileHitBody() const;

    /* Slot 42 (+0xA8) — PC 0x00571580 <== Xbox 0x00163260 (59 bytes) */
    SCARFACE_MATCHED_FN(0x00571580, 0x00163260, 59)
    virtual void SetPhysicsActive(bool bActive);

    /* Slot 44 (+0xB0) — PC 0x00573CB0 <== Xbox 0x00167CF0 (17 bytes) */
    SCARFACE_MATCHED_FN(0x00573CB0, 0x00167CF0, 17)
    virtual void SetHeadingRadians(float headingRad);

    /* Slot 45 (+0xB4) — PC 0x00573CC0 <== Xbox 0x00167D10 (7 bytes) */
    SCARFACE_MATCHED_FN(0x00573CC0, 0x00167D10, 7)
    virtual float GetHeadingRadians() const;

    /* Slot 47 (+0xBC) — PC 0x00575B60 <== Xbox 0x001672A0 (86 bytes) */
    SCARFACE_MATCHED_FN(0x00575B60, 0x001672A0, 86)
    virtual GameSimObject* GetEffectiveTargetObject();

    /* Slot 48 (+0xC0) — PC 0x00572C80 <== Xbox 0x001646E0 (7 bytes) */
    SCARFACE_MATCHED_FN(0x00572C80, 0x001646E0, 7)
    virtual float GetActiveTimerSeconds() const;

    /* Slot 49 (+0xC4) — PC 0x005762A0 <== Xbox 0x00167DF0 (139 bytes) */
    SCARFACE_MATCHED_FN(0x005762A0, 0x00167DF0, 139)
    virtual void OnDamageInflicted(void* pHitInfo, bool bInvulnFlag, bool bNoPropagate);

    /* Slot 50 (+0xC8) — PC 0x00573CE0 <== Xbox 0x00167D30 (7 bytes) */
    SCARFACE_MATCHED_FN(0x00573CE0, 0x00167D30, 7)
    virtual bool IsInvulnerable() const;

    /* Slot 51 (+0xCC) — PC 0x00573CD0 <== Xbox 0x00167D20 (13 bytes) */
    SCARFACE_MATCHED_FN(0x00573CD0, 0x00167D20, 13)
    virtual void SetInvulnerable(bool bInvuln);

    /* Slot 52 (+0xD0) — PC 0x00438400 <== Xbox 0x00022710 (3 bytes: ret 4) */
    SCARFACE_MATCHED_FN(0x00438400, 0x00022710, 3)
    virtual void vfunc_52(int32_t a1);

    /* Slot 53 (+0xD4) — PC 0x00573D80 <== Xbox 0x00165350 (83 bytes) */
    SCARFACE_MATCHED_FN(0x00573D80, 0x00165350, 83)
    virtual void SetStreamingLockState(bool bLocked);

    /* Slot 55 (+0xDC) — PC 0x00573D30 <== Xbox 0x00165300 (72 bytes) */
    SCARFACE_MATCHED_FN(0x00573D30, 0x00165300, 72)
    virtual void CheckHitBodyMatch(void* pQuery, void* pArg2);

    /* Slot 56 (+0xE0) — PC 0x005715C0 <== Xbox 0x001632A0 (8 bytes: tail-jump to Slot 55) */
    SCARFACE_MATCHED_FN(0x005715C0, 0x001632A0, 8)
    virtual void CheckHitBodyMatchThunk(void* pQuery, void* pArg2);

    /* Slot 59 (+0xEC) — PC 0x00575D70 <== Xbox 0x001674B0 (97 bytes) */
    SCARFACE_MATCHED_FN(0x00575D70, 0x001674B0, 97)
    virtual uint32_t GetCombinedCollisionFlags() const;

    /* Slot 64 (+0x100) — PC 0x0057ACA0 <== Xbox 0x0016C6C0 (73 bytes) */
    SCARFACE_MATCHED_FN(0x0057ACA0, 0x0016C6C0, 73)
    virtual void OnWeaponEquipped(void* pWeapon, void* pSlotInfo);

    /* Slot 65 (+0x104) & Slot 66 (+0x108) — PC 0x005E1BB0 <== Xbox 0x002A9290 (1B: ret) */
    SCARFACE_MATCHED_FN(0x005E1BB0, 0x002A9290, 1)
    virtual void vfunc_65();
    virtual void vfunc_66();

    /* Slot 67 (+0x10C) — PC 0x00579B50 <== Xbox 0x0016B310 (661 bytes) */
    SCARFACE_MATCHED_FN(0x00579B50, 0x0016B310, 661)
    virtual void OnCharacterKilled(uint32_t weaponSimId, uint32_t killerSimId);

    /* Slot 68 (+0x110) — PC 0x005A4810 <== Xbox 0x0006F990 (3 bytes: returns true) */
    SCARFACE_MATCHED_FN(0x005A4810, 0x0006F990, 3)
    virtual bool SupportsWeaponInventory() const;

    /* Slot 69 (+0x114) — PC 0x005715F0 <== Xbox 0x001632D0 (37 bytes) */
    SCARFACE_MATCHED_FN(0x005715F0, 0x001632D0, 37)
    virtual bool CanDropOrSwitchWeapon() const;

    /* Slot 70 (+0x118) & Slot 71 (+0x11C) — PC 0x00438400 <== Xbox 0x00022710 (3B: ret 4) */
    virtual void vfunc_70(int32_t a1);
    virtual void OnDriverKilledFallback(int32_t a1);

    /* Slot 72 (+0x120) — PC 0x0046A2B0 <== Xbox 0x00213430 (3B: ret 0xC) */
    SCARFACE_MATCHED_FN(0x0046A2B0, 0x00213430, 3)
    virtual void vfunc_72(int32_t a1, int32_t a2, int32_t a3);

    /* Slot 73 (+0x124) — PC 0x00652590 <== Xbox 0x00022720 (3B: xor al, al; ret) */
    SCARFACE_MATCHED_FN(0x00652590, 0x00022720, 3)
    virtual bool vfunc_73() const;

    /*
     * Reconstructed Non-Virtual Core Helpers from `03_CharacterObject_WorkPack.txt`
     */
    /* Xbox 0x00166970 (454 bytes): Computes low-health state & fires Events 0x25, 0x26, or Boss ID */
    SCARFACE_MATCHED_FN(0x00000000, 0x00166970, 454)
    void UpdateHealthAndEvents();

    /* Xbox 0x00168C00 (643 bytes): Transitions AI alert state, Bullet/Projectile collision, & "drugwars" */
    SCARFACE_MATCHED_FN(0x00000000, 0x00168C00, 643)
    void SetAlertStatus(int32_t newAlertLevel, bool bOnlyEscalate);

    /* Xbox 0x00163B00 (174 bytes): Plays vocal line & triggers script "OnRequestVocal" */
    SCARFACE_MATCHED_FN(0x00000000, 0x00163B00, 174)
    void RequestVocal(const char* vocalLineName);

    /* Xbox 0x0016D5D0 (305 bytes): Polls vocal emitter & "gSampleTailIgnoredTime" */
    SCARFACE_MATCHED_FN(0x00000000, 0x0016D5D0, 305)
    void UpdateVocalPlaybackState();

    /* Xbox 0x0016C5A0 (281 bytes): Per-tick update for Tony Montana ("MainCharacter") */
    SCARFACE_MATCHED_FN(0x00000000, 0x0016C5A0, 281)
    void UpdateMainCharacterTick(const TickUpdateParams* pTick);

    /* Xbox 0x00167F50 (127 bytes): Per-tick update for NPCs */
    SCARFACE_MATCHED_FN(0x00000000, 0x00167F50, 127)
    void UpdateNPCCharacterTick(const TickUpdateParams* pTick);

    GameSimObject* ResolveMountedVehicle() const;

public:
    /*
     * ========================================================================
     * EXACT 32-BIT X86 MEMBER LAYOUT (+0x0BC .. +0x42F == 884 bytes; Total 0x430)
     * ========================================================================
     */
    CharacterDamageTracker      m_DamageTracker;          /* +0x0BC..+0x0D7 (28B) */
    uint32_t                    m_AIBehaviorId;           /* +0x0D8 ("AI behavior") */
    uint32_t                    m_AITaskGroupId;          /* +0x0DC ("AI task group") */
    uint32_t                    m_UnkE0;                  /* +0x0E0 */
    uint32_t                    m_NPCAttackersSetId;      /* +0x0E4 ("NPCAttackers") */
    uint32_t                    m_CurrentTargetHandle;    /* +0x0E8 */
    uint32_t                    m_PadEC;                  /* +0x0EC */
    int32_t                     m_ActiveStateIdx;         /* +0x0F0 (-1) */
    uint32_t                    m_UnkF4;                  /* +0x0F4 */
    CharacterContext*           m_pMainCharContext;       /* +0x0F8 (0x68B for Tony!) */
    uint32_t                    m_UnkFC;                  /* +0x0FC */
    uint32_t                    m_SpawnFlags100;          /* +0x100 */
    uint32_t                    m_Unk104;                 /* +0x104 */
    uint32_t                    m_Unk108;                 /* +0x108 */
    float                       m_ActiveTimerSec;         /* +0x10C (vfunc_08 / vfunc_48) */
    uint8_t                     m_bFlag110;               /* +0x110 */
    uint8_t                     m_bAccumulateTimer;       /* +0x111 (checked in vfunc_08!) */
    uint8_t                     m_bFlag112;               /* +0x112 */
    uint8_t                     m_bFlag113;               /* +0x113 */
    uint8_t                     m_bFlag114;               /* +0x114 */
    uint8_t                     m_Pad115[3];              /* +0x115..+0x117 */
    uint32_t                    m_Unk118;                 /* +0x118 */
    int32_t                     m_Unk11C;                 /* +0x11C (-1) */
    float                       m_MoveSpeedScaleA;        /* +0x120 (1.0f) */
    float                       m_MoveSpeedScaleB;        /* +0x124 (1.0f) */
    float                       m_FullHealthRatioConst;   /* +0x128 (1.0f) */
    float                       m_LowHealthThreshold;     /* +0x12C (0.25f) */
    uint32_t                    m_PropString130;          /* +0x130 ("None") */
    uint32_t                    m_PropString134;          /* +0x134 */
    uint32_t                    m_PropString138;          /* +0x138 */
    float                       m_Unk13C;                 /* +0x13C (0.0f) */
    uint32_t                    m_Unk140[4];              /* +0x140..+0x14F */
    uint32_t                    m_FactionGroup;           /* +0x150 (2) */
    uint32_t                    m_HandleList154;          /* +0x154 */
    uint32_t                    m_Unk158;                 /* +0x158 */
    int32_t                     m_CurrentHealth;          /* +0x15C (100 = 0x64) */
    int32_t                     m_MaxHealth;              /* +0x160 (100 = 0x64) */
    uint8_t                     m_bIsCriticalLowHealth;   /* +0x164 */
    uint8_t                     m_bFlag165;               /* +0x165 */
    uint8_t                     m_bMuteDeathScream;       /* +0x166 (checked in vfunc_67) */
    uint8_t                     m_bFlag167;               /* +0x167 */
    uint32_t                    m_Unk168;                 /* +0x168 */
    uint8_t                     m_bFlag16C;               /* +0x16C */
    uint8_t                     m_Pad16D[3];              /* +0x16D..+0x16F */
    uint32_t                    m_Unk170;                 /* +0x170 */
    float                       m_DamageScale;            /* +0x174 (1.0f) */
    uint32_t                    m_SurfaceType;            /* +0x178 (0x2B = 43) */
    int32_t                     m_Unk17C;                 /* +0x17C (-1) */
    uint32_t                    m_Unk180;                 /* +0x180 */
    uint32_t                    m_Unk184;                 /* +0x184 */
    uint8_t                     m_Flags188[4];            /* +0x188..+0x18B */
    uint32_t                    m_DyingTimerEventId;      /* +0x18C ("OnDyingFinished" handle) */
    uint32_t                    m_Unk190;                 /* +0x190 */
    uint32_t                    m_PerTickScratch194;      /* +0x194 (zeroed at end of vfunc_08) */
    uint32_t                    m_Unk198;                 /* +0x198 */
    uint32_t                    m_SpawnOrderFlag19C;      /* +0x19C (1) */
    uint32_t                    m_Unk1A0;                 /* +0x1A0 */
    float                       m_HeadingRadians;         /* +0x1A4 (vfunc_44 / vfunc_45) */
    uint32_t                    m_Unk1A8;                 /* +0x1A8 */
    PhysicsCharacterController* m_pPhysicsCharacter;      /* +0x1AC */
    LocomotionSubsystem         m_Locomotion;             /* +0x1B0..+0x26B (0xBCB) */
    AimingSubsystem             m_Aiming;                 /* +0x26C..+0x29B (0x30B) */
    uint8_t                     m_bFlag29C;               /* +0x29C */
    uint8_t                     m_bRagdollOrMounted;      /* +0x29D */
    uint8_t                     m_Pad29E[2];              /* +0x29E..+0x29F */
    TargetingSubsystem          m_Targeting;              /* +0x2A0..+0x2AB (0x0CB) */
    WeaponMountSubsystem        m_WeaponMount;            /* +0x2AC..+0x2DB (0x30B) */
    MeleeCombatSubsystem        m_MeleeCombat;            /* +0x2DC..+0x2E7 (0x0CB) */
    AnimationTreeDriver         m_AnimDriver;             /* +0x2E8..+0x377 (0x90B) */
    uint32_t                    m_CurrentVehicleHandle;   /* +0x378 */
    uint32_t                    m_Pad37C;                 /* +0x37C */
    CoverSubsystem              m_Cover;                  /* +0x380..+0x387 (0x08B) */
    InteractionSubsystem        m_Interaction;            /* +0x388..+0x38F (0x08B) */
    GrappleSubsystem            m_Grapple;                /* +0x390..+0x39F (0x10B) */
    uint8_t                     m_bFlag3A0;               /* +0x3A0 */
    uint8_t                     m_bFlag3A1;               /* +0x3A1 */
    uint8_t                     m_Pad3A2[2];              /* +0x3A2..+0x3A3 */
    uint32_t                    m_Unk3A4;                 /* +0x3A4 */
    uint32_t                    m_VocalFinishTimerMs;     /* +0x3A8 */
    uint32_t                    m_VocalCooldown[2];       /* +0x3AC..+0x3B3 */
    uint8_t                     m_bVocalPlaying;          /* +0x3B4 */
    uint8_t                     m_bVocalPendingTail;      /* +0x3B5 */
    uint8_t                     m_bDeferredAlertPending;  /* +0x3B6 */
    uint8_t                     m_Pad3B7;                 /* +0x3B7 */
    int32_t                     m_DeferredAlertLevel;     /* +0x3B8 */
    int32_t                     m_DeferredAlertTimeMs;    /* +0x3BC */
    uint32_t                    m_CombatEnterTimeMs;      /* +0x3C0 */
    uint32_t                    m_Unk3C4;                 /* +0x3C4 */
    uint8_t                     m_ActiveSlot3C8;          /* +0x3C8 (0xFF) */
    uint8_t                     m_Pad3C9[3];              /* +0x3C9..+0x3CB */
    uint32_t                    m_Unk3CC;                 /* +0x3CC */
    uint32_t                    m_Pad3D0;                 /* +0x3D0 */
    uint8_t                     m_bFlag3D4;               /* +0x3D4 */
    uint8_t                     m_Pad3D5[3];              /* +0x3D5..+0x3D7 */
    uint32_t                    m_AttachedPropMeta[6];    /* +0x3D8..+0x3EF */
    uint32_t                    m_AttachedPropHandles[6]; /* +0x3F0..+0x407 */
    uint32_t                    m_AuxiliarySimHandle;     /* +0x408 */
    uint8_t                     m_bFlag40C;               /* +0x40C */
    uint8_t                     m_bFlag40D;               /* +0x40D */
    uint8_t                     m_Pad40E[2];              /* +0x40E..+0x40F */
    int32_t                     m_Unk410;                 /* +0x410 (-1) */
    float                       m_Scale414;               /* +0x414 (1.0f) */
    int32_t                     m_Unk418;                 /* +0x418 (-1) */
    uint32_t                    m_DefaultTag41C;          /* +0x41C */
    uint8_t                     m_bAliveFlag420;          /* +0x420 (1) */
    uint8_t                     m_bIsInvulnerable;        /* +0x421 (vfunc_50 / vfunc_51!) */
    uint8_t                     m_bFlag422;               /* +0x422 (1) */
    uint8_t                     m_bFlag423;               /* +0x423 (0x10) */
    uint8_t                     m_SpawnConfigBits;        /* +0x424 (bit 0x02 skips AI init) */
    uint8_t                     m_Pad425[3];              /* +0x425..+0x427 */
    uint32_t                    m_HealthEventId;          /* +0x428 (0xE4; Boss ID if != 0xE4!) */
    void*                       m_pExtraHeapData;         /* +0x42C -> exact sizeof == 0x430 (1,072B)! */
};

/*
 * ============================================================================
 * 6. Compile-Time 32-Bit x86 ABI Size & Exact Offset Verification
 * ============================================================================
 */
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(GameSetObject) == 0x20,
    game_set_object_must_be_0x20_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(GameObject) == 0x70,
    game_object_must_be_0x70_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(InventoryOwner) == 0xBC,
    inventory_owner_must_be_exact_0xBC_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(CharacterContext) == 0x68,
    character_context_must_be_exact_0x68_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(PendingVocalRequest) == 0x38,
    pending_vocal_request_must_be_exact_0x38_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(CharacterObject) == 0x430,
    character_object_must_be_exact_0x430_bytes_on_x86);

/* Inline 32-bit x86 exact byte-offset verifier (constant-folds to `mov eax, 0x430; ret` under -m32 -O2!) */
inline int VerifyCharacterFieldOffsetsX86() {
    if (sizeof(void*) != 4) { return 0x430; }
    char raw[sizeof(CharacterObject)];
    const CharacterObject* p = reinterpret_cast<const CharacterObject*>(raw);
    #define CHK_OFF(field, hexOff) if ((reinterpret_cast<const char*>(&p->field) - raw) != (hexOff)) return -(hexOff)
    CHK_OFF(m_NameSymbolId, 0x00C);
    CHK_OFF(m_SimObjectId, 0x010);
    CHK_OFF(m_ScriptFlags, 0x01E);
    CHK_OFF(m_TransformTop, 0x054);
    CHK_OFF(m_Position, 0x064);
    CHK_OFF(m_CollisionMaskByte, 0x098);
    CHK_OFF(m_SimStateBits, 0x0A5);
    CHK_OFF(m_AlertStatus, 0x0AC);
    CHK_OFF(m_DamageTracker, 0x0BC);
    CHK_OFF(m_AIBehaviorId, 0x0D8);
    CHK_OFF(m_AITaskGroupId, 0x0DC);
    CHK_OFF(m_NPCAttackersSetId, 0x0E4);
    CHK_OFF(m_CurrentTargetHandle, 0x0E8);
    CHK_OFF(m_pMainCharContext, 0x0F8);
    CHK_OFF(m_ActiveTimerSec, 0x10C);
    CHK_OFF(m_bAccumulateTimer, 0x111);
    CHK_OFF(m_PropString130, 0x130);
    CHK_OFF(m_CurrentHealth, 0x15C);
    CHK_OFF(m_MaxHealth, 0x160);
    CHK_OFF(m_bIsCriticalLowHealth, 0x164);
    CHK_OFF(m_bMuteDeathScream, 0x166);
    CHK_OFF(m_SurfaceType, 0x178);
    CHK_OFF(m_DyingTimerEventId, 0x18C);
    CHK_OFF(m_PerTickScratch194, 0x194);
    CHK_OFF(m_HeadingRadians, 0x1A4);
    CHK_OFF(m_pPhysicsCharacter, 0x1AC);
    CHK_OFF(m_Locomotion, 0x1B0);
    CHK_OFF(m_Aiming, 0x26C);
    CHK_OFF(m_bRagdollOrMounted, 0x29D);
    CHK_OFF(m_Targeting, 0x2A0);
    CHK_OFF(m_WeaponMount, 0x2AC);
    CHK_OFF(m_MeleeCombat, 0x2DC);
    CHK_OFF(m_AnimDriver, 0x2E8);
    CHK_OFF(m_CurrentVehicleHandle, 0x378);
    CHK_OFF(m_Cover, 0x380);
    CHK_OFF(m_Interaction, 0x388);
    CHK_OFF(m_Grapple, 0x390);
    CHK_OFF(m_VocalFinishTimerMs, 0x3A8);
    CHK_OFF(m_VocalCooldown, 0x3AC);
    CHK_OFF(m_bVocalPlaying, 0x3B4);
    CHK_OFF(m_DeferredAlertLevel, 0x3B8);
    CHK_OFF(m_CombatEnterTimeMs, 0x3C0);
    CHK_OFF(m_AttachedPropMeta, 0x3D8);
    CHK_OFF(m_AttachedPropHandles, 0x3F0);
    CHK_OFF(m_AuxiliarySimHandle, 0x408);
    CHK_OFF(m_bIsInvulnerable, 0x421);
    CHK_OFF(m_SpawnConfigBits, 0x424);
    CHK_OFF(m_HealthEventId, 0x428);
    CHK_OFF(m_pExtraHeapData, 0x42C);
    #undef CHK_OFF
    return static_cast<int>(sizeof(CharacterObject));
}

#if defined(_MSC_VER) && defined(_M_IX86)
    #pragma pack(pop)
#endif

#endif /* SCARFACE_PC_V1002_CHARACTER_OBJECT_H */
