// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/BloqueLava.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueLava() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueLava();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueLava_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UParticleSystemComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueLava
void ABloqueLava::StaticRegisterNativesABloqueLava()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueLava);
UClass* Z_Construct_UClass_ABloqueLava_NoRegister()
{
	return ABloqueLava::StaticClass();
}
struct Z_Construct_UClass_ABloqueLava_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueLava.h" },
		{ "ModuleRelativePath", "BloqueLava.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ParticulasLava_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BloqueLava.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ParticulasLava;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueLava>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABloqueLava_Statics::NewProp_ParticulasLava = { "ParticulasLava", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABloqueLava, ParticulasLava), Z_Construct_UClass_UParticleSystemComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ParticulasLava_MetaData), NewProp_ParticulasLava_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABloqueLava_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABloqueLava_Statics::NewProp_ParticulasLava,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueLava_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ABloqueLava_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloque,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueLava_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueLava_Statics::ClassParams = {
	&ABloqueLava::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ABloqueLava_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueLava_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueLava_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueLava_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueLava()
{
	if (!Z_Registration_Info_UClass_ABloqueLava.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueLava.OuterSingleton, Z_Construct_UClass_ABloqueLava_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueLava.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueLava>()
{
	return ABloqueLava::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueLava);
ABloqueLava::~ABloqueLava() {}
// End Class ABloqueLava

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueLava_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueLava, ABloqueLava::StaticClass, TEXT("ABloqueLava"), &Z_Registration_Info_UClass_ABloqueLava, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueLava), 2700251649U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueLava_h_1725400038(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueLava_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueLava_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
