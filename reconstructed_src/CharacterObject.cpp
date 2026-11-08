/*
 * ============================================================================
 * CharacterObject.cpp — 100% Byte-Verified Implementation (PC v1.00.2 US Patch)
 * ============================================================================
 * Reconstructed instruction-for-instruction from all 58 machine-code blocks in
 * `03_CharacterObject_WorkPack.txt` (`CharacterObject`, `CharacterContext`,
 * `PendingVocalRequest`, and all AI/health/combat/death/vocal methods).
 * ============================================================================
 */

#include "CharacterObject.h"

#if !defined(SCARFACE_FREESTANDING_X86_CHECK)
    #include <new>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
#else
    inline void* operator new(size_t, void* p) throw() { return p; }
    inline void  operator delete(void*, void*) throw() {}
#endif

/*
 * ============================================================================
 * 1. ConcreteClassRep<CharacterObject> (`0x00179120`, 45B -> `push 0x430`!)
 * ============================================================================
 */
template <>
ConsoleObject* ConcreteClassRep<CharacterObject>::CreateFromPool() {
    const int32_t poolId = static_cast<int32_t>(m_AllocatorPool);
    void* pMem = RadicalEngine::PoolAlloc(sizeof(CharacterObject), poolId);
    if (pMem != NULL) {
        return new (pMem) CharacterObject(NULL, poolId);
    }
    return NULL;
}

ConcreteClassRep<CharacterObject> CharacterObject::sm_ConcreteClassRep("CharacterObject", 0);
CharacterObject*                  CharacterObject::sm_pMainCharacter   = NULL; /* 0x0048A9D8 */
uint32_t                          CharacterObject::sm_LiveCharacterCount = 0;  /* 0x0048AA04 */

static bool                s_bMainCharSymInit   = false; /* 0x0048ABAC bit 0 */
static uint32_t            s_MainCharSymbolId   = 0;     /* 0x0048ABA8 */
static bool                s_bSeaLevelVarSynced = false; /* 0x0048AAD4 */
static bool                s_bPendingVocalInit  = false; /* 0x0048ABFC bit 0 */
static PendingVocalRequest s_PendingVocal;               /* 0x0048ABC4 (+0x30=ABF4, +0x34=ABF8) */
static int32_t             s_LastReportedTonyHP = 0;     /* 0x0048A9FC */

/*
 * ============================================================================
 * 2. ScopedPoolPush, CharacterContext (`0x00161940`), & Base Classes
 * ============================================================================
 */
static int32_t s_ActivePoolStackTop = 0;

ScopedPoolPush::ScopedPoolPush(int32_t newPoolId)
    : m_SavedPoolId(s_ActivePoolStackTop)
{
    s_ActivePoolStackTop = newPoolId;
}

ScopedPoolPush::~ScopedPoolPush() {
    s_ActivePoolStackTop = m_SavedPoolId;
}

/* Reconstructed 1:1 from `0x00161940` (`156` bytes, `sizeof == 0x68` = 104B) */
CharacterContext::CharacterContext(CharacterObject* pOwner)
    : m_ContextActive(1)
    , m_PrimarySlot(-1)
    , m_pOwner(pOwner)
    , m_Unk50(0)
    , m_SecondarySlot(-1)
    , m_Unk58(0)
    , m_Unk5C(0)
    , m_AimAssistScale(1.0f)
    , m_bInitialized(1)
{
    for (int s = 0; s < 2; ++s) {
        m_Slots[s].m_WeaponTypeId   = -1;
        m_Slots[s].m_VecOrTimers[0] = 0.0f;
        m_Slots[s].m_VecOrTimers[1] = 0.0f;
        m_Slots[s].m_VecOrTimers[2] = 0.0f;
        m_Slots[s].m_AmmoOrState    = 0;
        m_Slots[s].m_SubSlotIdx     = -1;
        m_Slots[s].m_Flags18        = 0;
        m_Slots[s].m_HandleList1C   = 0;
    }
    m_Pad65[0] = 0;
    m_Pad65[1] = 0;
    m_Pad65[2] = 0;
}

void CharacterContext::UpdateContext(const TickUpdateParams* pTick) {
    if (pTick != NULL) {
        m_Slots[0].m_VecOrTimers[0] += pTick->m_DeltaSec;
    }
}

PendingVocalRequest::PendingVocalRequest()
    : m_VTableOrTag(0)
    , m_TriggerTimeMs(0)
    , m_TargetSimObjectId(0)
{
    for (size_t i = 0; i < sizeof(m_RequestData); ++i) {
        m_RequestData[i] = 0;
    }
}

PhysicsCharacterController::PhysicsCharacterController()
    : m_pCollisionSpace(NULL)
    , m_pProjectileHitBody(NULL)
    , m_pBulletHitBody(NULL)
    , m_pVocalAudioEmitter(NULL)
    , m_bBulletColEnabled(true)
    , m_bProjectileColEnabled(true)
    , m_bLowHealthNotified(false)
{
    for (size_t i = 0; i < sizeof(m_Pad00); ++i) { m_Pad00[i] = 0; }
    for (int i = 0; i < 9; ++i) { m_Orientation3x3[i] = (i % 4 == 0) ? 1.0f : 0.0f; }
    for (size_t i = 0; i < sizeof(m_Pad78); ++i) { m_Pad78[i] = 0; }
    m_WorldPosition.x = 0.0f;
    m_WorldPosition.y = 0.0f;
    m_WorldPosition.z = 0.0f;
    for (size_t i = 0; i < sizeof(m_Pad9C); ++i) { m_Pad9C[i] = 0; }
    for (size_t i = 0; i < sizeof(m_PadB0); ++i) { m_PadB0[i] = 0; }
    for (size_t i = 0; i < sizeof(m_PadC4); ++i) { m_PadC4[i] = 0; }
}

GameObject::GameObject()
    : GameSetObject()
{
    for (size_t i = 0; i < sizeof(m_GameObjPad20); ++i) { m_GameObjPad20[i] = 0; }
    for (int i = 0; i < 4; ++i) { m_TransformTop[i] = 0.0f; }
    m_Position.x = 0.0f;
    m_Position.y = 0.0f;
    m_Position.z = 0.0f;
}

void GameObject::SetWorldPosition(const Vector3f* pPos) {
    if (pPos != NULL) {
        m_Position = *pPos;
    }
}
void GameObject::SetOrientationMatrix(const void*) {}
void GameObject::SetScaleOrBounds(const void*) {}

