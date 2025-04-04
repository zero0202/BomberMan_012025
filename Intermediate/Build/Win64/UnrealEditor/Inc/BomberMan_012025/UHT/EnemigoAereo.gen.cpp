// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/EnemigoAereo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemigoAereo() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAereo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAereo_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AEnemigoAereo Function AjustarTamanoA
struct Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics
{
	struct EnemigoAereo_eventAjustarTamanoA_Parms
	{
		FVector NuevoTamano;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EnemigoAereo.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NuevoTamano;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::NewProp_NuevoTamano = { "NuevoTamano", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EnemigoAereo_eventAjustarTamanoA_Parms, NuevoTamano), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::NewProp_NuevoTamano,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemigoAereo, nullptr, "AjustarTamanoA", nullptr, nullptr, Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::EnemigoAereo_eventAjustarTamanoA_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::EnemigoAereo_eventAjustarTamanoA_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEnemigoAereo::execAjustarTamanoA)
{
	P_GET_STRUCT(FVector,Z_Param_NuevoTamano);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AjustarTamanoA(Z_Param_NuevoTamano);
	P_NATIVE_END;
}
// End Class AEnemigoAereo Function AjustarTamanoA

// Begin Class AEnemigoAereo
void AEnemigoAereo::StaticRegisterNativesAEnemigoAereo()
{
	UClass* Class = AEnemigoAereo::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AjustarTamanoA", &AEnemigoAereo::execAjustarTamanoA },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemigoAereo);
UClass* Z_Construct_UClass_AEnemigoAereo_NoRegister()
{
	return AEnemigoAereo::StaticClass();
}
struct Z_Construct_UClass_AEnemigoAereo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemigoAereo.h" },
		{ "ModuleRelativePath", "EnemigoAereo.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParticleSystem_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EnemigoAereo.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlturaVuelo_MetaData[] = {
		{ "Category", "Movimiento A\xef\xbf\xbdreo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Altura a la que debe mantenerse volando\n" },
#endif
		{ "ModuleRelativePath", "EnemigoAereo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Altura a la que debe mantenerse volando" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParticleSystem;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AlturaVuelo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemigoAereo_AjustarTamanoA, "AjustarTamanoA" }, // 3788135974
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemigoAereo>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemigoAereo_Statics::NewProp_ParticleSystem = { "ParticleSystem", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemigoAereo, ParticleSystem), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParticleSystem_MetaData), NewProp_ParticleSystem_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigoAereo_Statics::NewProp_AlturaVuelo = { "AlturaVuelo", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemigoAereo, AlturaVuelo), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlturaVuelo_MetaData), NewProp_AlturaVuelo_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemigoAereo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAereo_Statics::NewProp_ParticleSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAereo_Statics::NewProp_AlturaVuelo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAereo_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEnemigoAereo_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemigo,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAereo_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemigoAereo_Statics::ClassParams = {
	&AEnemigoAereo::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEnemigoAereo_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAereo_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAereo_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemigoAereo_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemigoAereo()
{
	if (!Z_Registration_Info_UClass_AEnemigoAereo.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemigoAereo.OuterSingleton, Z_Construct_UClass_AEnemigoAereo_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemigoAereo.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AEnemigoAereo>()
{
	return AEnemigoAereo::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemigoAereo);
AEnemigoAereo::~AEnemigoAereo() {}
// End Class AEnemigoAereo

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereo_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemigoAereo, AEnemigoAereo::StaticClass, TEXT("AEnemigoAereo"), &Z_Registration_Info_UClass_AEnemigoAereo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemigoAereo), 712398852U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereo_h_368615459(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereo_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
