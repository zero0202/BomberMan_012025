// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/BloqueAcero.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueAcero() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueAcero();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueAcero_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueAcero Function AjustarTamanoAcero
struct Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics
{
	struct BloqueAcero_eventAjustarTamanoAcero_Parms
	{
		FVector NuevoTamano;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BloqueAcero.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NuevoTamano;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::NewProp_NuevoTamano = { "NuevoTamano", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BloqueAcero_eventAjustarTamanoAcero_Parms, NuevoTamano), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::NewProp_NuevoTamano,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABloqueAcero, nullptr, "AjustarTamanoAcero", nullptr, nullptr, Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::BloqueAcero_eventAjustarTamanoAcero_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::BloqueAcero_eventAjustarTamanoAcero_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ABloqueAcero::execAjustarTamanoAcero)
{
	P_GET_STRUCT(FVector,Z_Param_NuevoTamano);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AjustarTamanoAcero(Z_Param_NuevoTamano);
	P_NATIVE_END;
}
// End Class ABloqueAcero Function AjustarTamanoAcero

// Begin Class ABloqueAcero
void ABloqueAcero::StaticRegisterNativesABloqueAcero()
{
	UClass* Class = ABloqueAcero::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AjustarTamanoAcero", &ABloqueAcero::execAjustarTamanoAcero },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueAcero);
UClass* Z_Construct_UClass_ABloqueAcero_NoRegister()
{
	return ABloqueAcero::StaticClass();
}
struct Z_Construct_UClass_ABloqueAcero_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "BloqueAcero.h" },
		{ "ModuleRelativePath", "BloqueAcero.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshBloqueAcero_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BloqueAcero.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BloqueAceroMaterial_MetaData[] = {
		{ "ModuleRelativePath", "BloqueAcero.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshBloqueAcero;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BloqueAceroMaterial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ABloqueAcero_AjustarTamanoAcero, "AjustarTamanoAcero" }, // 1552027926
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueAcero>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABloqueAcero_Statics::NewProp_MeshBloqueAcero = { "MeshBloqueAcero", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABloqueAcero, MeshBloqueAcero), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshBloqueAcero_MetaData), NewProp_MeshBloqueAcero_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABloqueAcero_Statics::NewProp_BloqueAceroMaterial = { "BloqueAceroMaterial", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABloqueAcero, BloqueAceroMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BloqueAceroMaterial_MetaData), NewProp_BloqueAceroMaterial_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABloqueAcero_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueAcero_Statics::NewProp_MeshBloqueAcero,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueAcero_Statics::NewProp_BloqueAceroMaterial,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueAcero_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABloqueAcero_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueAcero_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueAcero_Statics::ClassParams = {
	&ABloqueAcero::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ABloqueAcero_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueAcero_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueAcero_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueAcero_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueAcero()
{
	if (!Z_Registration_Info_UClass_ABloqueAcero.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueAcero.OuterSingleton, Z_Construct_UClass_ABloqueAcero_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueAcero.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueAcero>()
{
	return ABloqueAcero::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueAcero);
ABloqueAcero::~ABloqueAcero() {}
// End Class ABloqueAcero

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueAcero_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueAcero, ABloqueAcero::StaticClass, TEXT("ABloqueAcero"), &Z_Registration_Info_UClass_ABloqueAcero, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueAcero), 3367823258U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueAcero_h_2122823314(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueAcero_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueAcero_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