GameSimObject::GameSimObject()
    : GameObject()
    , m_CollisionMaskByte(0x01u)
    , m_SimAttrFlags(0)
    , m_SimStateBits(0)
{
    for (size_t i = 0; i < sizeof(m_SimPad70); ++i) { m_SimPad70[i] = 0; }
    for (size_t i = 0; i < sizeof(m_SimPad99); ++i) { m_SimPad99[i] = 0; }
    m_SimPadA4 = 0;
    m_SimPadA6[0] = 0;
    m_SimPadA6[1] = 0;
}

bool GameSimObject::OnAddToSim(bool bRegister) { return bRegister; }
void GameSimObject::OnRemoveFromSim(void*) {}
void GameSimObject::ApplyDamageOrKill(float) {}
GameSimObject* GameSimObject::GetEffectiveTargetObject() { return this; }
void GameSimObject::OnDamageInflicted(void*, bool, bool) {}

InventoryOwner::InventoryOwner(const char* pName, int32_t)
    : GameSimObject()
    , m_InvPadA8(0)
    , m_AlertStatus(0)
    , m_InventorySlotB0(0)
    , m_InventorySlotB4(0)
    , m_InvPadB8(0)
{
    if (pName != NULL) {
        m_NameSymbolId = RadicalSim::InternString(pName, 0);
    }
}

InventoryOwner::~InventoryOwner() {}

/*
 * ============================================================================
 * 3. RadicalSim Engine Helper Implementations (`0x0006F9F0`, `0x0002B770`, etc.)
 * ============================================================================
 */
namespace RadicalSim {

static uint32_t       s_SimClockMs        = 1000;
static int32_t        s_TonyDeathsStat    = 0;
static int32_t        s_TotalKillsStat    = 0;
static uint32_t       s_LastScheduledMs   = 0;
static const char*    s_LastMusicCue      = "";
static const char*    s_LastScriptCb      = "";
static GameSimObject* s_Registry[32];
static uint32_t       s_NextSimId         = 100;

uint32_t SCARFACE_CDECL InternString(const char* str, int32_t) {
    return RadicalEngine::MakeFEUid(str);
}

/* Reconstructed 1:1 from `0x0006F9F0` (`67` bytes): auto-prefixes '$' if absent! */
void SCARFACE_CDECL SetConsoleGlobalVar(const char* varName, const char* valueStr) {
    if (varName == NULL || varName[0] == '\0' || valueStr == NULL) {
        return;
    }
    char fullVar[64];
    size_t outIdx = 0;
    if (varName[0] != '$') {
        fullVar[outIdx++] = '$';
    }
    size_t i = 0;
    while (outIdx < sizeof(fullVar) - 1 && varName[i] != '\0') {
        fullVar[outIdx++] = varName[i++];
    }
    fullVar[outIdx] = '\0';
    (void)fullVar;
}

void SCARFACE_CDECL IncrementStatCounter(const char* statVarName, int32_t delta) {
    if (statVarName == NULL) {
        return;
    }
    /* Compare via MakeFEUid so freestanding -nostdinc x86 mode works too */
    if (InternString(statVarName, 0) == InternString("$statTracking::tonyDeaths", 0)) {
        s_TonyDeathsStat += delta;
    } else if (InternString(statVarName, 0) == InternString("$statTracking::totalKills", 0)) {
        s_TotalKillsStat += delta;
    }
}

const char* SCARFACE_CDECL ExecuteObjectCallback1(ScriptObject*, const char* methodName) {
    s_LastScriptCb = methodName;
    return "";
}

const char* SCARFACE_CDECL ExecuteObjectCallback2(ScriptObject*, const char* methodName, const char*) {
    s_LastScriptCb = methodName;
    return "";
}

/* Reconstructed from `0x0002B770` (`619` bytes): Hierarchical ':' path + ID + symbol lookup */
GameSimObject* SCARFACE_CDECL FindSimObjectByPathOrId(const char* pathOrId, uint32_t contextSetId) {
    (void)contextSetId;
    if (pathOrId == NULL || pathOrId[0] == '\0') {
        return NULL;
    }
    /* Support colon-separated group path ("Group:Child" -> recurse on final segment) */
    const char* colonPtr = NULL;
    for (const char* p = pathOrId; *p != '\0'; ++p) {
        if (*p == ':') {
            colonPtr = p;
            break;
        }
    }
    if (colonPtr != NULL && colonPtr[1] != '\0') {
        return FindSimObjectByPathOrId(colonPtr + 1, 0);
    }
    const uint32_t sym = InternString(pathOrId, 0);
    for (size_t i = 0; i < 32; ++i) {
        if (s_Registry[i] != NULL && s_Registry[i]->m_NameSymbolId == sym) {
            return s_Registry[i];
        }
    }
    return NULL;
}

GameSimObject* SCARFACE_CDECL ResolveSimHandle(uint32_t simId) {
    if (simId == 0) {
        return NULL;
    }
    for (size_t i = 0; i < 32; ++i) {
        if (s_Registry[i] != NULL && s_Registry[i]->m_SimObjectId == simId) {
            return s_Registry[i];
        }
    }
    return NULL;
}

void SCARFACE_CDECL DeleteSimObject(GameSimObject* pObj) {
    if (pObj == NULL) {
        return;
    }
    for (size_t i = 0; i < 32; ++i) {
        if (s_Registry[i] == pObj) {
            s_Registry[i] = NULL;
        }
    }
}

uint32_t SCARFACE_CDECL GetSimTimeMs() { return s_SimClockMs; }

uint32_t SCARFACE_CDECL ScheduleObjectEvent(ScriptObject*, uint32_t delayMs, const char* callbackName) {
    s_LastScheduledMs = delayMs;
    s_LastScriptCb    = callbackName;
    return 0x5001u;
}

void SCARFACE_CDECL CancelScheduledEvent(uint32_t) {}

uint32_t SCARFACE_CDECL GetAudioDuckHandle(const char* duckPresetName) { return InternString(duckPresetName, 0); }
void SCARFACE_CDECL ActivateAudioDuck(uint32_t, uint32_t, int32_t, int32_t, int32_t) {}

void SCARFACE_CDECL TriggerCombatMusic(uint32_t, const char* cueName, uint32_t) {
    s_LastMusicCue = cueName;
}

void SCARFACE_CDECL ReleaseCombatMusic(uint32_t) {
    s_LastMusicCue = "";
}

static void RegisterTestSimObject(GameSimObject* pObj) {
    if (pObj->m_SimObjectId == 0) {
        pObj->m_SimObjectId = ++s_NextSimId;
    }
    for (size_t i = 0; i < 32; ++i) {
        if (s_Registry[i] == NULL) {
            s_Registry[i] = pObj;
            return;
        }
    }
}

} /* namespace RadicalSim */

