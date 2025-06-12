// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/FacadeDificultad.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFacadeDificultad() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AFacadeDificultad();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AFacadeDificultad_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AFacadeDificultad
void AFacadeDificultad::StaticRegisterNativesAFacadeDificultad()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFacadeDificultad);
UClass* Z_Construct_UClass_AFacadeDificultad_NoRegister()
{
	return AFacadeDificultad::StaticClass();
}
struct Z_Construct_UClass_AFacadeDificultad_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "FacadeDificultad.h" },
		{ "ModuleRelativePath", "FacadeDificultad.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFacadeDificultad>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AFacadeDificultad_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFacadeDificultad_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFacadeDificultad_Statics::ClassParams = {
	&AFacadeDificultad::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFacadeDificultad_Statics::Class_MetaDataParams), Z_Construct_UClass_AFacadeDificultad_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFacadeDificultad()
{
	if (!Z_Registration_Info_UClass_AFacadeDificultad.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFacadeDificultad.OuterSingleton, Z_Construct_UClass_AFacadeDificultad_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFacadeDificultad.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AFacadeDificultad>()
{
	return AFacadeDificultad::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFacadeDificultad);
AFacadeDificultad::~AFacadeDificultad() {}
// End Class AFacadeDificultad

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_FacadeDificultad_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFacadeDificultad, AFacadeDificultad::StaticClass, TEXT("AFacadeDificultad"), &Z_Registration_Info_UClass_AFacadeDificultad, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFacadeDificultad), 376512218U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_FacadeDificultad_h_3516176487(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_FacadeDificultad_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_FacadeDificultad_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
