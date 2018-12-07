#include "TowerDefenseDemoC.h"
#include "SpawnAI.h"
#include "GeneratedCodeHelpers.h"
#include "AIEnemy.h"
#include "Utils.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Engine/CollisionProfile.h"

#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif

PRAGMA_DISABLE_DEPRECATION_WARNINGS
PRAGMA_DISABLE_OPTIMIZATION
SpawnAI::SpawnAI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if(HasAnyFlags(RF_ClassDefaultObject) && (SpawnAI::StaticClass() == GetClass()))
	{
		SpawnAI::__CustomDynamicClassInitialization(CastChecked<UDynamicClass>(GetClass()));
	}

	bpv__DefaultSceneRoot__pf = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = bpv__DefaultSceneRoot__pf;
	bpv__DefaultSceneRoot__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__DefaultSceneRoot__pf->bVisible = false;
	bpv__DefaultSceneRoot__pf->bHiddenInGame = true;
}

PRAGMA_ENABLE_OPTIMIZATION
void SpawnAI::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	if(bpv__DefaultSceneRoot__pf)
	{
		bpv__DefaultSceneRoot__pf->CreationMethod = EComponentCreationMethod::Native;
	}
}

PRAGMA_DISABLE_OPTIMIZATION
void SpawnAI::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();
	// List of all referenced converted classes
	InDynamicClass->ReferencedConvertedFields.Add(AIEnemy::StaticClass());
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
}

PRAGMA_ENABLE_OPTIMIZATION
void SpawnAI::bpf__ExecuteUbergraph_SpawnAI__pf_0(int32 bpp__EntryPoint__pf)
{
	FVector bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf(EForceInit::ForceInit);
	APawn* bpfv__CallFunc_SpawnAIFromClass_ReturnValue__pf{};
	check(bpp__EntryPoint__pf == 4);
	// optimized KCST_UnconditionalGoto
	bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf = AActor::K2_GetActorLocation();
	bpfv__CallFunc_SpawnAIFromClass_ReturnValue__pf = UAIBlueprintHelperLibrary::SpawnAIFromClass(this, AIEnemy::StaticClass(), ((UBehaviorTree*)nullptr), bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf, FRotator(0.000000,180.000000,0.000000), false);
	return; // KCST_GotoReturn
}

void SpawnAI::bpf__ExecuteUbergraph_SpawnAI__pf_1(int32 bpp__EntryPoint__pf)
{
	FTimerHandle bpfv__CallFunc_K2_SetTimerDelegate_ReturnValue__pf{};
	check(bpp__EntryPoint__pf == 3);
	// optimized KCST_UnconditionalGoto
	b0l__K2Node_CreateDelegate_OutputDelegate__pf.BindUFunction(this,FName(TEXT("Spawn Enemy")));
	bpfv__CallFunc_K2_SetTimerDelegate_ReturnValue__pf = UKismetSystemLibrary::K2_SetTimerDelegate(b0l__K2Node_CreateDelegate_OutputDelegate__pf, 5.000000, true);
	return; // KCST_GotoReturn
}

void SpawnAI::bpf__SpawnxEnemy__pfT()
{
	bpf__ExecuteUbergraph_SpawnAI__pf_0(4);
}

void SpawnAI::bpf__ReceiveBeginPlay__pf()
{
	bpf__ExecuteUbergraph_SpawnAI__pf_1(3);
}

PRAGMA_ENABLE_OPTIMIZATION
PRAGMA_DISABLE_OPTIMIZATION
void SpawnAI::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_DirectlyUsedAssets(AssetsToLoad);
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{0, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, true, false)},  //  Class /Script/Engine.SceneComponent
		{1, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.PointerToUberGraphFrame
		{2, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.Pawn
		{3, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  DelegateFunction /Script/Engine.TimerDynamicDelegate__DelegateSignature
		{4, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.TimerHandle
		{5, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.Actor
		{6, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/AIModule.AIBlueprintHelperLibrary
		{7, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetSystemLibrary
		{8, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  BlueprintGeneratedClass /Game/MyBlueprints/EnemyAI/AIEnemy.AIEnemy_C
	};

	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}

}
PRAGMA_ENABLE_OPTIMIZATION
struct FRegisterHelper__SpawnAI
{
	FRegisterHelper__SpawnAI()
	{
		FConvertedBlueprintsDependencies::Get().RegisterConvertedClass(TEXT("/Game/MyBlueprints/EnemyAI/SpawnAI"), &SpawnAI::__StaticDependenciesAssets);
	}
	static FRegisterHelper__SpawnAI Instance;
};

FRegisterHelper__SpawnAI FRegisterHelper__SpawnAI::Instance;
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