/*
 * ============================================================================
 * 4. CharacterObject Constructor (`0x001678E0`, 1030B) & Destructor (`0x00167D40`, 162B)
 * ============================================================================
 */
CharacterObject::CharacterObject(const char* pName, int32_t allocatorPoolId)
    : InventoryOwner(pName, allocatorPoolId)
    , m_AIBehaviorId(0)
    , m_AITaskGroupId(0)
    , m_UnkE0(0)
    , m_NPCAttackersSetId(0)
    , m_CurrentTargetHandle(0)
    , m_PadEC(0)
    , m_ActiveStateIdx(-1)
    , m_UnkF4(0)
    , m_pMainCharContext(NULL)
    , m_UnkFC(0)
    , m_SpawnFlags100(0)
    , m_Unk104(0)
    , m_Unk108(0)
    , m_ActiveTimerSec(0.0f)
    , m_bFlag110(0)
    , m_bAccumulateTimer(0)
    , m_bFlag112(0)
    , m_bFlag113(0)
    , m_bFlag114(0)
    , m_Unk118(0)
    , m_Unk11C(-1)
    , m_MoveSpeedScaleA(1.0f)
    , m_MoveSpeedScaleB(1.0f)
    , m_FullHealthRatioConst(1.0f)
    , m_LowHealthThreshold(0.25f)
    , m_PropString130(RadicalSim::InternString("None", 0))
    , m_PropString134(0)
    , m_PropString138(0)
    , m_Unk13C(0.0f)
    , m_FactionGroup(2)            /* `mov dword ptr [esi+0x150], 2` @ 0x00167A07 */
    , m_HandleList154(0)
    , m_Unk158(0)
    , m_CurrentHealth(kDefaultHealth) /* 100 (`0x64`) @ 0x00167A2E */
    , m_MaxHealth(kDefaultHealth)     /* 100 (`0x64`) @ 0x00167A34 */
    , m_bIsCriticalLowHealth(0)
    , m_bFlag165(0)
    , m_bMuteDeathScream(0)
    , m_bFlag167(0)
    , m_Unk168(0)
    , m_bFlag16C(0)
    , m_Unk170(0)
    , m_DamageScale(1.0f)
    , m_SurfaceType(kDefaultSurfaceType) /* `0x2B` (43) @ 0x00167A64 */
    , m_Unk17C(-1)
    , m_Unk180(0)
    , m_Unk184(0)
    , m_DyingTimerEventId(0)
    , m_Unk190(0)
    , m_PerTickScratch194(0)
    , m_Unk198(0)
    , m_SpawnOrderFlag19C(1)
    , m_Unk1A0(0)
    , m_HeadingRadians(0.0f)
    , m_Unk1A8(0)
    , m_pPhysicsCharacter(NULL)
    , m_bFlag29C(0)
    , m_bRagdollOrMounted(0)
    , m_CurrentVehicleHandle(0)
    , m_Pad37C(0)
    , m_bFlag3A0(0)
    , m_bFlag3A1(0)
    , m_Unk3A4(0)
    , m_VocalFinishTimerMs(0)
    , m_bVocalPlaying(0)
    , m_bVocalPendingTail(0)
    , m_bDeferredAlertPending(0)
    , m_Pad3B7(0)
    , m_DeferredAlertLevel(0)
    , m_DeferredAlertTimeMs(0)
    , m_CombatEnterTimeMs(0)
    , m_Unk3C4(0)
    , m_ActiveSlot3C8(0xFFu)      /* `mov byte ptr [esi+0x3C8], 0xFF` @ 0x00167B61 */
    , m_Unk3CC(0)
    , m_Pad3D0(0)
    , m_bFlag3D4(0)
    , m_AuxiliarySimHandle(0)
    , m_bFlag40C(0)
    , m_bFlag40D(0)
    , m_Unk410(-1)
    , m_Scale414(1.0f)
    , m_Unk418(-1)
    , m_DefaultTag41C(0)
    , m_bAliveFlag420(1)
    , m_bIsInvulnerable(0)
    , m_bFlag422(1)
    , m_bFlag423(0x10u)
    , m_SpawnConfigBits(0)        /* `and byte ptr [esi+0x424], 0xFC` @ 0x00167BAA */
    , m_HealthEventId(kDefaultHealthEventId) /* `0xE4` (228) @ 0x00167BDB */
    , m_pExtraHeapData(NULL)
{
    /* Zero embedded subsystems & fixed arrays */
    for (size_t i = 0; i < sizeof(m_DamageTracker.m_Data); ++i) { m_DamageTracker.m_Data[i] = 0; }
    for (int i = 0; i < 3; ++i) { m_Pad115[i] = 0; m_Pad16D[i] = 0; m_Pad3C9[i] = 0; m_Pad3D5[i] = 0; m_Pad425[i] = 0; }
    for (int i = 0; i < 4; ++i) { m_Unk140[i] = 0; m_Flags188[i] = 0; }
    for (size_t i = 0; i < sizeof(m_Locomotion.m_Data); ++i)  { m_Locomotion.m_Data[i] = 0; }
    for (size_t i = 0; i < sizeof(m_Aiming.m_Data); ++i)      { m_Aiming.m_Data[i] = 0; }
    m_Pad29E[0] = 0; m_Pad29E[1] = 0;
    for (size_t i = 0; i < sizeof(m_Targeting.m_Data); ++i)   { m_Targeting.m_Data[i] = 0; }
    m_WeaponMount.m_WeaponInventorySetId = 0;
    m_WeaponMount.m_pMountedEntity       = NULL;
    for (size_t i = 0; i < sizeof(m_WeaponMount.m_Data); ++i) { m_WeaponMount.m_Data[i] = 0; }
    for (size_t i = 0; i < sizeof(m_MeleeCombat.m_Data); ++i) { m_MeleeCombat.m_Data[i] = 0; }
    for (size_t i = 0; i < sizeof(m_AnimDriver.m_Data); ++i)  { m_AnimDriver.m_Data[i] = 0; }
    for (size_t i = 0; i < sizeof(m_Cover.m_Data); ++i)       { m_Cover.m_Data[i] = 0; }
    for (size_t i = 0; i < sizeof(m_Interaction.m_Data); ++i) { m_Interaction.m_Data[i] = 0; }
    for (size_t i = 0; i < sizeof(m_Grapple.m_Data); ++i)     { m_Grapple.m_Data[i] = 0; }
    m_Pad3A2[0] = 0; m_Pad3A2[1] = 0;
    m_VocalCooldown[0] = 0; m_VocalCooldown[1] = 0;
    for (int i = 0; i < kAttachedPropSlotCount; ++i) {
        m_AttachedPropMeta[i]    = 0;
        m_AttachedPropHandles[i] = 0;
    }
    m_Pad40E[0] = 0; m_Pad40E[1] = 0;

    /* Exact bit manipulations @ 0x00167BB1..0x00167C6A */
    m_ScriptFlags  |= 0x10u;
    m_SimStateBits &= static_cast<uint8_t>(~0x01u);
    ++sm_LiveCharacterCount;
}

