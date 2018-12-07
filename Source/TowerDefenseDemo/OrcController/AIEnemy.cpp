#include "TowerDefenseDemoC.h"
#include "AIEnemy.h"
#include "Utils.h"


#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
PRAGMA_DISABLE_OPTIMIZATION
AIEnemy::AIEnemy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	if(HasAnyFlags(RF_ClassDefaultObject) && (AIEnemy::StaticClass() == GetClass()))
	{
		AIEnemy::__CustomDynamicClassInitialization(CastChecked<UDynamicClass>(GetClass()));
	}

	auto __Local__0 = CastChecked<UCapsuleComponent>(this->GetDefaultSubobjectByName(TEXT("CollisionCylinder")), ECastCheckedType::NullAllowed);
	auto __Local__1 = CastChecked<UCharacterMovementComponent>(this->GetDefaultSubobjectByName(TEXT("CharMoveComp")), ECastCheckedType::NullAllowed);
	auto __Local__2 = CastChecked<USkeletalMeshComponent>(this->GetDefaultSubobjectByName(TEXT("CharacterMesh0")), ECastCheckedType::NullAllowed);
	if(__Local__0)
	{
		// --- Default subobject 'CollisionCylinder' //
		auto& __Local__3 = (*(AccessPrivateProperty<float >((__Local__0), UCapsuleComponent::__PPO__CapsuleHalfHeight() )));
		__Local__3 = 65.353058f;
		auto& __Local__4 = (*(AccessPrivateProperty<float >((__Local__0), UCapsuleComponent::__PPO__CapsuleRadius() )));
		__Local__4 = 60.044453f;
		if(!__Local__0->IsTemplate())
		{
			__Local__0->BodyInstance.FixupData(__Local__0);
		}
		// --- END default subobject 'CollisionCylinder' //
	}
	if(__Local__1)
	{
		// --- Default subobject 'CharMoveComp' //
		__Local__1->MaxWalkSpeedCrouched = 100.000000f;
		__Local__1->MaxCustomMovementSpeed = 100.000000f;
		__Local__1->InitialPushForceFactor = 300.000000f;
		static TWeakObjectPtr<UProperty> __Local__6{};
		const UProperty* __Local__5 = __Local__6.Get();
		if (nullptr == __Local__5)
		{
			__Local__5 = (UNavMovementComponent::StaticClass())->FindPropertyByName(FName(TEXT("bUseAccelerationForPaths")));
			check(__Local__5);
			__Local__6 = __Local__5;
		}
		(((UBoolProperty*)__Local__5)->SetPropertyValue_InContainer((__Local__1), false, 0));
		// --- END default subobject 'CharMoveComp' //
	}
	if(__Local__2)
	{
		// --- Default subobject 'CharacterMesh0' //
		__Local__2->AnimClass = UEnemyAnimBP_C__pf2989283815::StaticClass();
		__Local__2->ClothingSimulationFactory = UClothingSimulationFactoryNv::StaticClass();
		__Local__2->SkeletalMesh = CastChecked<USkeletalMesh>(CastChecked<UDynamicClass>(AIEnemy::StaticClass())->UsedAssets[0], ECastCheckedType::NullAllowed);
		auto& __Local__7 = (*(AccessPrivateProperty<UCapsuleComponent*>((__Local__2), USceneComponent::__PPO__AttachParent() )));
		__Local__7 = __Local__0;
		__Local__2->RelativeLocation = FVector(-10.000000, 0.000000, -64.500000);
		__Local__2->RelativeScale3D = FVector(1.750000, 1.750000, 1.750000);
		if(!__Local__2->IsTemplate())
		{
			__Local__2->BodyInstance.FixupData(__Local__2);
		}
		// --- END default subobject 'CharacterMesh0' //
	}
	bpv__isAggro__pf = CreateDefaultSubobject<UTextRenderComponent>(TEXT("isAggro"));
	bpv__Scene__pf = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	bpv__healthBar__pf = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("healthBar"));
	bpv__isAggro__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__isAggro__pf->AttachToComponent(__Local__0, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__isAggro__pf->Font = CastChecked<UFont>(CastChecked<UDynamicClass>(AIEnemy::StaticClass())->UsedAssets[1], ECastCheckedType::NullAllowed);
	bpv__isAggro__pf->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	bpv__isAggro__pf->VerticalAlignment = EVerticalTextAligment::EVRTA_TextCenter;
	bpv__isAggro__pf->RelativeLocation = FVector(20.000000, 0.000000, 190.000000);
	bpv__isAggro__pf->RelativeScale3D = FVector(0.500000, 0.500000, 0.500000);
	if(!bpv__isAggro__pf->IsTemplate())
	{
		bpv__isAggro__pf->BodyInstance.FixupData(bpv__isAggro__pf);
	}
	bpv__Scene__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__Scene__pf->AttachToComponent(__Local__0, FAttachmentTransformRules::KeepRelativeTransform );
	bpv__Scene__pf->RelativeLocation = FVector(20.000000, -0.000011, 150.000000);
	bpv__Scene__pf->RelativeRotation = FRotator(0.000007, -0.000031, -90.000214);
	bpv__Scene__pf->RelativeScale3D = FVector(0.250000, 0.250000, 1.750000);
	bpv__healthBar__pf->CreationMethod = EComponentCreationMethod::Native;
	bpv__healthBar__pf->AttachToComponent(bpv__Scene__pf, FAttachmentTransformRules::KeepRelativeTransform );
	auto& __Local__8 = (*(AccessPrivateProperty<UStaticMesh* >((bpv__healthBar__pf), UStaticMeshComponent::__PPO__StaticMesh() )));
	__Local__8 = CastChecked<UStaticMesh>(CastChecked<UDynamicClass>(AIEnemy::StaticClass())->UsedAssets[2], ECastCheckedType::NullAllowed);
	bpv__healthBar__pf->OverrideMaterials = TArray<UMaterialInterface*> ();
	bpv__healthBar__pf->OverrideMaterials.Reserve(1);
	bpv__healthBar__pf->OverrideMaterials.Add(CastChecked<UMaterialInterface>(CastChecked<UDynamicClass>(AIEnemy::StaticClass())->UsedAssets[3], ECastCheckedType::NullAllowed));
	bpv__healthBar__pf->RelativeRotation = FRotator(0.000000, 0.000000, -0.000000);
	if(!bpv__healthBar__pf->IsTemplate())
	{
		bpv__healthBar__pf->BodyInstance.FixupData(bpv__healthBar__pf);
	}
	bpv__isTargeting__pf = FText::GetEmpty();
	bpv__Health__pf = 1.000000f;
	bpv__attackingPlayer__pf = false;
	bpv__barScale__pf = FVector(0.000000, 0.000000, 0.000000);
	auto& __Local__9 = (*(AccessPrivateProperty<USkeletalMeshComponent*>((this), ACharacter::__PPO__Mesh() )));
	__Local__9 = __Local__2;
	auto& __Local__10 = (*(AccessPrivateProperty<UCharacterMovementComponent*>((this), ACharacter::__PPO__CharacterMovement() )));
	__Local__10 = __Local__1;
	auto& __Local__11 = (*(AccessPrivateProperty<UCapsuleComponent*>((this), ACharacter::__PPO__CapsuleComponent() )));
	__Local__11 = __Local__0;
}
PRAGMA_ENABLE_OPTIMIZATION
void AIEnemy::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
	if(bpv__isAggro__pf)
	{
		bpv__isAggro__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__Scene__pf)
	{
		bpv__Scene__pf->CreationMethod = EComponentCreationMethod::Native;
	}
	if(bpv__healthBar__pf)
	{
		bpv__healthBar__pf->CreationMethod = EComponentCreationMethod::Native;
	}
}
PRAGMA_DISABLE_OPTIMIZATION
void AIEnemy::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();
	// List of all referenced converted classes
	InDynamicClass->ReferencedConvertedFields.Add(AMotionControllerPawn_C__pf563933975::StaticClass());
	InDynamicClass->ReferencedConvertedFields.Add(UmyGameInstance_C__pf789957808::StaticClass());
	InDynamicClass->ReferencedConvertedFields.Add(UEnemyAnimBP_C__pf2989283815::StaticClass());
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
	auto __Local__12 = NewObject<USceneComponent>(InDynamicClass, USceneComponent::StaticClass(), TEXT("DefaultSceneRoot_GEN_VARIABLE"));
	InDynamicClass->ComponentTemplates.Add(__Local__12);
	auto __Local__13 = NewObject<UComponentDelegateBinding>(InDynamicClass, UComponentDelegateBinding::StaticClass(), TEXT("ComponentDelegateBinding_3"));
	InDynamicClass->DynamicBindingObjects.Add(__Local__13);
	__Local__13->ComponentDelegateBindings = TArray<FBlueprintComponentDelegateBinding> ();
	__Local__13->ComponentDelegateBindings.AddUninitialized(1);
	FBlueprintComponentDelegateBinding::StaticStruct()->InitializeStruct(__Local__13->ComponentDelegateBindings.GetData(), 1);
	auto& __Local__14 = __Local__13->ComponentDelegateBindings[0];
	__Local__14.ComponentPropertyName = FName(TEXT("CapsuleComponent"));
	__Local__14.DelegatePropertyName = FName(TEXT("OnComponentBeginOverlap"));
	__Local__14.FunctionNameToBind = FName(TEXT("BndEvt__CapsuleComponent_K2Node_ComponentBoundEvent_1_ComponentBeginOverlapSignature__DelegateSignature"));
}
PRAGMA_ENABLE_OPTIMIZATION
void AIEnemy::bpf__ExecuteUbergraph_AIEnemy__pf_0(int32 bpp__EntryPoint__pf)
{
	FVector bpfv__CallFunc_MakeVector_ReturnValue__pf(EForceInit::ForceInit);
	bool bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue1__pf{};
	float bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf{};
	check(bpp__EntryPoint__pf == 46);
	bpf__playSwordSound__pf();
	bpf__swordFeedback__pf();
	b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn2__pf = Cast<AMotionControllerPawn_C__pf563933975>(b0l__K2Node_ComponentBoundEvent_OtherActor__pf);
	b0l__K2Node_DynamicCast_bSuccess5__pf = (b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn2__pf != nullptr);;
	if (!b0l__K2Node_DynamicCast_bSuccess5__pf)
	{
		return; //Component_EndOfThreadIfNot
	}
	bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Subtract_FloatFloat(bpv__Health__pf, 0.125000);
	bpv__Health__pf = bpfv__CallFunc_Subtract_FloatFloat_ReturnValue__pf;
	bpfv__CallFunc_MakeVector_ReturnValue__pf = UKismetMathLibrary::MakeVector(1.000000, 1.000000, bpv__Health__pf);
	if(::IsValid(bpv__healthBar__pf))
	{
		bpv__healthBar__pf->SetRelativeScale3D(bpfv__CallFunc_MakeVector_ReturnValue__pf);
	}
	bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue1__pf = UKismetMathLibrary::LessEqual_FloatFloat(bpv__Health__pf, 0.000000);
	if (!bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue1__pf)
	{
		return; //Component_EndOfThreadIfNot
	}
	K2_DestroyActor();
	return; //Component_EndOfThread
}
void AIEnemy::bpf__ExecuteUbergraph_AIEnemy__pf_1(int32 bpp__EntryPoint__pf)
{
	int32 bpfv__CallFunc_RandomInteger_ReturnValue__pf{};
	FVector bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf(EForceInit::ForceInit);
	float bpfv__CallFunc_RandomFloat_ReturnValue__pf{};
	float bpfv__CallFunc_RandomFloat_ReturnValue1__pf{};
	float bpfv__CallFunc_RandomFloat_ReturnValue2__pf{};
	int32 CurrentState = bpp__EntryPoint__pf;
	do
	{
		switch( CurrentState )
		{
		case 54:
			{
				bpfv__CallFunc_RandomInteger_ReturnValue__pf = UKismetMathLibrary::RandomInteger(2);
				b0l__K2Node_SwitchInteger_CmpSuccess__pf = UKismetMathLibrary::NotEqual_IntInt(bpfv__CallFunc_RandomInteger_ReturnValue__pf, 0);
				if (!b0l__K2Node_SwitchInteger_CmpSuccess__pf)
				{
					CurrentState = 57;
					break;
				}
				b0l__K2Node_SwitchInteger_CmpSuccess__pf = UKismetMathLibrary::NotEqual_IntInt(bpfv__CallFunc_RandomInteger_ReturnValue__pf, 1);
				if (!b0l__K2Node_SwitchInteger_CmpSuccess__pf)
				{
					CurrentState = 56;
					break;
				}
			}
		case 55:
			{
				bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf = AActor::K2_GetActorLocation();
				bpfv__CallFunc_RandomFloat_ReturnValue2__pf = UKismetMathLibrary::RandomFloat();
				UGameplayStatics::PlaySoundAtLocation(this, CastChecked<USoundBase>(CastChecked<UDynamicClass>(AIEnemy::StaticClass())->UsedAssets[4], ECastCheckedType::NullAllowed), bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf, FRotator(0.000000,0.000000,0.000000), bpfv__CallFunc_RandomFloat_ReturnValue2__pf, 1.000000, 0.000000, ((USoundAttenuation*)nullptr), ((USoundConcurrency*)nullptr), ((AActor*)nullptr));
				CurrentState = -1;
				break;
			}
		case 56:
			{
				bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf = AActor::K2_GetActorLocation();
				bpfv__CallFunc_RandomFloat_ReturnValue__pf = UKismetMathLibrary::RandomFloat();
				UGameplayStatics::PlaySoundAtLocation(this, CastChecked<USoundBase>(CastChecked<UDynamicClass>(AIEnemy::StaticClass())->UsedAssets[5], ECastCheckedType::NullAllowed), bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf, FRotator(0.000000,0.000000,0.000000), bpfv__CallFunc_RandomFloat_ReturnValue__pf, 1.000000, 0.000000, ((USoundAttenuation*)nullptr), ((USoundConcurrency*)nullptr), ((AActor*)nullptr));
				CurrentState = -1;
				break;
			}
		case 57:
			{
				bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf = AActor::K2_GetActorLocation();
				bpfv__CallFunc_RandomFloat_ReturnValue1__pf = UKismetMathLibrary::RandomFloat();
				UGameplayStatics::PlaySoundAtLocation(this, CastChecked<USoundBase>(CastChecked<UDynamicClass>(AIEnemy::StaticClass())->UsedAssets[6], ECastCheckedType::NullAllowed), bpfv__CallFunc_K2_GetActorLocation_ReturnValue__pf, FRotator(0.000000,0.000000,0.000000), bpfv__CallFunc_RandomFloat_ReturnValue1__pf, 1.000000, 0.000000, ((USoundAttenuation*)nullptr), ((USoundConcurrency*)nullptr), ((AActor*)nullptr));
				CurrentState = -1;
				break;
			}
		case 58:
			{
				CurrentState = 54;
				break;
			}
		default:
			break;
		}
	} while( CurrentState != -1 );
}
void AIEnemy::bpf__ExecuteUbergraph_AIEnemy__pf_2(int32 bpp__EntryPoint__pf)
{
	APlayerController* bpfv__CallFunc_GetPlayerController_ReturnValue__pf{};
	check(bpp__EntryPoint__pf == 59);
	// optimized Component_UnconditionalGoto
	bpfv__CallFunc_GetPlayerController_ReturnValue__pf = UGameplayStatics::GetPlayerController(this, 0);
	if(::IsValid(bpfv__CallFunc_GetPlayerController_ReturnValue__pf))
	{
		bpfv__CallFunc_GetPlayerController_ReturnValue__pf->APlayerController::PlayHapticEffect(CastChecked<UHapticFeedbackEffect_Base>(CastChecked<UDynamicClass>(AIEnemy::StaticClass())->UsedAssets[7], ECastCheckedType::NullAllowed), EControllerHand::Right, 1.000000, false);
	}
	return; //Component_EndOfThread
}
void AIEnemy::bpf__ExecuteUbergraph_AIEnemy__pf_3(int32 bpp__EntryPoint__pf)
{
	APawn* bpfv__CallFunc_GetPlayerPawn_ReturnValue__pf{};
	APawn* bpfv__CallFunc_GetPlayerPawn_ReturnValue1__pf{};
	float bpfv__CallFunc_GetHorizontalDistanceTo_ReturnValue__pf{};
	bool bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue__pf{};
	FText bpfv__CallFunc_Conv_StringToText_ReturnValue__pf{};
	FText bpfv__CallFunc_Conv_StringToText_ReturnValue1__pf{};
	UGameInstance* bpfv__CallFunc_GetGameInstance_ReturnValue1__pf{};
	UGameInstance* bpfv__CallFunc_GetGameInstance_ReturnValue2__pf{};
	int32 CurrentState = bpp__EntryPoint__pf;
	do
	{
		switch( CurrentState )
		{
		case 1:
			{
			}
		case 2:
			{
				(b0l__CallFunc_GetAllActorsOfClass_OutActors__pf).Reset();
				UGameplayStatics::GetAllActorsOfClass(this, ATargetPoint::StaticClass(), /*out*/ TArrayCaster<ATargetPoint*>(b0l__CallFunc_GetAllActorsOfClass_OutActors__pf).Get<AActor*>());
			}
		case 3:
			{
				FCustomThunkTemplates::Array_Get(b0l__CallFunc_GetAllActorsOfClass_OutActors__pf, 0, /*out*/ b0l__CallFunc_Array_Get_Item__pf);
				b0l__CallFunc_CreateMoveToProxyObject_ReturnValue1__pf = UAIBlueprintHelperLibrary::CreateMoveToProxyObject(this, this, FVector(0.000000,0.000000,0.000000), b0l__CallFunc_Array_Get_Item__pf, 5.000000, false);
			}
		case 4:
			{
				b0l__CallFunc_IsValid_ReturnValue1__pf = UKismetSystemLibrary::IsValid(b0l__CallFunc_CreateMoveToProxyObject_ReturnValue1__pf);
				if (!b0l__CallFunc_IsValid_ReturnValue1__pf)
				{
					CurrentState = -1;
					break;
				}
			}
		case 5:
			{
				b0l__K2Node_CreateDelegate_OutputDelegate__pf.BindUFunction(this,FName(TEXT("OnSuccess_B6ECDAD743B3A449680D9EB557F61FED")));
				if(::IsValid(b0l__CallFunc_CreateMoveToProxyObject_ReturnValue1__pf))
				{
					b0l__CallFunc_CreateMoveToProxyObject_ReturnValue1__pf->OnSuccess.AddUnique(b0l__K2Node_CreateDelegate_OutputDelegate__pf);
				}
			}
		case 6:
			{
				b0l__K2Node_CreateDelegate_OutputDelegate4__pf.BindUFunction(this,FName(TEXT("OnFail_B6ECDAD743B3A449680D9EB557F61FED")));
				if(::IsValid(b0l__CallFunc_CreateMoveToProxyObject_ReturnValue1__pf))
				{
					b0l__CallFunc_CreateMoveToProxyObject_ReturnValue1__pf->OnFail.AddUnique(b0l__K2Node_CreateDelegate_OutputDelegate4__pf);
				}
				CurrentState = -1;
				break;
			}
		case 8:
			{
			}
		case 9:
			{
				b0l__CallFunc_CreateMoveToProxyObject_ReturnValue__pf = UAIBlueprintHelperLibrary::CreateMoveToProxyObject(this, this, FVector(0.000000,0.000000,0.000000), b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn__pf, 4.000000, true);
			}
		case 10:
			{
				b0l__CallFunc_IsValid_ReturnValue__pf = UKismetSystemLibrary::IsValid(b0l__CallFunc_CreateMoveToProxyObject_ReturnValue__pf);
				if (!b0l__CallFunc_IsValid_ReturnValue__pf)
				{
					CurrentState = -1;
					break;
				}
			}
		case 11:
			{
				b0l__K2Node_CreateDelegate_OutputDelegate2__pf.BindUFunction(this,FName(TEXT("OnSuccess_363CE5FF40B7B19F327948B8098A5576")));
				if(::IsValid(b0l__CallFunc_CreateMoveToProxyObject_ReturnValue__pf))
				{
					b0l__CallFunc_CreateMoveToProxyObject_ReturnValue__pf->OnSuccess.AddUnique(b0l__K2Node_CreateDelegate_OutputDelegate2__pf);
				}
			}
		case 12:
			{
				b0l__K2Node_CreateDelegate_OutputDelegate1__pf.BindUFunction(this,FName(TEXT("OnFail_363CE5FF40B7B19F327948B8098A5576")));
				if(::IsValid(b0l__CallFunc_CreateMoveToProxyObject_ReturnValue__pf))
				{
					b0l__CallFunc_CreateMoveToProxyObject_ReturnValue__pf->OnFail.AddUnique(b0l__K2Node_CreateDelegate_OutputDelegate1__pf);
				}
				CurrentState = -1;
				break;
			}
		case 30:
			{
				UKismetSystemLibrary::Delay(this, 0.200000, FLatentActionInfo(1, 1519817796, TEXT("ExecuteUbergraph_AIEnemy_3"), this));
				CurrentState = -1;
				break;
			}
		case 31:
			{
				bpfv__CallFunc_GetPlayerPawn_ReturnValue__pf = UGameplayStatics::GetPlayerPawn(this, 0);
				b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn__pf = Cast<AMotionControllerPawn_C__pf563933975>(bpfv__CallFunc_GetPlayerPawn_ReturnValue__pf);
				b0l__K2Node_DynamicCast_bSuccess__pf = (b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn__pf != nullptr);;
				if (!b0l__K2Node_DynamicCast_bSuccess__pf)
				{
					CurrentState = -1;
					break;
				}
			}
		case 32:
			{
				UKismetSystemLibrary::Delay(this, 0.100000, FLatentActionInfo(8, 1587906956, TEXT("ExecuteUbergraph_AIEnemy_3"), this));
				CurrentState = -1;
				break;
			}
		case 33:
			{
				bpfv__CallFunc_GetPlayerPawn_ReturnValue1__pf = UGameplayStatics::GetPlayerPawn(this, 0);
				b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn1__pf = Cast<AMotionControllerPawn_C__pf563933975>(bpfv__CallFunc_GetPlayerPawn_ReturnValue1__pf);
				b0l__K2Node_DynamicCast_bSuccess1__pf = (b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn1__pf != nullptr);;
				if (!b0l__K2Node_DynamicCast_bSuccess1__pf)
				{
					CurrentState = -1;
					break;
				}
			}
		case 34:
			{
				if(::IsValid(b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn1__pf))
				{
					bpfv__CallFunc_GetHorizontalDistanceTo_ReturnValue__pf = b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn1__pf->AActor::GetHorizontalDistanceTo(this);
				}
				bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue__pf = UKismetMathLibrary::LessEqual_FloatFloat(bpfv__CallFunc_GetHorizontalDistanceTo_ReturnValue__pf, 1000.000000);
				if (!bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue__pf)
				{
					CurrentState = 39;
					break;
				}
			}
		case 35:
			{
				bpfv__CallFunc_Conv_StringToText_ReturnValue__pf = UKismetTextLibrary::Conv_StringToText(FString(TEXT("Aggro!")));
				if(::IsValid(bpv__isAggro__pf))
				{
					bpv__isAggro__pf->UTextRenderComponent::K2_SetText(bpfv__CallFunc_Conv_StringToText_ReturnValue__pf);
				}
			}
		case 36:
			{
				if(::IsValid(b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn1__pf))
				{
					bpfv__CallFunc_GetHorizontalDistanceTo_ReturnValue__pf = b0l__K2Node_DynamicCast_AsMotion_Controller_Pawn1__pf->AActor::GetHorizontalDistanceTo(this);
				}
				bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue__pf = UKismetMathLibrary::LessEqual_FloatFloat(bpfv__CallFunc_GetHorizontalDistanceTo_ReturnValue__pf, 1000.000000);
				if (!bpfv__CallFunc_LessEqual_FloatFloat_ReturnValue__pf)
				{
					CurrentState = 40;
					break;
				}
			}
		case 37:
			{
				bpfv__CallFunc_GetGameInstance_ReturnValue1__pf = UGameplayStatics::GetGameInstance(this);
				b0l__K2Node_DynamicCast_AsMy_Game_Instance1__pf = Cast<UmyGameInstance_C__pf789957808>(bpfv__CallFunc_GetGameInstance_ReturnValue1__pf);
				b0l__K2Node_DynamicCast_bSuccess3__pf = (b0l__K2Node_DynamicCast_AsMy_Game_Instance1__pf != nullptr);;
				if (!b0l__K2Node_DynamicCast_bSuccess3__pf)
				{
					CurrentState = -1;
					break;
				}
			}
		case 38:
			{
				if(::IsValid(b0l__K2Node_DynamicCast_AsMy_Game_Instance1__pf))
				{
					b0l__K2Node_DynamicCast_AsMy_Game_Instance1__pf->bpv__enemySpeed__pf = 600.000000;
				}
				CurrentState = 31;
				break;
			}
		case 39:
			{
				bpfv__CallFunc_Conv_StringToText_ReturnValue1__pf = UKismetTextLibrary::Conv_StringToText(FString(TEXT("Docile")));
				if(::IsValid(bpv__isAggro__pf))
				{
					bpv__isAggro__pf->UTextRenderComponent::K2_SetText(bpfv__CallFunc_Conv_StringToText_ReturnValue1__pf);
				}
				CurrentState = 36;
				break;
			}
		case 40:
			{
				bpv__attackingPlayer__pf = false;
			}
		case 41:
			{
				bpfv__CallFunc_GetGameInstance_ReturnValue2__pf = UGameplayStatics::GetGameInstance(this);
				b0l__K2Node_DynamicCast_AsMy_Game_Instance2__pf = Cast<UmyGameInstance_C__pf789957808>(bpfv__CallFunc_GetGameInstance_ReturnValue2__pf);
				b0l__K2Node_DynamicCast_bSuccess4__pf = (b0l__K2Node_DynamicCast_AsMy_Game_Instance2__pf != nullptr);;
				if (!b0l__K2Node_DynamicCast_bSuccess4__pf)
				{
					CurrentState = -1;
					break;
				}
			}
		case 42:
			{
				if(::IsValid(b0l__K2Node_DynamicCast_AsMy_Game_Instance2__pf))
				{
					b0l__K2Node_DynamicCast_AsMy_Game_Instance2__pf->bpv__enemySpeed__pf = 250.000000;
				}
			}
		case 43:
			{
				float  __Local__17 = 0.000000;
				if(::IsValid((*(AccessPrivateProperty<UCharacterMovementComponent* >((this), ACharacter::__PPO__CharacterMovement() )))))
				{
					(*(AccessPrivateProperty<UCharacterMovementComponent* >((this), ACharacter::__PPO__CharacterMovement() )))->MaxWalkSpeed = ((::IsValid(b0l__K2Node_DynamicCast_AsMy_Game_Instance2__pf)) ? (b0l__K2Node_DynamicCast_AsMy_Game_Instance2__pf->bpv__enemySpeed__pf) : (__Local__17));
				}
				CurrentState = 30;
				break;
			}
		case 45:
			{
				CurrentState = 33;
				break;
			}
		default:
			break;
		}
	} while( CurrentState != -1 );
}
void AIEnemy::bpf__ExecuteUbergraph_AIEnemy__pf_4(int32 bpp__EntryPoint__pf)
{
	FTimerHandle bpfv__CallFunc_K2_SetTimerDelegate_ReturnValue__pf{};
	check(bpp__EntryPoint__pf == 44);
	// optimized Component_UnconditionalGoto
	b0l__K2Node_CreateDelegate_OutputDelegate3__pf.BindUFunction(this,FName(TEXT("SpawnEnemies")));
	bpfv__CallFunc_K2_SetTimerDelegate_ReturnValue__pf = UKismetSystemLibrary::K2_SetTimerDelegate(b0l__K2Node_CreateDelegate_OutputDelegate3__pf, 0.100000, true);
	return; //Component_EndOfThread
}
void AIEnemy::bpf__ExecuteUbergraph_AIEnemy__pf_5(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 26);
	b0l__Temp_byte_Variable1__pf = b0l__K2Node_CustomEvent_MovementResult__pf;
	bpv__attackingPlayer__pf = true;
	return; //Component_EndOfThread
}
void AIEnemy::bpf__ExecuteUbergraph_AIEnemy__pf_6(int32 bpp__EntryPoint__pf)
{
	UGameInstance* bpfv__CallFunc_GetGameInstance_ReturnValue__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue__pf{};
	check(bpp__EntryPoint__pf == 15);
	b0l__Temp_byte_Variable__pf = b0l__K2Node_CustomEvent_MovementResult2__pf;
	K2_DestroyActor();
	bpfv__CallFunc_GetGameInstance_ReturnValue__pf = UGameplayStatics::GetGameInstance(this);
	b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf = Cast<UmyGameInstance_C__pf789957808>(bpfv__CallFunc_GetGameInstance_ReturnValue__pf);
	b0l__K2Node_DynamicCast_bSuccess2__pf = (b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf != nullptr);;
	if (!b0l__K2Node_DynamicCast_bSuccess2__pf)
	{
		return; //Component_EndOfThreadIfNot
	}
	int32  __Local__18 = 0;
	bpfv__CallFunc_Add_IntInt_ReturnValue__pf = UKismetMathLibrary::Add_IntInt(((::IsValid(b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf)) ? (b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf->bpv__numEnemies__pf) : (__Local__18)), 1);
	if(::IsValid(b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf))
	{
		b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf->bpv__numEnemies__pf = bpfv__CallFunc_Add_IntInt_ReturnValue__pf;
	}
	int32  __Local__19 = 0;
	if(::IsValid(b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf))
	{
		b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf->bpv__numEnemies__pf = ((::IsValid(b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf)) ? (b0l__K2Node_DynamicCast_AsMy_Game_Instance__pf->bpv__numEnemies__pf) : (__Local__19));
	}
	return; //Component_EndOfThread
}
void AIEnemy::bpf__ExecuteUbergraph_AIEnemy__pf_7(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 24);
	b0l__Temp_byte_Variable1__pf = b0l__K2Node_CustomEvent_MovementResult1__pf;
	return; //Component_EndOfThread
}
void AIEnemy::bpf__ExecuteUbergraph_AIEnemy__pf_8(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 13);
	b0l__Temp_byte_Variable__pf = b0l__K2Node_CustomEvent_MovementResult3__pf;
	return; //Component_EndOfThread
}
void AIEnemy::bpf__swordFeedback__pf()
{
	bpf__ExecuteUbergraph_AIEnemy__pf_2(59);
}
void AIEnemy::bpf__playSwordSound__pf()
{
	bpf__ExecuteUbergraph_AIEnemy__pf_1(58);
}
void AIEnemy::bpf__BndEvt__CapsuleComponent_K2Node_ComponentBoundEvent_1_ComponentBeginOverlapSignature__DelegateSignature__pf(UPrimitiveComponent* bpp__OverlappedComponent__pf, AActor* bpp__OtherActor__pf, UPrimitiveComponent* bpp__OtherComp__pf, int32 bpp__OtherBodyIndex__pf, bool bpp__bFromSweep__pf, FHitResult const& bpp__SweepResult__pf__const)
{
	typedef FHitResult  T__Local__20;
	T__Local__20& bpp__SweepResult__pf = *const_cast<T__Local__20 *>(&bpp__SweepResult__pf__const);
	b0l__K2Node_ComponentBoundEvent_OverlappedComponent__pf = bpp__OverlappedComponent__pf;
	b0l__K2Node_ComponentBoundEvent_OtherActor__pf = bpp__OtherActor__pf;
	b0l__K2Node_ComponentBoundEvent_OtherComp__pf = bpp__OtherComp__pf;
	b0l__K2Node_ComponentBoundEvent_OtherBodyIndex__pf = bpp__OtherBodyIndex__pf;
	b0l__K2Node_ComponentBoundEvent_bFromSweep__pf = bpp__bFromSweep__pf;
	b0l__K2Node_ComponentBoundEvent_SweepResult__pf = bpp__SweepResult__pf;
	bpf__ExecuteUbergraph_AIEnemy__pf_0(46);
}
void AIEnemy::bpf__SpawnEnemies__pf()
{
	bpf__ExecuteUbergraph_AIEnemy__pf_3(45);
}
void AIEnemy::bpf__ReceiveBeginPlay__pf()
{
	bpf__ExecuteUbergraph_AIEnemy__pf_4(44);
}
void AIEnemy::bpf__OnSuccess_363CE5FF40B7B19F327948B8098A5576__pf(EPathFollowingResult::Type bpp__MovementResult__pf)
{
	b0l__K2Node_CustomEvent_MovementResult__pf = bpp__MovementResult__pf;
	bpf__ExecuteUbergraph_AIEnemy__pf_5(26);
}
void AIEnemy::bpf__OnFail_363CE5FF40B7B19F327948B8098A5576__pf(EPathFollowingResult::Type bpp__MovementResult__pf)
{
	b0l__K2Node_CustomEvent_MovementResult1__pf = bpp__MovementResult__pf;
	bpf__ExecuteUbergraph_AIEnemy__pf_7(24);
}
void AIEnemy::bpf__OnSuccess_B6ECDAD743B3A449680D9EB557F61FED__pf(EPathFollowingResult::Type bpp__MovementResult__pf)
{
	b0l__K2Node_CustomEvent_MovementResult2__pf = bpp__MovementResult__pf;
	bpf__ExecuteUbergraph_AIEnemy__pf_6(15);
}
void AIEnemy::bpf__OnFail_B6ECDAD743B3A449680D9EB557F61FED__pf(EPathFollowingResult::Type bpp__MovementResult__pf)
{
	b0l__K2Node_CustomEvent_MovementResult3__pf = bpp__MovementResult__pf;
	bpf__ExecuteUbergraph_AIEnemy__pf_8(13);
}
void AIEnemy::bpf__UserConstructionScript__pf()
{
}
PRAGMA_DISABLE_OPTIMIZATION
void AIEnemy::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{0, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  SkeletalMesh /Game/Imported-Content/orc/orc.orc
		{1, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Font /Game/Imported-Content/chinese_rocks_rg_Font.chinese_rocks_rg_Font
		{2, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  StaticMesh /Engine/BasicShapes/Cylinder.Cylinder
		{3, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Material /Engine/EngineMaterials/EditorBrushMaterial.EditorBrushMaterial
		{4, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  SoundWave /Game/Imported-Content/sword_hit.sword_hit
		{5, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  SoundWave /Game/Imported-Content/fleshHit.fleshHit
		{6, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  SoundWave /Game/Imported-Content/chainhit.chainhit
		{7, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  HapticFeedbackEffect_Curve /Game/VirtualRealityBP/Blueprints/swordhitHaptics.swordhitHaptics
	};
	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}
}
PRAGMA_ENABLE_OPTIMIZATION
PRAGMA_DISABLE_OPTIMIZATION
void AIEnemy::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_DirectlyUsedAssets(AssetsToLoad);
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{8, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, true, false)},  //  Class /Script/Engine.TextRenderComponent
		{9, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Material /Engine/EngineMaterials/DefaultTextMaterialOpaque.DefaultTextMaterialOpaque
		{10, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, true, false)},  //  Class /Script/Engine.SceneComponent
		{11, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, true, false)},  //  Class /Script/Engine.StaticMeshComponent
		{12, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.PointerToUberGraphFrame
		{13, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.PlayerController
		{14, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Enum /Script/AIModule.EPathFollowingResult
		{15, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  DelegateFunction /Script/AIModule.OAISimpleDelegate__DelegateSignature
		{16, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  DelegateFunction /Script/Engine.TimerDynamicDelegate__DelegateSignature
		{17, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.TimerHandle
		{18, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.Pawn
		{19, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/AIModule.AIAsyncTaskBlueprintProxy
		{20, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.TargetPoint
		{21, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.GameInstance
		{22, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.PrimitiveComponent
		{23, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.Actor
		{24, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.HitResult
		{25, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.GameplayStatics
		{26, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetArrayLibrary
		{27, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/AIModule.AIBlueprintHelperLibrary
		{28, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetSystemLibrary
		{29, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetMathLibrary
		{30, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.LatentActionInfo
		{31, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetTextLibrary
		{32, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, true, false)},  //  Class /Script/Engine.CharacterMovementComponent
		{33, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.Character
		{34, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/ClothingSystemRuntime.ClothingSimulationFactoryNv
		{35, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.NavArea_Obstacle
		{36, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/AIModule.AIController
		{37, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  BlueprintGeneratedClass /Game/VirtualRealityBP/Blueprints/MotionControllerPawn.MotionControllerPawn_C
		{38, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  BlueprintGeneratedClass /Game/MyBlueprints/myGameInstance.myGameInstance_C
		{39, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  AnimBlueprintGeneratedClass /Game/MyBlueprints/EnemyAI/EnemyAnimBP.EnemyAnimBP_C
	};
	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}
}
PRAGMA_ENABLE_OPTIMIZATION
struct FRegisterHelper__AIEnemy
{
	FRegisterHelper__AIEnemy()
	{
		FConvertedBlueprintsDependencies::Get().RegisterConvertedClass(TEXT("/Game/MyBlueprints/EnemyAI/AIEnemy"), &AIEnemy::__StaticDependenciesAssets);
	}
	static FRegisterHelper__AIEnemy Instance;
};
FRegisterHelper__AIEnemy FRegisterHelper__AIEnemy::Instance;
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
