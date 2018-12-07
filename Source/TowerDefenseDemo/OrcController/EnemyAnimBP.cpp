#include "TowerDefenseDemoC.h"
#include "EnemyAnimBP.h"
#include "Utils.h"


#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
PRAGMA_DISABLE_OPTIMIZATION
EnemyAnimBP::EnemyAnimBP(const FObjectInitializer& ObjectInitializer) : Super()
{
	if(HasAnyFlags(RF_ClassDefaultObject) && (EnemyAnimBP::StaticClass() == GetClass()))
	{
		EnemyAnimBP::__CustomDynamicClassInitialization(CastChecked<UDynamicClass>(GetClass()));
	}

	__InitAllAnimNodes();
	bpv__isAttacking__pf = false;
	bUseMultiThreadedAnimationUpdate = false;
}
PRAGMA_ENABLE_OPTIMIZATION
void EnemyAnimBP::__InitAllAnimNodes()
{
	__InitAnimNode__AnimGraphNode_Root();
	__InitAnimNode__AnimGraphNode_TransitionResult();
	__InitAnimNode__AnimGraphNode_TransitionResult();
	__InitAnimNode__AnimGraphNode_BlendSpacePlayer();
	__InitAnimNode__AnimGraphNode_StateResult_A();
	__InitAnimNode__AnimGraphNode_BlendListByInt();
	__InitAnimNode__AnimGraphNode_SequencePlayer_First();
	__InitAnimNode__AnimGraphNode_SequencePlayer_Second();
	__InitAnimNode__AnimGraphNode_SequencePlayer_Third();
	__InitAnimNode__AnimGraphNode_StateResult_B();
	__InitAnimNode__AnimGraphNode_StateMachine();
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_Root()
{
	bpv__AnimGraphNode_Root.Result.LinkID = 10;
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_TransitionResult()
{
	bpv__AnimGraphNode_TransitionResult.EvaluateGraphExposedInputs.CopyRecords = TArray<FExposedValueCopyRecord> ();
	bpv__AnimGraphNode_TransitionResult.EvaluateGraphExposedInputs.CopyRecords.AddUninitialized(1);
	FExposedValueCopyRecord::StaticStruct()->InitializeStruct(bpv__AnimGraphNode_TransitionResult.EvaluateGraphExposedInputs.CopyRecords.GetData(), 1);
	auto& __Local__0 = bpv__AnimGraphNode_TransitionResult.EvaluateGraphExposedInputs.CopyRecords[0];
	__Local__0.SourcePropertyName = FName(TEXT("isAttacking"));
	__Local__0.DestProperty = FindFieldChecked<UBoolProperty>(FAnimNode_TransitionResult::StaticStruct(), TEXT("bCanEnterTransition"));
	__Local__0.Size = 1;
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_TransitionResult()
{
	bpv__AnimGraphNode_TransitionResult.EvaluateGraphExposedInputs.CopyRecords = TArray<FExposedValueCopyRecord> ();
	bpv__AnimGraphNode_TransitionResult.EvaluateGraphExposedInputs.CopyRecords.AddUninitialized(1);
	FExposedValueCopyRecord::StaticStruct()->InitializeStruct(bpv__AnimGraphNode_TransitionResult.EvaluateGraphExposedInputs.CopyRecords.GetData(), 1);
	auto& __Local__1 = bpv__AnimGraphNode_TransitionResult.EvaluateGraphExposedInputs.CopyRecords[0];
	__Local__1.SourcePropertyName = FName(TEXT("isAttacking"));
	__Local__1.DestProperty = FindFieldChecked<UBoolProperty>(FAnimNode_TransitionResult::StaticStruct(), TEXT("bCanEnterTransition"));
	__Local__1.Size = 1;
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_BlendSpacePlayer()
{
	bpv__AnimGraphNode_BlendSpacePlayer.BlendSpace = CastChecked<UBlendSpaceBase>(CastChecked<UDynamicClass>(EnemyAnimBP::StaticClass())->UsedAssets[0], ECastCheckedType::NullAllowed);
	bpv__AnimGraphNode_BlendSpacePlayer.EvaluateGraphExposedInputs.BoundFunction = FName(TEXT("EvaluateGraphExposedInputs_ExecuteUbergraph_EnemyAnimBP_AnimGraphNode_BlendSpacePlayer_4439833543B29F503AB8A28B580C0A18"));
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_StateResult_B3EBDC7447AC49C5EDE32F9BE601754C()
{
	bpv__AnimGraphNode_StateResult_B3EBDC7447AC49C5EDE32F9BE601754C__pf.Result.LinkID = 3;
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_BlendListByInt()
{
	bpv__AnimGraphNode_BlendListByInt.BlendPose = TArray<FPoseLink> ();
	bpv__AnimGraphNode_BlendListByInt.BlendPose.AddUninitialized(3);
	FPoseLink::StaticStruct()->InitializeStruct(bpv__AnimGraphNode_BlendListByInt.BlendPose.GetData(), 3);
	auto& __Local__2 = bpv__AnimGraphNode_BlendListByInt.BlendPose[0];
	__Local__2.LinkID = 8;
	auto& __Local__3 = bpv__AnimGraphNode_BlendListByInt.BlendPose[1];
	__Local__3.LinkID = 6;
	auto& __Local__4 = bpv__AnimGraphNode_BlendListByInt.BlendPose[2];
	__Local__4.LinkID = 7;
	bpv__AnimGraphNode_BlendListByInt.BlendTime = TArray<float> ();
	bpv__AnimGraphNode_BlendListByInt.BlendTime.Reserve(3);
	bpv__AnimGraphNode_BlendListByInt.BlendTime.Add(0.100000f);
	bpv__AnimGraphNode_BlendListByInt.BlendTime.Add(0.100000f);
	bpv__AnimGraphNode_BlendListByInt.BlendTime.Add(0.100000f);
	bpv__AnimGraphNode_BlendListByInt.EvaluateGraphExposedInputs.BoundFunction = FName(TEXT("EvaluateGraphExposedInputs_ExecuteUbergraph_EnemyAnimBP_AnimGraphNode_BlendListByInt"));
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_SequencePlayer()
{
	bpv__AnimGraphNode_SequencePlayer.Sequence = CastChecked<UAnimSequenceBase>(CastChecked<UDynamicClass>(EnemyAnimBP::StaticClass())->UsedAssets[1], ECastCheckedType::NullAllowed);
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_SequencePlayer()
{
	bpv__AnimGraphNode_SequencePlayer.Sequence = CastChecked<UAnimSequenceBase>(CastChecked<UDynamicClass>(EnemyAnimBP::StaticClass())->UsedAssets[2], ECastCheckedType::NullAllowed);
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_SequencePlayer
{
	bpv__AnimGraphNode_SequencePlayer.Sequence = CastChecked<UAnimSequenceBase>(CastChecked<UDynamicClass>(EnemyAnimBP::StaticClass())->UsedAssets[3], ECastCheckedType::NullAllowed);
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_StateResult()
{
	bpv__AnimGraphNode_StateResult.Result.LinkID = 5;
}
void EnemyAnimBP::__InitAnimNode__AnimGraphNode_StateMachine()
{
}
void EnemyAnimBP::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
}
PRAGMA_DISABLE_OPTIMIZATION
void EnemyAnimBP::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();

	// List of all referenced classes for enemy animation
	InDynamicClass->ReferencedConvertedFields.Add(AIEnemy::StaticClass());
	InDynamicClass->ReferencedConvertedFields.Add(myGameInstance::StaticClass());
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
	auto __Local__5 = NewObject<UAnimClassData>(InDynamicClass, TEXT("AnimClassData"));
	__Local__5->BakedStateMachines = TArray<FBakedAnimationStateMachine> ();
	__Local__5->BakedStateMachines.AddUninitialized(1);
	FBakedAnimationStateMachine::StaticStruct()->InitializeStruct(__Local__5->BakedStateMachines.GetData(), 1);
	auto& __Local__6 = __Local__5->BakedStateMachines[0];
	__Local__6.MachineName = FName(TEXT("Locomotion"));
	__Local__6.InitialState = 0;
	__Local__6.States = TArray<FBakedAnimationState> ();
	__Local__6.States.AddUninitialized(2);
	FBakedAnimationState::StaticStruct()->InitializeStruct(__Local__6.States.GetData(), 2);
	auto& __Local__7 = __Local__6.States[0];
	__Local__7.StateName = FName(TEXT("Walking"));
	__Local__7.Transitions = TArray<FBakedStateExitTransition> ();
	__Local__7.Transitions.AddUninitialized(1);
	FBakedStateExitTransition::StaticStruct()->InitializeStruct(__Local__7.Transitions.GetData(), 1);
	auto& __Local__8 = __Local__7.Transitions[0];
	__Local__8.CanTakeDelegateIndex = 8;
	__Local__8.TransitionIndex = 0;
	__Local__7.StateRootNodeIndex = 6;
	__Local__7.PlayerNodeIndices = TArray<int32> ();
	__Local__7.PlayerNodeIndices.Reserve(1);
	__Local__7.PlayerNodeIndices.Add(7);
	auto& __Local__9 = __Local__6.States[1];
	__Local__9.StateName = FName(TEXT("Attacking Player"));
	__Local__9.Transitions = TArray<FBakedStateExitTransition> ();
	__Local__9.Transitions.AddUninitialized(1);
	FBakedStateExitTransition::StaticStruct()->InitializeStruct(__Local__9.Transitions.GetData(), 1);
	auto& __Local__10 = __Local__9.Transitions[0];
	__Local__10.CanTakeDelegateIndex = 9;
	__Local__10.TransitionIndex = 1;
	__Local__9.StateRootNodeIndex = 1;
	__Local__9.PlayerNodeIndices = TArray<int32> ();
	__Local__9.PlayerNodeIndices.Reserve(3);
	__Local__9.PlayerNodeIndices.Add(2);
	__Local__9.PlayerNodeIndices.Add(3);
	__Local__9.PlayerNodeIndices.Add(4);
	__Local__6.Transitions = TArray<FAnimationTransitionBetweenStates> ();
	__Local__6.Transitions.AddUninitialized(2);
	FAnimationTransitionBetweenStates::StaticStruct()->InitializeStruct(__Local__6.Transitions.GetData(), 2);
	auto& __Local__11 = __Local__6.Transitions[0];
	__Local__11.PreviousState = 0;
	__Local__11.NextState = 1;
	__Local__11.CrossfadeDuration = 0.200000f;
	__Local__11.BlendMode = EAlphaBlendOption::HermiteCubic;
	auto& __Local__12 = __Local__6.Transitions[1];
	__Local__12.PreviousState = 1;
	__Local__12.NextState = 0;
	__Local__12.CrossfadeDuration = 0.200000f;
	__Local__12.BlendMode = EAlphaBlendOption::HermiteCubic;
	__Local__5->TargetSkeleton = CastChecked<USkeleton>(CastChecked<UDynamicClass>(EnemyAnimBP::StaticClass())->UsedAssets[4], ECastCheckedType::NullAllowed);
	__Local__5->RootAnimNodeIndex = 10;
	__Local__5->RootAnimNodeProperty = InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_Root"));
	__Local__5->AnimNodeProperties = TArray<UStructProperty*> ();
	__Local__5->AnimNodeProperties.Reserve(11);
	__Local__5->AnimNodeProperties.Add(InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_Root")));
	__Local__5->AnimNodeProperties.Add(InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_TransitionResult")));
	__Local__5->AnimNodeProperties.Add(InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_BlendSpacePlayer")));
	__Local__5->AnimNodeProperties.Add(InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_StateResult")));
	__Local__5->AnimNodeProperties.Add(InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_BlendListByInt")));
	__Local__5->AnimNodeProperties.Add(InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_SequencePlayer")));
	__Local__5->AnimNodeProperties.Add(InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_SequencePlayer")));
	__Local__5->AnimNodeProperties.Add(InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_SequencePlayer")));
	__Local__5->AnimNodeProperties.Add(InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_StateResult")));
	__Local__5->AnimNodeProperties.Add(InDynamicClass->FindStructPropertyChecked(TEXT("AnimGraphNode_StateMachine")));
	InDynamicClass->AnimClassImplementation = __Local__5;
}

PRAGMA_ENABLE_OPTIMIZATION
void EnemyAnimBP::bpf__ExecuteUbergraph_EnemyAnimBP__pf_0(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 6);
	bpv__AnimGraphNode_TransitionResult.bCanEnterTransition = bpv__isAttacking__pf;
	return; // KCST_GotoReturn
}
void EnemyAnimBP::bpf__ExecuteUbergraph_EnemyAnimBP__pf_1(int32 bpp__EntryPoint__pf)
{
	int32 bpfv__CallFunc_RandomInteger_ReturnValue__pf{};
	check(bpp__EntryPoint__pf == 2);
	bpfv__CallFunc_RandomInteger_ReturnValue__pf = UKismetMathLibrary::RandomInteger(3);
	bpv__AnimGraphNode_BlendListByInt_.ActiveChildIndex = bpfv__CallFunc_RandomInteger_ReturnValue__pf;
	return; // KCST_GotoReturn
}
void EnemyAnimBP::bpf__ExecuteUbergraph_EnemyAnimBP__pf_2(int32 bpp__EntryPoint__pf)
{
	ACharacter* bpfv__CallFunc_GetPlayerCharacter_ReturnValue__pf{};
	check(bpp__EntryPoint__pf == 10);
	// optimized KCST_UnconditionalGoto
	bpfv__CallFunc_GetPlayerCharacter_ReturnValue__pf = UGameplayStatics::GetPlayerCharacter(this, 0);
	b0l__K2Node_DynamicCast_AsAIEnemy__pf = Cast<AIEnemy>(bpfv__CallFunc_GetPlayerCharacter_ReturnValue__pf);
	b0l__K2Node_DynamicCast_bSuccess__pf = (b0l__K2Node_DynamicCast_AsAIEnemy__pf != nullptr);;
	if (!b0l__K2Node_DynamicCast_bSuccess__pf)
	{
		return; //KCST_GotoReturnIfNot
	}
	return; // KCST_GotoReturn
}
void EnemyAnimBP::bpf__ExecuteUbergraph_EnemyAnimBP__pf_3(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 9);
	// optimized KCST_UnconditionalGoto
	bpv__AnimGraphNode_TransitionResult.bCanEnterTransition = bpv__isAttacking__pf;
	return; // KCST_GotoReturn
}
void EnemyAnimBP::bpf__ExecuteUbergraph_EnemyAnimBP__pf_4(int32 bpp__EntryPoint__pf)
{
	UGameInstance* bpfv__CallFunc_GetGameInstance_ReturnValue__pf{};
	check(bpp__EntryPoint__pf == 8);
	// optimized KCST_UnconditionalGoto
	bpfv__CallFunc_GetGameInstance_ReturnValue__pf = UGameplayStatics::GetGameInstance(this);
	b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf = Cast<myGameInstance>(bpfv__CallFunc_GetGameInstance_ReturnValue__pf);
	b0l__K2Node_DynamicCast_bSuccess1__pf = (b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf != nullptr);;
	float  __Local__13 = 0.000000;
	bpv__AnimGraphNode_BlendSpacePlayer.X = ((::IsValid(b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf)) ? (b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf->bpv__enemySpeed__pf) : (__Local__13));
	return; // KCST_GotoReturn
}
void EnemyAnimBP::bpf__BlueprintUpdateAnimation__pf(float bpp__DeltaTimeX__pf)
{
	b0l__K2Node_Event_DeltaTimeX__pf = bpp__DeltaTimeX__pf;
	bpf__ExecuteUbergraph_EnemyAnimBP__pf_2(10);
}
void EnemyAnimBP::bpf__EvaluateGraphExposedInputs_ExecuteUbergraph_EnemyAnimBP_AnimGraphNode_TransitionResult()
{
	bpf__ExecuteUbergraph_EnemyAnimBP__pf_3(9);
}
void EnemyAnimBP::bpf__EvaluateGraphExposedInputs_ExecuteUbergraph_EnemyAnimBP_AnimGraphNode_BlendListByInt()
{
	bpf__ExecuteUbergraph_EnemyAnimBP__pf_1(2);
}
void EnemyAnimBP::bpf__EvaluateGraphExposedInputs_ExecuteUbergraph_EnemyAnimBP_AnimGraphNode_TransitionResult_080A5CF94B5A12E35231B1802B29FD25__pf()
{
	bpf__ExecuteUbergraph_EnemyAnimBP__pf_0(6);
}
void EnemyAnimBP::bpf__EvaluateGraphExposedInputs_ExecuteUbergraph_EnemyAnimBP_AnimGraphNode_BlendSpacePlayer_4439833543B29F503AB8A28B580C0A18__pf()
{
	bpf__ExecuteUbergraph_EnemyAnimBP__pf_4(8);
}
PRAGMA_DISABLE_OPTIMIZATION
void EnemyAnimBP::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{0, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  BlendSpace1D /Game/MyBlueprints/EnemyAI/EnemyBS.EnemyBS
		{1, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  AnimSequence /Game/Imported-Content/orc/orc_Anim_Attack2H__15_.orc_Anim_Attack2H__15_
		{2, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  AnimSequence /Game/Imported-Content/orc/orc_Anim_AttackUnarmed__23_.orc_Anim_AttackUnarmed__23_
		{3, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  AnimSequence /Game/Imported-Content/orc/orc_Anim_Attack1H__5_.orc_Anim_Attack1H__5_
		{4, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Skeleton /Game/Imported-Content/orc/orc_Skeleton.orc_Skeleton
	};
	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}
}
PRAGMA_ENABLE_OPTIMIZATION
PRAGMA_DISABLE_OPTIMIZATION
void EnemyAnimBP::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_DirectlyUsedAssets(AssetsToLoad);
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{5, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.PointerToUberGraphFrame
		{6, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.Character
		{7, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.GameInstance
		{8, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.GameplayStatics
		{9, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetMathLibrary
		{10, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/AnimGraphRuntime.AnimNode_BlendListByInt
		{11, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/AnimGraphRuntime.AnimNode_BlendSpacePlayer
		{12, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.AnimNode_TransitionResult
		{13, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.AnimInstance
		{14, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/AnimGraphRuntime.AnimNode_Root
		{15, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.AnimNode_SequencePlayer
		{16, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.AnimNode_StateMachine
		{17, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.SkeletalMeshComponent
		{18, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  BlueprintGeneratedClass /Game/MyBlueprints/EnemyAI/AIEnemy.AIEnemy_C
		{19, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  BlueprintGeneratedClass /Game/MyBlueprints/myGameInstance.myGameInstance_C
	};
	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}
}
PRAGMA_ENABLE_OPTIMIZATION
struct FRegisterHelper__EnemyAnimBP
{
	FRegisterHelper__EnemyAnimBP()
	{
		FConvertedBlueprintsDependencies::Get().RegisterConvertedClass(TEXT("/Game/MyBlueprints/EnemyAI/EnemyAnimBP"), &EnemyAnimBP::__StaticDependenciesAssets);
	}
	static FRegisterHelper__EnemyAnimBP Instance;
};
FRegisterHelper__EnemyAnimBP FRegisterHelper__EnemyAnimBP::Instance;
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