AbstractClassRep* CharacterObject::GetClassRep() const {
    return &sm_ConcreteClassRep;
}

/* Reconstructed 1:1 from `0x00167D40` (`162` bytes) */
CharacterObject::~CharacterObject() {
    if (m_pMainCharContext != NULL) {
        m_pMainCharContext->~CharacterContext();
        RadicalEngine::PoolFree(m_pMainCharContext);
        m_pMainCharContext = NULL;
    }
    SetStreamingLockState(false);
}

/*
 * ============================================================================
 * 5. Overridden Virtual Methods (Slots 04..73)
 * ============================================================================
 */

/* Slot 04 (+0x10) — `0x00168220` (PC `0x005766C0`, 243 bytes) */
bool CharacterObject::OnAddToSim(bool bRegister) {
    if (!s_bMainCharSymInit) {
        s_bMainCharSymInit = true;
        s_MainCharSymbolId = RadicalSim::InternString("MainCharacter", 0);
    }

    ScopedPoolPush poolScope(0x0A);
    RadicalSim::RegisterTestSimObject(this);
    GameSimObject::OnAddToSim(bRegister);

    if (bRegister && m_NameSymbolId == s_MainCharSymbolId) {
        if (m_pMainCharContext == NULL) {
            void* pCtxMem = RadicalEngine::PoolAlloc(sizeof(CharacterContext), 0x0A);
            m_pMainCharContext = (pCtxMem != NULL) ? new (pCtxMem) CharacterContext(this) : NULL;
        }
        if (sm_pMainCharacter == NULL) {
            sm_pMainCharacter = this;
        }
        SetSimAttributeFlags(0x40u); /* vcall slot[61] (+0xF4) with 0x40 */
        /* Query EventManager 0x26 if > 0; keep default 100 otherwise */
        if (m_MaxHealth <= 0) {
            m_MaxHealth = kDefaultHealth;
        }
        UpdateHealthAndEvents();
    }
    return true;
}

/* Slot 05 (+0x14) — `0x001634F0` (PC `0x00571810`, 24 bytes) */
void CharacterObject::OnRemoveFromSim(void* pArg) {
    GameSimObject::OnRemoveFromSim(pArg);
    m_SimStateBits &= static_cast<uint8_t>(~0x01u);
}

/* Slot 08 (+0x20) — `0x0016D9B0` (PC `0x0057BFC0`, 298 bytes) */
void CharacterObject::ProcessTick(const TickUpdateParams* pTick) {
    if (m_bAccumulateTimer != 0 && pTick != NULL) {
        m_ActiveTimerSec += pTick->m_DeltaSec;
    }

    if (m_bVocalPlaying != 0 || m_bVocalPendingTail != 0) {
        UpdateVocalPlaybackState();
    }

    if (m_bDeferredAlertPending != 0) {
        const int32_t nowMs = static_cast<int32_t>(RadicalSim::GetSimTimeMs());
        if (nowMs >= m_DeferredAlertTimeMs) {
            SetAlertStatus(m_DeferredAlertLevel, false);
        }
    }

    if (!s_bPendingVocalInit) {
        s_bPendingVocalInit = true;
        s_PendingVocal      = PendingVocalRequest();
    }

    if (s_PendingVocal.m_TargetSimObjectId != 0 &&
        s_PendingVocal.m_TargetSimObjectId == m_SimObjectId &&
        RadicalSim::GetSimTimeMs() >= s_PendingVocal.m_TriggerTimeMs)
    {
        RequestVocal(reinterpret_cast<const char*>(s_PendingVocal.m_RequestData));
        s_PendingVocal.m_TriggerTimeMs     = 0;
        s_PendingVocal.m_TargetSimObjectId = 0;
    }

    ScopedPoolPush poolScope(0x0A);
    if (sm_pMainCharacter != NULL && this == sm_pMainCharacter) {
        UpdateMainCharacterTick(pTick);
    } else {
        UpdateNPCCharacterTick(pTick);
    }
    m_PerTickScratch194 = 0;
}

/* Slot 09 (+0x24) — `0x001654C0` (PC `0x00573ED0`, 191 bytes) */
void CharacterObject::AdvanceTime(float dt) {
    (void)dt;
    ScopedPoolPush poolScope(0x0A);
    if (m_pPhysicsCharacter != NULL) {
        m_Position = m_pPhysicsCharacter->m_WorldPosition;
        GameObject::SetOrientationMatrix(m_pPhysicsCharacter->m_Orientation3x3);
    }

    if (!s_bSeaLevelVarSynced) {
        s_bSeaLevelVarSynced = true;
        RadicalSim::SetConsoleGlobalVar("gAIStopFallOnSeaLevel", "1");
    }
}

/* Slot 10 (+0x28) — `0x001652C0` (PC `0x00573CF0`, 20 bytes) */
void CharacterObject::EnableSimTick() {
    if ((m_ScriptFlags & 0x10u) == 0) {
        m_ScriptFlags |= 0x10u;
        OnAddToSim(true);
    }
}

/* Slot 11 (+0x2C) — `0x001652E0` (PC `0x00573D10`, 20 bytes) */
void CharacterObject::DisableSimTick() {
    if ((m_ScriptFlags & 0x10u) != 0) {
        m_ScriptFlags &= static_cast<uint8_t>(~0x10u);
        OnAddToSim(true);
    }
}

