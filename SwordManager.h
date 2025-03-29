/*	SwordManager.h - Sword API wrapper for Modules.

    Copyright 2008 Manfred Bergmann
    Based on code by Will Thimbleby

	This program is free software; you can redistribute it and/or modify it under the terms of the
	GNU General Public License as published by the Free Software Foundation version 2.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
	even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
	General Public License for more details. (http://www.gnu.org/licenses/gpl.html)
*/

//#import <Foundation/Foundation.h>

#import "SwordModule.h"

#ifdef __cplusplus
#include <swmgr.h>		// C++ Sword API
#include <localemgr.h>
#include <markupfiltmgr.h>
// Filters
#include <markupfiltmgr.h>
#include <osishtmlhref.h>
#include <thmlhtmlhref.h>
#include <gbfhtmlhref.h>
#include <versekey.h>
//class sword::SWModule;
using sword::SWModule;
#endif


#define SWMOD_CATEGORY_BIBLES			@"Biblical Texts"
#define SWMOD_CATEGORY_COMMENTARIES     @"Commentaries"
#define SWMOD_CATEGORY_DICTIONARIES     @"Lexicons / Dictionaries"
#define SWMOD_CATEGORY_GENBOOKS         @"Generic Books"
#define SWMOD_CATEGORY_DAILYDEVS        @"Daily Devotional"
#define SWMOD_CATEGORY_GLOSSARIES       @"Glossaries"
#define SWMOD_CATEGORY_CULTS            @"Cults / Unorthodox / Questionable Material"
#define SWMOD_CATEGORY_ESSAYS           @"Essays"
#define SWMOD_CATEGORY_MAPS             @"Maps"
#define SWMOD_CATEGORY_IMAGES           @"Images"

/** number of sword module stypes */
#define SWMODTYPE_COUNT                 5

/** config entries */
#define SWMOD_CONFENTRY_VERSION             @"Version"
#define SWMOD_CONFENTRY_MINVERSION          @"MinimumVersion"
#define SWMOD_CONFENTRY_CIPHERKEY           @"CipherKey"
#define SWMOD_CONFENTRY_ABOUT               @"About"
#define SWMOD_CONFENTRY_CATEGORY            @"Category"
#define SWMOD_CONFENTRY_INSTALLSIZE         @"InstallSize"
#define SWMOD_CONFENTRY_COPYRIGHT           @"Copyright"
#define SWMOD_CONFENTRY_COPYRIGHTHOLDER     @"CopyrightHolder"
#define SWMOD_CONFENTRY_DISTRLICENSE        @"DistributionLicense"
#define SWMOD_CONFENTRY_DISTRNOTES          @"DistributionNotes"
#define SWMOD_CONFENTRY_TEXTSOURCE          @"TextSource"
#define SWMOD_CONFENTRY_VERSIFICATION       @"Versification"
#define SWMOD_CONFENTRY_DIRECTION           @"Direction"
#define SWMOD_CONFENTRY_EDITABLE            @"Editable"
#define SWMOD_CONFENTRY_MODDRV				@"ModDrv"

/** module features */
#define SWMOD_FEATURE_STRONGS           @"Strongs"
#define SWMOD_FEATURE_HEADINGS          @"Headings"
#define SWMOD_FEATURE_FOOTNOTES         @"Footnotes"
#define SWMOD_FEATURE_MORPH             @"Morph"
#define SWMOD_FEATURE_CANTILLATION      @"Cantillation"
#define SWMOD_FEATURE_HEBREWPOINTS      @"HebrewPoints"
#define SWMOD_FEATURE_GREEKACCENTS      @"GreekAccents"
#define SWMOD_FEATURE_LEMMA             @"Lemma"
#define SWMOD_FEATURE_SCRIPTREF         @"Scripref"     // not Scriptref
#define SWMOD_FEATURE_VARIANTS          @"Variants"
#define SWMOD_FEATURE_REDLETTERWORDS    @"RedLetterWords"
#define SWMOD_FEATURE_GLOSSES			@"Glosses"

