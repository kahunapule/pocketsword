//
//  SwordListKey.mm
//  MacSword2
//
//  Created by Manfred Bergmann on 10.04.09.
//  Copyright 2009 The CrossWire Bible Society. All rights reserved.
//

#import "SwordListKey.h"
//#import "SwordBible.h"
#import "SwordVerseKey.h"


@interface SwordListKey ()

@end

@implementation SwordListKey

+ (id)listKeyWithRef:(NSString *)aRef {
    return [[SwordListKey alloc] initWithRef:aRef];
}

+ (id)listKeyWithRef:(NSString *)aRef v11n:(NSString *)scheme {
    return [[SwordListKey alloc] initWithRef:aRef v11n:scheme];
}

+ (id)listKeyWithRef:(NSString *)aRef headings:(BOOL)headings v11n:(NSString *)scheme {
    return [[SwordListKey alloc] initWithRef:aRef headings:headings v11n:scheme];
}

+ (id)listKeyWithSWListKey:(sword::ListKey *)aLk {
    return [[SwordListKey alloc] initWithSWListKey:aLk];
}

+ (id)listKeyWithSWListKey:(sword::ListKey *)aLk makeCopy:(BOOL)copy {
    return [[SwordListKey alloc] initWithSWListKey:aLk makeCopy:copy];    
}

- (id)init {
    return [super init];
}

- (id)initWithSWListKey:(sword::ListKey *)aLk {
    return [super initWithSWKey:aLk];
}

- (id)initWithSWListKey:(sword::ListKey *)aLk makeCopy:(BOOL)copy {
    return [super initWithSWKey:aLk makeCopy:copy];
}

- (id)initWithRef:(NSString *)aRef {
    return [self initWithRef:aRef v11n:nil];
}

- (id)initWithRef:(NSString *)aRef v11n:(NSString *)scheme {
    return [self initWithRef:aRef headings:NO v11n:scheme];
}

- (id)initWithRef:(NSString *)aRef headings:(BOOL)headings v11n:(NSString *)scheme {
    sword::VerseKey vk;
	vk.setIntros(headings);
    if(scheme) {
        vk.setVersificationSystem([scheme UTF8String]);
    }
    sword::ListKey listKey = vk.parseVerseList([aRef UTF8String], "Gen1", true);
    sword::ListKey *lk = new sword::ListKey(listKey);
    self = [super initWithSWKey:lk];
	if(self) {
		created = YES;
	}
	return self;
}



- (NSInteger)numberOfVerses {
    NSInteger ret = 0;
    
    if(sk) {
        for(*sk = sword::TOP; !sk->popError(); (void)*sk++) {++ret;};
    }
    
    return ret;
}

- (void)parse {
    
}

- (void)parseWithHeaders {
    
}

- (VerseEnumerator *)verseEnumerator {
    return [[VerseEnumerator alloc] initWithListKey:self];
}

- (NSInteger)count {
	return ((sword::ListKey *)sk)->getCount();
}

- (NSString *)refForElement:(NSInteger)elt {
	return [NSString stringWithUTF8String: ((sword::ListKey *)sk)->getElement((int)elt)->getText()];
}

- (BOOL)containsKey:(SwordVerseKey *)aVerseKey {
    BOOL ret = NO;
    
    if(sk) {
        *sk = [[aVerseKey osisRef] UTF8String];
        ret = !sk->popError();
    }
    
    return ret;
}

- (sword::ListKey *)swListKey {
    return (sword::ListKey *)sk;
}

@end