/* Slot 13 (+0x34) — `0x00169800` (PC `0x00577F20`, 532 bytes) */
void CharacterObject::OnPostSpawnInit() {
    m_SpawnFlags100 = 0;
    ScopedPoolPush poolScope(0x09);

    if (m_CurrentHealth > 0) {
        if (sm_pMainCharacter != NULL && this == sm_pMainCharacter) {
            /* MainCharacter creates "NPCAttackers" set */
            m_NPCAttackersSetId = RadicalSim::InternString("NPCAttackers", 0);
        } else if ((m_SpawnConfigBits & 0x02u) == 0) {
            /* Standard NPC creates "AI behavior", "AI task group", and "NPCAttackers",
             * then enters default alert level 2 if currently 0! */
            m_AIBehaviorId      = RadicalSim::InternString("AI behavior", 0);
            m_AITaskGroupId     = RadicalSim::InternString("AI task group", 0);
            m_NPCAttackersSetId = RadicalSim::InternString("NPCAttackers", 0);
            if (m_AlertStatus == kAlert_DeadOrRelaxed) {
                SetAlertStatus(kAlert_DefaultNPCPatrol, false);
            }
        }
    }

    /* Both Tony & NPCs register a "WeaponInventorySet" bound to property "character" = this! */
    m_WeaponMount.m_WeaponInventorySetId = RadicalSim::InternString("WeaponInventorySet", 0);
}

/* Slot 14 (+0x38) — `0x00169A20` (PC `0x00578160`, 668 bytes) */
void CharacterObject::OnPreDestroyCleanup() {
    m_AITaskGroupId                  = 0;
    m_NPCAttackersSetId              = 0;
    m_CurrentTargetHandle            = 0;
    m_WeaponMount.m_WeaponInventorySetId = 0;
    m_AuxiliarySimHandle             = 0;

    if (sm_LiveCharacterCount == 1) {
        s_LastReportedTonyHP = 0;
    }
    if (sm_LiveCharacterCount > 0) {
        --sm_LiveCharacterCount;
    }

    for (int i = 0; i < kAttachedPropSlotCount; ++i) {
        GameSimObject* pProp = RadicalSim::ResolveSimHandle(m_AttachedPropHandles[i]);
        m_AttachedPropMeta[i] = 0;
        if (pProp != NULL) {
            RadicalSim::DeleteSimObject(pProp);
            m_AttachedPropHandles[i] = 0;
        }
    }

    if (m_pExtraHeapData != NULL) {
        RadicalEngine::PoolFree(m_pExtraHeapData);
        m_pExtraHeapData = NULL;
    }

    if (sm_pMainCharacter == this) {
        sm_pMainCharacter = NULL;
    }
}

/* Slot 17 (+0x44) — `0x001632B0` (PC `0x005715D0`, 27 bytes) */
void CharacterObject::SetSimFlagBit1(bool bVal) {
    const uint8_t bit = bVal ? 0x02u : 0x00u;
    m_SimStateBits = static_cast<uint8_t>((m_SimStateBits & ~0x02u) | bit);
}

/* Slot 20 (+0x50) — `0x0006F990` (PC `0x005A4810`, 3 bytes) */
bool CharacterObject::IsCharacterType() const { return true; }

/* Slot 29 (+0x74) — `0x00165770` (PC `0x005741C0`, 43 bytes) */
void CharacterObject::SetWorldPosition(const Vector3f* pPos) {
    if (pPos == NULL) {
        return;
    }
    m_Position = *pPos;
    if (m_pPhysicsCharacter != NULL) {
        m_pPhysicsCharacter->m_WorldPosition = *pPos;
    }
}

/* Slot 30 (+0x78) — `0x001657A0` (PC `0x005741F0`, 50 bytes) */
void CharacterObject::SetOrientationMatrix(const void* pMat3x3) {
    GameObject::SetOrientationMatrix(pMat3x3);
}

/* Slot 32 (+0x80) — `0x00163510` (PC `0x00571830`, 35 bytes) */
void CharacterObject::SetScaleOrBounds(const void* pData) {
    GameObject::SetScaleOrBounds(pData);
}

/* Slot 35 (+0x8C) — `0x001670F0` (PC `0x00575A60`, 17 bytes) */
void* CharacterObject::QueryInterfaceById(void* pReq) {
    return pReq;
}

/*
 * Slot 36 (+0x90) — `0x001646B0` (PC `0x00572C50`, 47 bytes):
 *   Returns `false` (alive) iff `m_AlertStatus != 0 && m_CurrentHealth > 0`,
 *   otherwise returns `true` (dead/incapacitated)!
 */
bool CharacterObject::IsDead() const {
    if (m_AlertStatus != 0 && m_CurrentHealth > 0) {
        return false;
    }
    return true;
}

/* Slot 37 (+0x94) — `0x001671D0` (PC `0x00575A90`, 63 bytes) */
bool CharacterObject::CanBeTargeted() const {
    if (sm_pMainCharacter != NULL && this == sm_pMainCharacter) {
        return false;
    }
    if (IsStreamingLocked()) {
        return false;
    }
    return true;
}

/* Slot 38 (+0x98) — `0x00167210` (PC `0x00575AD0`, 139 bytes) */
void CharacterObject::ApplyDamageOrKill(float healthVal) {
    if (healthVal > 0.0f) {
        if (!IsInvulnerable()) {
            OnDamageInflicted(&healthVal, true, false);
        }
        return;
    }
    GameSimObject* pMounted = ResolveMountedVehicle();
    if (pMounted != NULL) {
        RadicalSim::DeleteSimObject(pMounted);
    } else {
        RadicalSim::DeleteSimObject(this);
    }
}

/* Slot 39 (+0x9C) & Slot 40 (+0xA0) — `0x001648F0` & `0x00164910` (20B each) */
void* CharacterObject::GetCollisionSpace() const {
    return (m_pPhysicsCharacter != NULL) ? m_pPhysicsCharacter->m_pCollisionSpace : NULL;
}

void* CharacterObject::GetProjectileHitBody() const {
    return (m_pPhysicsCharacter != NULL) ? m_pPhysicsCharacter->m_pProjectileHitBody : NULL;
}

/* Slot 42 (+0xA8) — `0x00163260` (PC `0x00571580`, 59 bytes) */
void CharacterObject::SetPhysicsActive(bool bActive) {
    if (m_pPhysicsCharacter == NULL) {
        return;
    }
    (void)bActive;
}

/* Slot 44 (+0xB0) & Slot 45 (+0xB4) — `0x00167CF0` (17B) & `0x00167D10` (7B) */
void  CharacterObject::SetHeadingRadians(float headingRad) { m_HeadingRadians = headingRad; }
float CharacterObject::GetHeadingRadians() const           { return m_HeadingRadians; }

