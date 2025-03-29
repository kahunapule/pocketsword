//
//  PSBibleViewController.h
//  PocketSword
//
//  Created by Nic Carter on 3/11/09.
//  Copyright 2009 The CrossWire Bible Society. All rights reserved.
//

#import "PSModuleViewController.h"

@class PSCommentaryViewController;

@interface PSBibleViewController : PSModuleViewController {

	PSCommentaryViewController	*__weak commentaryView;
}

@property (weak)			PSCommentaryViewController	*commentaryView;

@end
