// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Teletransportador.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef BOMBERMAN_012025_Teletransportador_generated_h
#error "Teletransportador.generated.h already included, missing '#pragma once' in Teletransportador.h"
#endif
#define BOMBERMAN_012025_Teletransportador_generated_h

#define FID_BomberMan_012025_Source_BomberMan_012025_Teletransportador_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define FID_BomberMan_012025_Source_BomberMan_012025_Teletransportador_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATeletransportador(); \
	friend struct Z_Construct_UClass_ATeletransportador_Statics; \
public: \
	DECLARE_CLASS(ATeletransportador, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BomberMan_012025"), NO_API) \
	DECLARE_SERIALIZER(ATeletransportador)


#define FID_BomberMan_012025_Source_BomberMan_012025_Teletransportador_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ATeletransportador(ATeletransportador&&); \
	ATeletransportador(const ATeletransportador&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATeletransportador); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATeletransportador); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATeletransportador) \
	NO_API virtual ~ATeletransportador();


#define FID_BomberMan_012025_Source_BomberMan_012025_Teletransportador_h_10_PROLOG
#define FID_BomberMan_012025_Source_BomberMan_012025_Teletransportador_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BomberMan_012025_Source_BomberMan_012025_Teletransportador_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_BomberMan_012025_Source_BomberMan_012025_Teletransportador_h_13_INCLASS_NO_PURE_DECLS \
	FID_BomberMan_012025_Source_BomberMan_012025_Teletransportador_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BOMBERMAN_012025_API UClass* StaticClass<class ATeletransportador>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BomberMan_012025_Source_BomberMan_012025_Teletransportador_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