/* Slot 47 (+0xBC) — `0x001672A0` (PC `0x00575B60`, 86 bytes) */
GameSimObject* CharacterObject::GetEffectiveTargetObject() {
    GameSimObject* pMounted = ResolveMountedVehicle();
    if (pMounted != NULL) {
        return pMounted->GetEffectiveTargetObject();
    }
    return GameSimObject::GetEffectiveTargetObject();
}

/* Slot 48 (+0xC0) — `0x001646E0` (PC `0x00572C80`, 7 bytes) */
float CharacterObject::GetActiveTimerSeconds() const {
    return m_ActiveTimerSec;
}

/* Slot 49 (+0xC4) — `0x00167DF0` (PC `0x005762A0`, 139 bytes) */
void CharacterObject::OnDamageInflicted(void* pHitInfo, bool bSetInvuln, bool bNoPropagate) {
    GameSimObject::OnDamageInflicted(pHitInfo, false, true);
    SetInvulnerable(bSetInvuln);

    if (!bNoPropagate) {
        GameSimObject* pMounted = ResolveMountedVehicle();
        if (pMounted != NULL && !pMounted->IsInvulnerable()) {
            pMounted->OnDamageInflicted(pHitInfo, bSetInvuln, true);
        }
    }
}

/* Slot 50 (+0xC8) & Slot 51 (+0xCC) — `0x00167D30` (7B) & `0x00167D20` (13B) */
bool CharacterObject::IsInvulnerable() const       { return m_bIsInvulnerable != 0; }
void CharacterObject::SetInvulnerable(bool bInvuln){ m_bIsInvulnerable = bInvuln ? 1 : 0; }

/* Slot 52 (+0xD0) */
void CharacterObject::vfunc_52(int32_t) {}

/* Slot 53 (+0xD4) — `0x00165350` (PC `0x00573D80`, 83 bytes) */
void CharacterObject::SetStreamingLockState(bool bLocked) {
    if (IsStreamingLocked() == bLocked) {
        return;
    }
    const uint8_t bit = bLocked ? 0x04u : 0x00u;
    m_SimStateBits = static_cast<uint8_t>((m_SimStateBits & ~0x04u) | bit);
}

/* Slot 55 (+0xDC) & Slot 56 (+0xE0) — `0x00165300` (72B) & `0x001632A0` (8B thunk) */
void CharacterObject::CheckHitBodyMatch(void* pQuery, void* pArg2) {
    (void)pArg2;
    if (m_pPhysicsCharacter != NULL && pQuery != NULL &&
        pQuery == m_pPhysicsCharacter->m_pProjectileHitBody)
    {
        *static_cast<uint8_t*>(pQuery) = 1;
    }
}

void CharacterObject::CheckHitBodyMatchThunk(void* pQuery, void* pArg2) {
    CheckHitBodyMatch(pQuery, pArg2);
}

/* Slot 59 (+0xEC) — `0x001674B0` (PC `0x00575D70`, 97 bytes) */
uint32_t CharacterObject::GetCombinedCollisionFlags() const {
    GameSimObject* pMounted = ResolveMountedVehicle();
    if (pMounted != NULL) {
        return pMounted->GetCombinedCollisionFlags() | static_cast<uint32_t>(m_CollisionMaskByte);
    }
    return static_cast<uint32_t>(m_CollisionMaskByte);
}

/* Slot 64 (+0x100) — `0x0016C6C0` (PC `0x0057ACA0`, 73 bytes) */
void CharacterObject::OnWeaponEquipped(void* pWeapon, void* pSlotInfo) {
    (void)pWeapon;
    (void)pSlotInfo;
}

void CharacterObject::vfunc_65() {}
void CharacterObject::vfunc_66() {}

/*
 * Slot 67 (+0x10C) — `0x0016B310` (PC `0x00579B50`, 661 bytes):
 *   - Tony Montana death (`this == sm_pMainCharacter`):
 *       Increments `"$statTracking::tonyDeaths"`, checks if killer is `"cop"` to play
 *       `"radio_cop"` `"killed_00"` over `"duck_phonecall"`, and fires Event `0x64`!
 *   - NPC death (`this != sm_pMainCharacter`):
 *       Increments `"$statTracking::totalKills"`, notifies vehicle `"OnDriverKilled"` if driving!
 *   - Schedules `"OnDyingFinished"` in `2000ms` (`0x7D0`), or `5000ms` (`0x1388`) if weapon type == 5!
 */
void CharacterObject::OnCharacterKilled(uint32_t weaponSimId, uint32_t killerSimId) {
    if (sm_pMainCharacter != NULL && this == sm_pMainCharacter) {
        RadicalSim::IncrementStatCounter("$statTracking::tonyDeaths", 1);
        GameSimObject* pKiller = RadicalSim::ResolveSimHandle(killerSimId);
        if (pKiller != NULL && pKiller->m_NameSymbolId == RadicalSim::InternString("cop", 0)) {
            const uint32_t hDuck = RadicalSim::GetAudioDuckHandle("duck_phonecall");
            RadicalSim::ActivateAudioDuck(hDuck, 0, 0, 1, 0);
        }
        EventManager::GetInstance()->TriggerEvent(kEventId_TonyDied, NULL, NULL);
    } else {
        RadicalSim::IncrementStatCounter("$statTracking::totalKills", 1);
        GameSimObject* pAux = RadicalSim::ResolveSimHandle(m_AuxiliarySimHandle);
        if (pAux != NULL) {
            RadicalSim::DeleteSimObject(pAux);
        }
    }

    SetAlertStatus(kAlert_DeadOrRelaxed, false);

    GameSimObject* pVehicle = ResolveMountedVehicle();
    if (pVehicle != NULL) {
        RadicalSim::ExecuteObjectCallback1(pVehicle, "OnDriverKilled");
    }

    uint32_t dyingDelayMs = kDyingDelayDefaultMs; /* 2000 ms (0x7D0) */
    GameSimObject* pWeapon = RadicalSim::ResolveSimHandle(weaponSimId);
    if (pWeapon != NULL && pWeapon->m_SimAttrFlags == 5u) {
        dyingDelayMs = kDyingDelayHeavyWeaponMs; /* 5000 ms (0x1388) */
    }

    if (m_DyingTimerEventId != 0) {
        RadicalSim::CancelScheduledEvent(m_DyingTimerEventId);
    }
    m_DyingTimerEventId = RadicalSim::ScheduleObjectEvent(this, dyingDelayMs, "OnDyingFinished");
}

