#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "SpawnAI.h"
class USceneComponent;

UCLASS(config=Engine, Blueprintable, BlueprintType)
class SpawnAI : public AActor
{
public:
	UPROPERTY(BlueprintReadWrite, NonTransactional, meta=(Category="Default", OverrideNativeName="DefaultSceneRoot"))
	USceneComponent* bpv__DefaultSceneRoot__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_CreateDelegate_OutputDelegate"))
	FTimerDynamicDelegate b0l__K2Node_CreateDelegate_OutputDelegate__pf;

	SpawnAI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;

	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);

	void bpf__ExecuteUbergraph_SpawnAI__pf_0(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_SpawnAI__pf_1(int32 bpp__EntryPoint__pf);

	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="Spawn Enemy"))
	virtual void bpf__SpawnxEnemy__pfT();

	UFUNCTION(meta=(DisplayName="BeginPlay", ToolTip="Event when play begins for this actor.", CppFromBpEvent, OverrideNativeName="ReceiveBeginPlay"))
	void bpf__ReceiveBeginPlay__pf();

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", DisplayName="Construction Script");

	void bpf__UserConstructionScript__pf();
public:
};
