// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Nivel_1.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNivel_1() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ANivel_1();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ANivel_1_NoRegister();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_UConfiguracionNivel_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ANivel_1
void ANivel_1::StaticRegisterNativesANivel_1()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANivel_1);
UClass* Z_Construct_UClass_ANivel_1_NoRegister()
{
	return ANivel_1::StaticClass();
}
struct Z_Construct_UClass_ANivel_1_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Nivel_1.h" },
		{ "ModuleRelativePath", "Nivel_1.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANivel_1>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ANivel_1_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANivel_1_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ANivel_1_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UConfiguracionNivel_NoRegister, (int32)VTABLE_OFFSET(ANivel_1, IConfiguracionNivel), false },  // 3311579320
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANivel_1_Statics::ClassParams = {
	&ANivel_1::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANivel_1_Statics::Class_MetaDataParams), Z_Construct_UClass_ANivel_1_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANivel_1()
{
	if (!Z_Registration_Info_UClass_ANivel_1.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANivel_1.OuterSingleton, Z_Construct_UClass_ANivel_1_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANivel_1.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ANivel_1>()
{
	return ANivel_1::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANivel_1);
ANivel_1::~ANivel_1() {}
// End Class ANivel_1

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_1_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANivel_1, ANivel_1::StaticClass, TEXT("ANivel_1"), &Z_Registration_Info_UClass_ANivel_1, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANivel_1), 4260232964U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_1_h_654518261(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_1_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_Nivel_1_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