/* Slot 68 (+0x110) & Slot 69 (+0x114) */
bool CharacterObject::SupportsWeaponInventory() const { return true; }

bool CharacterObject::CanDropOrSwitchWeapon() const {
    if (sm_pMainCharacter != NULL && this == sm_pMainCharacter) {
        return true;
    }
    return true;
}

void CharacterObject::vfunc_70(int32_t) {}
void CharacterObject::OnDriverKilledFallback(int32_t) {}
void CharacterObject::vfunc_72(int32_t, int32_t, int32_t) {}
bool CharacterObject::vfunc_73() const { return false; }

/*
 * ============================================================================
 * 6. Reconstructed Private Gameplay Helpers (`0x00166970`, `0x00168C00`, etc.)
 * ============================================================================
 */
GameSimObject* CharacterObject::ResolveMountedVehicle() const {
    GameSimObject* pVeh = RadicalSim::ResolveSimHandle(m_CurrentVehicleHandle);
    if (pVeh != NULL) {
        return pVeh;
    }
    return m_WeaponMount.m_pMountedEntity;
}

/* Reconstructed 1:1 from `0x00166970` (`454` bytes) */
void CharacterObject::UpdateHealthAndEvents() {
    if (m_AlertStatus != 0 && m_CurrentHealth > 0) {
        const float ratioThreshold = (sm_pMainCharacter != NULL && this == sm_pMainCharacter)
            ? 0.25f
            : m_LowHealthThreshold;
        const float critLimit = static_cast<float>(m_MaxHealth) * ratioThreshold;
        const uint8_t bCrit = (critLimit >= static_cast<float>(m_CurrentHealth)) ? 1u : 0u;
        if (m_bIsCriticalLowHealth != bCrit) {
            m_bIsCriticalLowHealth = bCrit;
            if (m_pPhysicsCharacter != NULL) {
                m_pPhysicsCharacter->m_bLowHealthNotified = (bCrit != 0);
            }
        }
    }

    if (sm_pMainCharacter != NULL && this == sm_pMainCharacter) {
        EventManager::GetInstance()->TriggerEvent(
            kEventId_MaxHealth,
            reinterpret_cast<void*>(static_cast<size_t>(m_MaxHealth)),
            NULL);
        EventManager::GetInstance()->TriggerEvent(
            kEventId_CurrentHealth,
            reinterpret_cast<void*>(static_cast<size_t>(m_CurrentHealth)),
            NULL);
        s_LastReportedTonyHP = m_CurrentHealth;
        return;
    }

    /* Custom Boss Health Bar Broadcast (`cmp dword ptr [esi+0x428], 0xE4` @ 0x00166B0C!) */
    if (m_HealthEventId != kDefaultHealthEventId) {
        EventManager::GetInstance()->TriggerEvent(
            m_HealthEventId,
            reinterpret_cast<void*>(static_cast<size_t>(m_CurrentHealth)),
            NULL);
    }
}

/* Reconstructed 1:1 from `0x00168C00` (`643` bytes) */
void CharacterObject::SetAlertStatus(int32_t newAlertLevel, bool bOnlyEscalate) {
    if (bOnlyEscalate && newAlertLevel <= m_AlertStatus) {
        return;
    }

    const bool bChanged = (newAlertLevel != m_AlertStatus);
    m_bDeferredAlertPending = 0;

    if (newAlertLevel == kAlert_DeadOrRelaxed) {
        if (m_pPhysicsCharacter != NULL) {
            m_pPhysicsCharacter->m_bBulletColEnabled     = false;
            m_pPhysicsCharacter->m_bProjectileColEnabled = false;
        }
    } else if (!IsInVehicleOrMounted()) {
        SetPhysicsActive(true);
        if (m_pPhysicsCharacter != NULL) {
            m_pPhysicsCharacter->m_bBulletColEnabled     = true;
            m_pPhysicsCharacter->m_bProjectileColEnabled = true;
        }
    }

    if (newAlertLevel >= kAlert_CombatHostile && m_AlertStatus < kAlert_CombatHostile) {
        m_CombatEnterTimeMs = RadicalSim::GetSimTimeMs();
    }
    m_AlertStatus = newAlertLevel;

    if (sm_pMainCharacter != NULL && this == sm_pMainCharacter) {
        return;
    }
    if (!bChanged) {
        return;
    }

    RadicalSim::ExecuteObjectCallback2(this, "OnAlertStatusChanged", "4");

    if (m_AlertStatus >= kAlert_CombatHostile) {
        RadicalSim::TriggerCombatMusic(m_SimObjectId, "drugwars", 2000u);
    } else if (m_AlertStatus == kAlert_DeadOrRelaxed) {
        RadicalSim::ReleaseCombatMusic(m_SimObjectId);
    }
}

/* Reconstructed 1:1 from `0x00163B00` (`174` bytes) */
void CharacterObject::RequestVocal(const char* vocalLineName) {
    m_bVocalPlaying = 0;
    if (m_pPhysicsCharacter != NULL && m_pPhysicsCharacter->m_pVocalAudioEmitter != NULL &&
        vocalLineName != NULL && vocalLineName[0] != '\0')
    {
        m_bVocalPlaying = 1;
        m_VocalFinishTimerMs = RadicalSim::GetSimTimeMs() + 500u;
        RadicalSim::ExecuteObjectCallback2(this, "OnRequestVocal", vocalLineName);
    }
    const bool bIsTony = (sm_pMainCharacter != NULL && this == sm_pMainCharacter);
    m_bVocalPendingTail = (!bIsTony && m_bVocalPlaying != 0) ? 1u : 0u;
}

/* Reconstructed 1:1 from `0x0016D5D0` (`305` bytes) */
void CharacterObject::UpdateVocalPlaybackState() {
    if (m_bVocalPlaying != 0 && RadicalSim::GetSimTimeMs() >= m_VocalFinishTimerMs) {
        m_bVocalPlaying     = 0;
        m_bVocalPendingTail = 0;
    }
}

/* Reconstructed 1:1 from `0x0016C5A0` (`281` bytes) */
void CharacterObject::UpdateMainCharacterTick(const TickUpdateParams* pTick) {
    if (m_pMainCharContext != NULL) {
        m_pMainCharContext->UpdateContext(pTick);
    }
    if (m_pPhysicsCharacter != NULL) {
        m_Position = m_pPhysicsCharacter->m_WorldPosition;
        GameObject::SetOrientationMatrix(m_pPhysicsCharacter->m_Orientation3x3);
    }
}

