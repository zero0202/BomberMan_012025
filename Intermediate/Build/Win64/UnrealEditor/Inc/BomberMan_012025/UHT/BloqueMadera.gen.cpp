// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/BloqueMadera.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueMadera() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueMadera();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueMadera_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueMadera Function AjustarTamanoAcero
struct Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics
{
	struct BloqueMadera_eventAjustarTamanoAcero_Parms
	{
		FVector NuevoTamano;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Posici\xef\xbf\xbdn inicial\n" },
#endif
		{ "ModuleRelativePath", "BloqueMadera.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Posici\xef\xbf\xbdn inicial" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NuevoTamano;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::NewProp_NuevoTamano = { "NuevoTamano", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BloqueMadera_eventAjustarTamanoAcero_Parms, NuevoTamano), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::NewProp_NuevoTamano,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABloqueMadera, nullptr, "AjustarTamanoAcero", nullptr, nullptr, Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::BloqueMadera_eventAjustarTamanoAcero_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::BloqueMadera_eventAjustarTamanoAcero_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABloqueMadera::execAjustarTamanoAcero)
{
	P_GET_STRUCT(FVector,Z_Param_NuevoTamano);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AjustarTamanoAcero(Z_Param_NuevoTamano);
	P_NATIVE_END;
}
// End Class ABloqueMadera Function AjustarTamanoAcero

// Begin Class ABloqueMadera
void ABloqueMadera::StaticRegisterNativesABloqueMadera()
{
	UClass* Class = ABloqueMadera::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AjustarTamanoAcero", &ABloqueMadera::execAjustarTamanoAcero },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueMadera);
UClass* Z_Construct_UClass_ABloqueMadera_NoRegister()
{
	return ABloqueMadera::StaticClass();
}
struct Z_Construct_UClass_ABloqueMadera_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "BloqueMadera.h" },
		{ "ModuleRelativePath", "BloqueMadera.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshBloqueMadera_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BloqueMadera.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BloqueMaderaMaterial_MetaData[] = {
		{ "ModuleRelativePath", "BloqueMadera.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshBloqueMadera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BloqueMaderaMaterial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABloqueMadera_AjustarTamanoAcero, "AjustarTamanoAcero" }, // 986689973
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueMadera>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABloqueMadera_Statics::NewProp_MeshBloqueMadera = { "MeshBloqueMadera", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABloqueMadera, MeshBloqueMadera), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshBloqueMadera_MetaData), NewProp_MeshBloqueMadera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABloqueMadera_Statics::NewProp_BloqueMaderaMaterial = { "BloqueMaderaMaterial", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABloqueMadera, BloqueMaderaMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BloqueMaderaMaterial_MetaData), NewProp_BloqueMaderaMaterial_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABloqueMadera_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueMadera_Statics::NewProp_MeshBloqueMadera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueMadera_Statics::NewProp_BloqueMaderaMaterial,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueMadera_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABloqueMadera_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueMadera_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueMadera_Statics::ClassParams = {
	&ABloqueMadera::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABloqueMadera_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueMadera_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueMadera_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueMadera_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueMadera()
{
	if (!Z_Registration_Info_UClass_ABloqueMadera.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueMadera.OuterSingleton, Z_Construct_UClass_ABloqueMadera_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueMadera.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueMadera>()
{
	return ABloqueMadera::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueMadera);
ABloqueMadera::~ABloqueMadera() {}
// End Class ABloqueMadera

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueMadera_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueMadera, ABloqueMadera::StaticClass, TEXT("ABloqueMadera"), &Z_Registration_Info_UClass_ABloqueMadera, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueMadera), 3174515068U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueMadera_h_3066233835(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueMadera_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueMadera_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
