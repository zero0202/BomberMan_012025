// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/BloqueLadrillo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueLadrillo() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueLadrillo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueLadrillo_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueLadrillo Function AjustarTamanoAcero
struct Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics
{
	struct BloqueLadrillo_eventAjustarTamanoAcero_Parms
	{
		FVector NuevoTamano;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BloqueLadrillo.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NuevoTamano;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::NewProp_NuevoTamano = { "NuevoTamano", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BloqueLadrillo_eventAjustarTamanoAcero_Parms, NuevoTamano), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::NewProp_NuevoTamano,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABloqueLadrillo, nullptr, "AjustarTamanoAcero", nullptr, nullptr, Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::BloqueLadrillo_eventAjustarTamanoAcero_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::BloqueLadrillo_eventAjustarTamanoAcero_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABloqueLadrillo::execAjustarTamanoAcero)
{
	P_GET_STRUCT(FVector,Z_Param_NuevoTamano);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AjustarTamanoAcero(Z_Param_NuevoTamano);
	P_NATIVE_END;
}
// End Class ABloqueLadrillo Function AjustarTamanoAcero

// Begin Class ABloqueLadrillo
void ABloqueLadrillo::StaticRegisterNativesABloqueLadrillo()
{
	UClass* Class = ABloqueLadrillo::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AjustarTamanoAcero", &ABloqueLadrillo::execAjustarTamanoAcero },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueLadrillo);
UClass* Z_Construct_UClass_ABloqueLadrillo_NoRegister()
{
	return ABloqueLadrillo::StaticClass();
}
struct Z_Construct_UClass_ABloqueLadrillo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "BloqueLadrillo.h" },
		{ "ModuleRelativePath", "BloqueLadrillo.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshBloqueLadrillo_MetaData[] = {
		{ "Category", "BloqueLadrillo" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BloqueLadrillo.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BloqueLadrilloMaterial_MetaData[] = {
		{ "Category", "BloqueLadrillo" },
		{ "ModuleRelativePath", "BloqueLadrillo.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshBloqueLadrillo;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BloqueLadrilloMaterial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABloqueLadrillo_AjustarTamanoAcero, "AjustarTamanoAcero" }, // 3078042427
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueLadrillo>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABloqueLadrillo_Statics::NewProp_MeshBloqueLadrillo = { "MeshBloqueLadrillo", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABloqueLadrillo, MeshBloqueLadrillo), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshBloqueLadrillo_MetaData), NewProp_MeshBloqueLadrillo_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABloqueLadrillo_Statics::NewProp_BloqueLadrilloMaterial = { "BloqueLadrilloMaterial", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABloqueLadrillo, BloqueLadrilloMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BloqueLadrilloMaterial_MetaData), NewProp_BloqueLadrilloMaterial_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABloqueLadrillo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueLadrillo_Statics::NewProp_MeshBloqueLadrillo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueLadrillo_Statics::NewProp_BloqueLadrilloMaterial,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueLadrillo_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABloqueLadrillo_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueLadrillo_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueLadrillo_Statics::ClassParams = {
	&ABloqueLadrillo::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABloqueLadrillo_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueLadrillo_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueLadrillo_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueLadrillo_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueLadrillo()
{
	if (!Z_Registration_Info_UClass_ABloqueLadrillo.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueLadrillo.OuterSingleton, Z_Construct_UClass_ABloqueLadrillo_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueLadrillo.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueLadrillo>()
{
	return ABloqueLadrillo::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueLadrillo);
ABloqueLadrillo::~ABloqueLadrillo() {}
// End Class ABloqueLadrillo

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueLadrillo_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueLadrillo, ABloqueLadrillo::StaticClass, TEXT("ABloqueLadrillo"), &Z_Registration_Info_UClass_ABloqueLadrillo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueLadrillo), 3824265277U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueLadrillo_h_2444446269(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueLadrillo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueLadrillo_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