/** global options */
#define SW_OPTION_STRONGS               @"Strong's Numbers"
#define SW_OPTION_HEADINGS              @"Headings"
#define SW_OPTION_FOOTNOTES             @"Footnotes"
#define SW_OPTION_MORPHS                @"Morphological Tags"
#define SW_OPTION_HEBREWCANTILLATION    @"Hebrew Cantillation"
#define SW_OPTION_HEBREWPOINTS          @"Hebrew Vowel Points"
#define SW_OPTION_GREEKACCENTS          @"Greek Accents"
#define SW_OPTION_LEMMAS                @"Lemmas"
#define SW_OPTION_SCRIPTREFS            @"Cross-references"
#define SW_OPTION_VARIANTS              @"Textual Variants" // was "Variants" but that was a MacSword bug....
#define SW_OPTION_REDLETTERWORDS        @"Words of Christ in Red"
#define SW_OPTION_GLOSSES				@"Glosses"
// this is not part of Sword
#define SW_OPTION_REF                   @"Reference"
#define SW_OPTION_MODULENAME            @"ModuleName"

/** config features definitions */
#define SWMOD_CONF_FEATURE_STRONGS       @"StrongsNumbers"
#define SWMOD_CONF_FEATURE_GREEKDEF      @"GreekDef"
#define SWMOD_CONF_FEATURE_HEBREWDEF     @"HebrewDef"
#define SWMOD_CONF_FEATURE_GREEKPARSE    @"GreekParse"
#define SWMOD_CONF_FEATURE_HEBREWPARSE   @"HebrewParse"
#define SWMOD_CONF_FEATURE_DAILYDEVOTION @"DailyDevotion"
#define SWMOD_CONF_FEATURE_GLOSSARY      @"Glossary"
#define SWMOD_CONF_FEATURE_IMAGES        @"Images"
#define SWMOD_CONF_MODDRV				 @"RawFiles"

/** On / Off */
#define SW_ON    @"On"
#define SW_OFF   @"Off"
#define SW_OPTION_VARIANTS_PRIMARY		@"Primary Reading"
#define SW_OPTION_VARIANTS_SECONDARY	@"Secondary Reading"
#define SW_OPTION_VARIANTS_ALL			@"All Readings"

// direction
#define SW_DIRECTION_RTL    @"RtoL"

@interface SwordManager : NSObject {
    
	#ifdef __cplusplus
	sword::SWMgr *swManager;
	//sword::SWFilter *plainFilter, *thmlFilter, *gbfFilter, *osisFilter;
	//sword::SWFilter *thmlStripFilter, *gbfStripFilter, *osisStripFilter;
	#endif

	NSDictionary *modules;
	NSArray *moduleListByType;
    NSString *modulesPath;
	NSRecursiveLock *managerLock;
    BOOL temporaryManager;
	NSArray *moduleTypes;//types that are present in this instance.
}

// ------------------- getter / setter -------------------
@property (strong, readwrite) NSDictionary *modules;
@property (strong, readwrite) NSArray *moduleListByType;
@property (strong, readwrite) NSString *modulesPath;
@property (strong, readwrite) NSRecursiveLock *managerLock;
@property (readwrite) BOOL temporaryManager;
@property (strong) NSArray *moduleTypes;

// --------------------- methods -----------------------

+ (SwordManager *)managerWithPath:(NSString*)path;
+ (SwordManager *)defaultManager;
+ (void)releaseDefaultManager;

//+ (void)initStringManager;
+ (void)initLocale;
+ (NSArray *)moduleTypes;
+ (BOOL)moduleCategoryAllowed:(ModuleCategory)cat;

/** Constructor */
- (id)initWithPath:(NSString *)path;
- (void)addPath:(NSString*)path;

/** reinit the swManager */
- (void)reInit;

/**
 generate a menu structure
 
 @params[in|out] subMenuItem is the start of the menustructure.
 @params[in] type, create menu for module types. ModuleType enum values can be ORed, -1 for all
 @params[in] aTarget the target object of the created menuitem
 @params[in] aSelector the selector of the target that should be called
 */
/*- (void)generateModuleMenu:(NSMenu **)itemMenu
             forModuletype:(int)type 
            withMenuTarget:(id)aTarget 
            withMenuAction:(SEL)aSelector;
*/
- (void)setCipherKey:(NSString*)key forModuleNamed:(NSString *)name;
- (void)setGlobalOption:(NSString*)option value:(NSString *)value;

- (NSArray *)listModules;
- (NSArray *)moduleNames;
- (SwordModule *)moduleWithName:(NSString *)name;
- (BOOL)isModuleInstalled:(NSString *)name;

- (NSArray *)modulesForFeature:(NSString *)feature;
- (NSArray *)modulesForType:(NSString *)type;

- (void)installModulesFromPath:(NSString *)path;

#ifdef __cplusplus
- (id)initWithSWMgr:(sword::SWMgr *)smgr;
- (sword::SWModule *)getSWModuleWithName:(NSString *)moduleName;
- (sword::SWMgr *)swManager;
#endif

@end
