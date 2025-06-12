// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Nivel_3.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNivel_3() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ANivel_3();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ANivel_3_NoRegister();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_UConfiguracionNivel_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ANivel_3
void ANivel_3::StaticRegisterNativesANivel_3()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANivel_3);
UClass* Z_Construct_UClass_ANivel_3_NoRegister()
{
	return ANivel_3::StaticClass();
}
struct Z_Construct_UClass_ANivel_3_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Nivel_3.h" },
		{ "ModuleRelativePath", "Nivel_3.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANivel_3>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ANivel_3_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANivel_3_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ANivel_3_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UConfiguracionNivel_NoRegister, (int32)VTABLE_OFFSET(ANivel_3, IConfiguracionNivel), false },  // 3311579320
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANivel_3_Statics::ClassParams = {
	&ANivel_3::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANivel_3_Statics::Class_MetaDataParams), Z_Construct_UClass_ANivel_3_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANivel_3()
{
	if (!Z_Registration_Info_UClass_ANivel_3.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANivel_3.OuterSingleton, Z_Construct_UClass_ANivel_3_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANivel_3.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ANivel_3>()
{
	return ANivel_3::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANivel_3);
ANivel_3::~ANivel_3() {}
// End Class ANivel_3

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_3_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANivel_3, ANivel_3::StaticClass, TEXT("ANivel_3"), &Z_Registration_Info_UClass_ANivel_3, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANivel_3), 2883703575U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_3_h_211016910(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_3_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_3_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
