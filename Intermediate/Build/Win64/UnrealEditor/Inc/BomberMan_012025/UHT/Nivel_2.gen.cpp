// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Nivel_2.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNivel_2() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ANivel_2();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ANivel_2_NoRegister();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_UConfiguracionNivel_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ANivel_2
void ANivel_2::StaticRegisterNativesANivel_2()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANivel_2);
UClass* Z_Construct_UClass_ANivel_2_NoRegister()
{
	return ANivel_2::StaticClass();
}
struct Z_Construct_UClass_ANivel_2_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Nivel_2.h" },
		{ "ModuleRelativePath", "Nivel_2.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANivel_2>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ANivel_2_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANivel_2_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ANivel_2_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UConfiguracionNivel_NoRegister, (int32)VTABLE_OFFSET(ANivel_2, IConfiguracionNivel), false },  // 3311579320
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANivel_2_Statics::ClassParams = {
	&ANivel_2::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANivel_2_Statics::Class_MetaDataParams), Z_Construct_UClass_ANivel_2_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANivel_2()
{
	if (!Z_Registration_Info_UClass_ANivel_2.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANivel_2.OuterSingleton, Z_Construct_UClass_ANivel_2_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANivel_2.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ANivel_2>()
{
	return ANivel_2::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANivel_2);
ANivel_2::~ANivel_2() {}
// End Class ANivel_2

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_2_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANivel_2, ANivel_2::StaticClass, TEXT("ANivel_2"), &Z_Registration_Info_UClass_ANivel_2, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANivel_2), 3755346537U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_2_h_3297130099(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_2_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_2_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
