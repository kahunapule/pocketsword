//
//  PSModuleUnlockViewController.h
//  PocketSword
//
//  Created by Nic Carter on 4/01/11.
//  Copyright 2011 CrossWire Bible Society. All rights reserved.
//

#import "globals.h"


@interface PSModuleUnlockViewController : UIViewController <UITextFieldDelegate> {
	
	UIBarButtonItem		*unlockEditButton;
	UIBarButtonItem		*unlockSaveButton;
	UIWebView			*unlockWebView;
	UIWebView			*unlockHelpWebView;
	UITextField			*unlockTextField;
	UIToolbar			*unlockToolbar;
	
	NSString			*moduleName;
}

@property (copy)   NSString			*moduleName;
@property (strong) UIWebView		*unlockHelpWebView;
@property (strong) UITextField		*unlockTextField;
@property (strong) UIWebView		*unlockWebView;
@property (strong) UIToolbar		*unlockToolbar;
@property (strong) UIBarButtonItem	*unlockEditButton;
@property (strong) UIBarButtonItem	*unlockSaveButton;

- (void)unlockEditButtonPressed:(id)sender;

- (void)unlockSaveButtonPressed:(id)sender;
- (void)closeUnlockView:(id)sender;

- (BOOL)textFieldShouldReturn:(UITextField *)textField;
- (void)keyboardWillShow:(NSNotification *)note;
- (void)keyboardWillHide:(NSNotification *)note;

@end
