// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "IPrototypeBloque.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BOMBERMAN_012025_IPrototypeBloque_generated_h
#error "IPrototypeBloque.generated.h already included, missing '#pragma once' in IPrototypeBloque.h"
#endif
#define BOMBERMAN_012025_IPrototypeBloque_generated_h

#define FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	BOMBERMAN_012025_API UIPrototypeBloque(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UIPrototypeBloque(UIPrototypeBloque&&); \
	UIPrototypeBloque(const UIPrototypeBloque&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(BOMBERMAN_012025_API, UIPrototypeBloque); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UIPrototypeBloque); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UIPrototypeBloque) \
	BOMBERMAN_012025_API virtual ~UIPrototypeBloque();


#define FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUIPrototypeBloque(); \
	friend struct Z_Construct_UClass_UIPrototypeBloque_Statics; \
public: \
	DECLARE_CLASS(UIPrototypeBloque, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/BomberMan_012025"), BOMBERMAN_012025_API) \
	DECLARE_SERIALIZER(UIPrototypeBloque)


#define FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_13_GENERATED_UINTERFACE_BODY() \
	FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IIPrototypeBloque() {} \
public: \
	typedef UIPrototypeBloque UClassType; \
	typedef IIPrototypeBloque ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_10_PROLOG
#define FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BOMBERMAN_012025_API UClass* StaticClass<class UIPrototypeBloque>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