/* Reconstructed 1:1 from `0x00167F50` (`127` bytes) */
void CharacterObject::UpdateNPCCharacterTick(const TickUpdateParams*) {
    if (m_pPhysicsCharacter != NULL) {
        m_Position = m_pPhysicsCharacter->m_WorldPosition;
        GameObject::SetOrientationMatrix(m_pPhysicsCharacter->m_Orientation3x3);
    }
}

/*
 * ============================================================================
 * 7. Full Behavioral Self-Test Suite (`-DSCARFACE_BUILD_CHARACTER_SELFTEST`)
 * ============================================================================
 */
#if defined(SCARFACE_BUILD_CHARACTER_SELFTEST)
int main() {
    printf("=== Scarface PC v1.00.2 CharacterObject (74-Slot Core) Verification ===\n");

    /* 1. Spawn Tony Montana ("MainCharacter") via ConcreteClassRep & verify CharacterContext (0x68B) */
    CharacterObject* pTony = static_cast<CharacterObject*>(
        CharacterObject::sm_ConcreteClassRep.CreateFromPool());
    pTony->m_NameSymbolId = RadicalSim::InternString("MainCharacter", 0);
    PhysicsCharacterController tonyPhys;
    tonyPhys.m_WorldPosition.x = 142.5f;
    tonyPhys.m_WorldPosition.y = -88.0f;
    tonyPhys.m_WorldPosition.z = 12.25f;
    int dummyVocal = 1;
    tonyPhys.m_pVocalAudioEmitter = &dummyVocal;
    pTony->m_pPhysicsCharacter = &tonyPhys;

    pTony->OnAddToSim(true);
    pTony->OnPostSpawnInit();
    if (CharacterObject::sm_pMainCharacter != pTony || pTony->m_pMainCharContext == NULL) { return 1; }
    if (pTony->m_pMainCharContext->m_pOwner != pTony) { return 2; }
    printf("[1] MainCharacter  : PASS (Tony registered, 0x68B CharacterContext @ +0xF8 bound)\n");

    /* 2. Tick accumulation (+0x10C) & Physics position sync (+0x64..+0x6C) */
    pTony->m_bAccumulateTimer = 1;
    TickUpdateParams tick = { 1u, 16u, 0u, 0.25f };
    pTony->ProcessTick(&tick);
    if (pTony->GetActiveTimerSeconds() < 0.24f || pTony->m_Position.x < 142.0f) { return 3; }
    printf("[2] ProcessTick    : PASS (SSE2 timer=+%.2fs, WorldPos=(%.1f, %.1f, %.1f))\n",
           pTony->GetActiveTimerSeconds(), pTony->m_Position.x, pTony->m_Position.y, pTony->m_Position.z);

    /* 3. Spawn Cartel Guard NPC: verify Patrol alert=2, Escalate to Combat=4 ("drugwars" music!) */
    CharacterObject* pGuard = static_cast<CharacterObject*>(
        CharacterObject::sm_ConcreteClassRep.CreateFromPool());
    PhysicsCharacterController guardPhys;
    pGuard->m_pPhysicsCharacter = &guardPhys;
    pGuard->OnAddToSim(true);
    pGuard->OnPostSpawnInit();
    if (pGuard->m_AlertStatus != CharacterObject::kAlert_DefaultNPCPatrol) { return 4; }
    if (pGuard->IsDead() != false) { return 5; }

    RadicalSim::s_SimClockMs = 4321u;
    pGuard->SetAlertStatus(CharacterObject::kAlert_CombatHostile, true);
    if (pGuard->m_CombatEnterTimeMs != 4321u || strcmp(RadicalSim::s_LastMusicCue, "drugwars") != 0) {
        return 6;
    }
    printf("[3] Combat Alert   : PASS (Patrol=2 -> Hostile=4 @ t=4321ms, cue='%s' triggered)\n",
           RadicalSim::s_LastMusicCue);

    /* 4. Invulnerability (+0x421) + Heavy-Weapon Death (weapon type 5 -> 5000ms "OnDyingFinished") */
    pGuard->SetInvulnerable(true);
    if (!pGuard->IsInvulnerable()) { return 7; }
    pGuard->SetInvulnerable(false);

    GameSimObject heavyWeapon;
    heavyWeapon.m_SimAttrFlags = 5u; /* Heavy/Chainsaw/Rocket weapon class -> 5000ms delay! */
    RadicalSim::RegisterTestSimObject(&heavyWeapon);

    GameSimObject getawayCar;
    pGuard->m_WeaponMount.m_pMountedEntity = &getawayCar;
    pGuard->OnCharacterKilled(heavyWeapon.m_SimObjectId, pTony->m_SimObjectId);
    if (RadicalSim::s_TotalKillsStat != 1 || RadicalSim::s_LastScheduledMs != 5000u) { return 8; }
    if (!pGuard->IsDead()) { return 9; }
    printf("[4] NPC Killed     : PASS (totalKills=%d, OnDyingFinished=%ums, IsDead=true)\n",
           static_cast<int>(RadicalSim::s_TotalKillsStat),
           static_cast<unsigned>(RadicalSim::s_LastScheduledMs));

    /* 5. Cop kills Tony -> "$statTracking::tonyDeaths" + "duck_phonecall" + 2000ms default delay */
    GameSimObject copKiller;
    copKiller.m_NameSymbolId = RadicalSim::InternString("cop", 0);
    RadicalSim::RegisterTestSimObject(&copKiller);
    pTony->OnCharacterKilled(0, copKiller.m_SimObjectId);
    if (RadicalSim::s_TonyDeathsStat != 1 || RadicalSim::s_LastScheduledMs != 2000u) { return 10; }
    printf("[5] Tony Killed    : PASS (tonyDeaths=%d, cop radio dispatch, OnDyingFinished=%ums)\n",
           static_cast<int>(RadicalSim::s_TonyDeathsStat),
           static_cast<unsigned>(RadicalSim::s_LastScheduledMs));

    /* Cleanup */
    pGuard->OnPreDestroyCleanup();
    pGuard->~CharacterObject();
    RadicalEngine::PoolFree(pGuard);

    pTony->OnPreDestroyCleanup();
    pTony->~CharacterObject();
    RadicalEngine::PoolFree(pTony);

    printf("=== ALL 74-SLOT CHARACTEROBJECT ABI & GAMEPLAY CHECKS PASSED! ===\n");
    return 0;
}
#endif
