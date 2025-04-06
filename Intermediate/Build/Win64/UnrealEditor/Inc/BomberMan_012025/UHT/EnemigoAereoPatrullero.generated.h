// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EnemigoAereoPatrullero.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef BOMBERMAN_012025_EnemigoAereoPatrullero_generated_h
#error "EnemigoAereoPatrullero.generated.h already included, missing '#pragma once' in EnemigoAereoPatrullero.h"
#endif
#define BOMBERMAN_012025_EnemigoAereoPatrullero_generated_h

#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoPatrullero_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnComponentBeginOverlap);


#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoPatrullero_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemigoAereoPatrullero(); \
	friend struct Z_Construct_UClass_AEnemigoAereoPatrullero_Statics; \
public: \
	DECLARE_CLASS(AEnemigoAereoPatrullero, AEnemigo, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BomberMan_012025"), NO_API) \
	DECLARE_SERIALIZER(AEnemigoAereoPatrullero)


#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoPatrullero_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEnemigoAereoPatrullero(AEnemigoAereoPatrullero&&); \
	AEnemigoAereoPatrullero(const AEnemigoAereoPatrullero&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemigoAereoPatrullero); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemigoAereoPatrullero); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemigoAereoPatrullero) \
	NO_API virtual ~AEnemigoAereoPatrullero();


#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoPatrullero_h_12_PROLOG
#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoPatrullero_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoPatrullero_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoPatrullero_h_15_INCLASS_NO_PURE_DECLS \
	FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoPatrullero_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BOMBERMAN_012025_API UClass* StaticClass<class AEnemigoAereoPatrullero>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoPatrullero_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
